
// FaceRecognitionTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FaceRecognitionTest.h"
#include "FaceRecognitionTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFaceRecognitionTestDlg �Ի���



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


// CFaceRecognitionTestDlg ��Ϣ�������

BOOL CFaceRecognitionTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFaceRecognitionTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFaceRecognitionTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFaceRecognitionTestDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CFaceRecognitionTestDlg::OnBnClickedButton2()
{

	if (!reader.Init("COM3")) {
		AfxMessageBox("�򿪶˿�ʧ��");
		return;
	}
	AfxMessageBox("�򿪶˿ڳɹ�");

	/*
	hComm = CreateFile("com3", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, 0);
	if (hComm == INVALID_HANDLE_VALUE)
	{
	AfxMessageBox("�򿪴���ʧ��");
	return;
	}

	SetupComm(hComm, 4096, 4096);

	DCB dcb;
	GetCommState(hComm, &dcb);

	dcb.DCBlength = sizeof(dcb);
	dcb.BaudRate = CBR_115200;
	dcb.StopBits = ONESTOPBIT;
	SetCommState(hComm, &dcb);

	PurgeComm(hComm, PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR | PURGE_TXABORT);//��ջ���

	COMMTIMEOUTS ct;
	ct.ReadIntervalTimeout = 0;
	ct.ReadTotalTimeoutConstant = 5000;
	ct.ReadTotalTimeoutMultiplier = 500;
	ct.WriteTotalTimeoutConstant = 5000;
	ct.WriteTotalTimeoutMultiplier = 500;


	SetCommTimeouts(hComm, &ct);//���ó�ʱ

	AfxMessageBox("�򿪴��ڳɹ�");
	*/



	char data[256] = { 0 };
	int data_len = 0;

	if (!reader.ReadIDNo(data, &data_len))
	{
		AfxMessageBox("�����֤����ʧ��");
		return;
	}

	int len = WideCharToMultiByte(CP_ACP, 0, (LPCWCH)data, -1, NULL, 0, NULL, NULL);
	char * buf = new char[len];
	WideCharToMultiByte(CP_ACP, 0, (LPCWCH)data, -1, buf, len, NULL, NULL);

	CString msg;
	msg.Format("�����֤����ɹ� %s", buf);
	AfxMessageBox(msg);


	/*

	DWORD dwToWrite = 8;
	DWORD dwWritten = 0;



	if (WriteFile(hComm, buf, dwToWrite, &dwWritten, NULL))
	{
	TRACE("д�ɹ�...\n");

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
	TRACE("���ɹ�...\n");
	}
	else
	{
	TRACE("��ʧ��...\n");
	}
	}
	else
	{
	TRACE("дʧ��...\n");
	}
	*/


	IDCARD id;
	if (!reader.ReadIDCard(&id)) {
		AfxMessageBox("�����֤ȫ��Ϣʧ��");
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

	//����ͼ��

	FILE * f = NULL;
	if ((f = fopen("e:\\id.wlt", "wb")) == NULL) {
		return;

	}
	fwrite(id.image, 1024, 1, f);
	fclose(f);

	//ת��ͼ��
	/*
	1	��Ƭ���������ȷ
	0	����sdtapi.dll����
	-1	��Ƭ�������
	-2	wlt�ļ���׺����
	-3	wlt�ļ��򿪴���
	-4	wlt�ļ���ʽ����
	-5	���δ��Ȩ
	-6	�豸���Ӵ���
	*/
	int rc = GetBmp("e:\\id.wlt", 0);
	if (rc != 1) {
		TRACE("GetBmp fail \n");
	}


	//��ʾͼ��
	HBITMAP m_hBitmap;
	m_hBitmap = (HBITMAP)::LoadImage(NULL, "e:\\id.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);

	m_image.SetBitmap(m_hBitmap);

	CString msg;
	msg.Format("����:%s, ���֤����:%s", name, idno);
	AfxMessageBox(msg);
}
