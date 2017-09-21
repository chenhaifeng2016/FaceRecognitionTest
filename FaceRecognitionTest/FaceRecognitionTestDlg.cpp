
// FaceRecognitionTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FaceRecognitionTest.h"
#include "FaceRecognitionTestDlg.h"
#include "afxdialogex.h"


//身份证
#include "../IDCardReader/include/IDCardReader.h"
#include "third_party\wtl\WltRS.h"

//人脸识别服务
#include "../FaceRecognitionDLL/include/FaceRecognition.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFaceRecognitionTestDlg 对话框



CFaceRecognitionTestDlg::CFaceRecognitionTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FACERECOGNITIONTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFaceRecognitionTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ID_IMAGE, m_image);
}

BEGIN_MESSAGE_MAP(CFaceRecognitionTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CFaceRecognitionTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFaceRecognitionTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CFaceRecognitionTestDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CFaceRecognitionTestDlg 消息处理程序

BOOL CFaceRecognitionTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFaceRecognitionTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFaceRecognitionTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFaceRecognitionTestDlg::OnBnClickedButton1()
{
	int confidence = 0;
	int ret = 0;

	ret = FaceRecognition("E:\\FaceRecognition\\FaceRecognitionTest\\test_images\\id.bmp", "E:\\FaceRecognition\\FaceRecognitionTest\\test_images\\camera.jpg", &confidence);

	TRACE("confidence = %d\n", confidence);
}


void CFaceRecognitionTestDlg::OnBnClickedButton2()
{

	

	

	/*

	char data[256] = { 0 };
	int data_len = 0;

	if (!reader.ReadIDNo(data, &data_len))
	{
		AfxMessageBox("读身份证号码失败");
		return;
	}

	int len = WideCharToMultiByte(CP_ACP, 0, (LPCWCH)data, -1, NULL, 0, NULL, NULL);
	char * buf = new char[len];
	WideCharToMultiByte(CP_ACP, 0, (LPCWCH)data, -1, buf, len, NULL, NULL);

	CString msg;
	msg.Format("读身份证号码成功 %s", buf);
	AfxMessageBox(msg);
	*/

	


	IDCARD id;
	if (!ReadIDCard("com3", &id)) {
		AfxMessageBox("读身份证全信息失败");
		return;
	}
	/*
	int len = WideCharToMultiByte(CP_ACP, 0, (LPCWCH)id.name, 30, NULL, 0, NULL, NULL);
	char * name = new char[len];
	WideCharToMultiByte(CP_ACP, 0, (LPCWCH)id.name, 30, name, len, NULL, NULL);
	*/	
	char name[100] = { 0 };
	WideCharToMultiByte(CP_ACP, 0, (LPCWCH)id.name, sizeof(id.name), name, sizeof(id.name) / 2, NULL, NULL);

	char idno[100] = { 0 };
	WideCharToMultiByte(CP_ACP, 0, (LPCWCH)id.idno, sizeof(id.idno), idno, sizeof(id.idno) / 2, NULL, NULL);

	//保存图像

	FILE * f = NULL;
	if ((f = fopen("e:\\id.wlt", "wb")) == NULL) {
		return;

	}
	fwrite(id.image, 1024, 1, f);
	fclose(f);

	//转换图像
	/*
	1	相片解码解码正确
	0	调用sdtapi.dll错误
	-1	相片解码错误
	-2	wlt文件后缀错误
	-3	wlt文件打开错误
	-4	wlt文件格式错误
	-5	软件未授权
	-6	设备连接错误
	*/
	int rc = GetBmp("e:\\id.wlt", 0);
	if (rc != 1) {
		TRACE("GetBmp fail \n");
	}


	//显示图像
	HBITMAP m_hBitmap;
	m_hBitmap = (HBITMAP)::LoadImage(NULL, "e:\\id.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);

	m_image.SetBitmap(m_hBitmap);

	//CString msg;
	//msg.Format("姓名:%s, 身份证号码:%s", name, idno);
	//AfxMessageBox(msg);
}


void CFaceRecognitionTestDlg::OnBnClickedButton3()
{
	/*
	char pIn[10] = { 0 };
	char pOut[100] = { 0 };

	CAM_Open(pIn, pOut);
	*/
	/*
	Capture = cvCreateCameraCapture(0);
	if (Capture == 0)
	{
		MessageBox(_T("无法连接摄像头！！！"));
		return;
	}
	frame = cvQueryFrame(Capture); //从摄像头或者文件中抓取并返回一帧  
	CDC * pDC = GetDlgItem(IDC_CAMERA_IMAGE)->GetDC();//GetDlgItem(IDC_PIC_STATIC)意思为获取显示控件的句柄（句柄就是指针），获取显示控件的DC  
	CRect rect;
	GetDlgItem(IDC_CAMERA_IMAGE)->GetClientRect(&rect);
	HDC hDC = pDC->GetSafeHdc();//获取显示控件的句柄  

	CvvImage m_CvvImage;
	m_CvvImage.CopyOf(frame, 1); //复制该帧图像     
	m_CvvImage.DrawToHDC(hDC, &rect); //显示到设备的矩形框内  
	ReleaseDC(pDC);
	*/

}
