#pragma once


// CHtmlCodeViewDlg �Ի���

class CHtmlCodeViewDlg : public CDialog
{
	DECLARE_DYNAMIC(CHtmlCodeViewDlg)

public:
	CHtmlCodeViewDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHtmlCodeViewDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	// ����ʾ��ҳԴ����ı������ӱ�������
	CString m_htmlCode;
};