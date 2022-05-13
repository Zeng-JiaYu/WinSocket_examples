// HtmlCodeViewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SelfBrowser.h"
#include "HtmlCodeViewDlg.h"
#include "MainFrm.h"
#include "afxinet.h"//�õ�WinInet��

// CHtmlCodeViewDlg �Ի���

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


// CHtmlCodeViewDlg ��Ϣ��������

BOOL CHtmlCodeViewDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	CWaitCursor wait;	                    //�ȴ�
	CInternetSession session("Self Net");   //�½��Ự
	CStdioFile *pFile=NULL;	               
	CString sWebAddress;
	//�ӵ�ַ����ȡURL
	(((CMainFrame *)GetParentFrame())->m_wndDlgBar).GetDlgItem(IDC_EDIT_ADDRESS)->GetWindowTextA(sWebAddress);
	pFile = session.OpenURL(sWebAddress);	//��URL
	if(pFile != NULL)
	{
		CString str,allText,crlf="\r\n";	//�س�����
		while(pFile->ReadString(str))	    //����ҳ������
		{
			allText+=crlf + str;	
		}
		this->m_htmlCode = allText;
		UpdateData(false);                  //�ڶԻ�������ʾ��ҳԴ��

		pFile->Close();		                //�ر��ļ�
	}
	session.Close();	                    //�رջỰ
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}