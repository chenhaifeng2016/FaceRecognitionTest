
// FaceRecognitionTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFaceRecognitionTestApp: 
// �йش����ʵ�֣������ FaceRecognitionTest.cpp
//

class CFaceRecognitionTestApp : public CWinApp
{
public:
	CFaceRecognitionTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFaceRecognitionTestApp theApp;