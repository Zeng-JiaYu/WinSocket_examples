
// SelfBrowser.h : SelfBrowser Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSelfBrowserApp:
// �йش����ʵ�֣������ SelfBrowser.cpp
//

class CSelfBrowserApp : public CWinApp
{
public:
	CSelfBrowserApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSelfBrowserApp theApp;