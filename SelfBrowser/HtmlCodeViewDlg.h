#pragma once


// CHtmlCodeViewDlg 对话框

class CHtmlCodeViewDlg : public CDialog
{
	DECLARE_DYNAMIC(CHtmlCodeViewDlg)

public:
	CHtmlCodeViewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHtmlCodeViewDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	// 给显示网页源码的文本框添加变量关联
	CString m_htmlCode;
};
