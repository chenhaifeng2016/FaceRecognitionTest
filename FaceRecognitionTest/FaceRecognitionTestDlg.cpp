
// FaceRecognitionTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FaceRecognitionTest.h"
#include "FaceRecognitionTestDlg.h"
#include "afxdialogex.h"

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
	// TODO: 在此添加控件通知处理程序代码
}


void CFaceRecognitionTestDlg::OnBnClickedButton2()
{

	if (!reader.Init("COM3")) {
		AfxMessageBox("打开端口失败");
		return;
	}
	AfxMessageBox("打开端口成功");

	/*
	hComm = CreateFile("com3", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, 0);
	if (hComm == INVALID_HANDLE_VALUE)
	{
	AfxMessageBox("打开串口失败");
	return;
	}

	SetupComm(hComm, 4096, 4096);

	DCB dcb;
	GetCommState(hComm, &dcb);

	dcb.DCBlength = sizeof(dcb);
	dcb.BaudRate = CBR_115200;
	dcb.StopBits = ONESTOPBIT;
	SetCommState(hComm, &dcb);

	PurgeComm(hComm, PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR | PURGE_TXABORT);//清空缓存

	COMMTIMEOUTS ct;
	ct.ReadIntervalTimeout = 0;
	ct.ReadTotalTimeoutConstant = 5000;
	ct.ReadTotalTimeoutMultiplier = 500;
	ct.WriteTotalTimeoutConstant = 5000;
	ct.WriteTotalTimeoutMultiplier = 500;


	SetCommTimeouts(hComm, &ct);//设置超时

	AfxMessageBox("打开串口成功");
	*/



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


	/*

	DWORD dwToWrite = 8;
	DWORD dwWritten = 0;



	if (WriteFile(hComm, buf, dwToWrite, &dwWritten, NULL))
	{
	TRACE("写成功...\n");

	DWORD dwRead;


	memset(buf, 0x00, sizeof(buf));
	DWORD dwNeedRead = 38 + 5;
	if (ReadFile(hComm, buf, 1, &dwRead, NULL))
	{

	DWORD dwError;
	COMSTAT cs = { 0 };

	ClearCommError(hComm, &dwError, &cs);
	int read_len = cs.cbInQue;

	ReadFile(hComm, buf + 1, dwNeedRead-1, &dwRead, NULL);
	TRACE("读成功...\n");
	}
	else
	{
	TRACE("读失败...\n");
	}
	}
	else
	{
	TRACE("写失败...\n");
	}
	*/


	IDCARD id;
	if (!reader.ReadIDCard(&id)) {
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

	CString msg;
	msg.Format("姓名:%s, 身份证号码:%s", name, idno);
	AfxMessageBox(msg);
}
