// HtmlCodeViewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SelfBrowser.h"
#include "HtmlCodeViewDlg.h"
#include "MainFrm.h"
#include "afxinet.h"//用到WinInet类

// CHtmlCodeViewDlg 对话框

IMPLEMENT_DYNAMIC(CHtmlCodeViewDlg, CDialog)

CHtmlCodeViewDlg::CHtmlCodeViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHtmlCodeViewDlg::IDD, pParent)
	, m_htmlCode(_T(""))
{

}

CHtmlCodeViewDlg::~CHtmlCodeViewDlg()
{
}

void CHtmlCodeViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_htmlCode);
}


BEGIN_MESSAGE_MAP(CHtmlCodeViewDlg, CDialog)
END_MESSAGE_MAP()


// CHtmlCodeViewDlg 消息处理程序

BOOL CHtmlCodeViewDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CWaitCursor wait;	                    //等待
	CInternetSession session("Self Net");   //新建会话
	CStdioFile *pFile=NULL;	               
	CString sWebAddress;
	//从地址栏获取URL
	(((CMainFrame *)GetParentFrame())->m_wndDlgBar).GetDlgItem(IDC_EDIT_ADDRESS)->GetWindowTextA(sWebAddress);
	pFile = session.OpenURL(sWebAddress);	//打开URL
	if(pFile != NULL)
	{
		CString str,allText,crlf="\r\n";	//回车换行
		while(pFile->ReadString(str))	    //读入页面内容
		{
			allText+=crlf + str;	
		}
		this->m_htmlCode = allText;
		UpdateData(false);                  //在对话框中显示网页源码

		pFile->Close();		                //关闭文件
	}
	session.Close();	                    //关闭会话
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
