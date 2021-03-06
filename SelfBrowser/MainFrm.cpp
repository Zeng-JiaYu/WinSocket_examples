
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "SelfBrowser.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON1, &CMainFrame::OnBnClickedButton1)

	//捕捉回车事件,消息映射
	ON_COMMAND(IDOK,OnInputAddress)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT | TBSTYLE_TRANSPARENT) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}
	if (!m_wndDlgBar.Create(this, IDR_MAINFRAME, CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("未能创建对话栏\n");
		return -1;		// 未能创建
	}

	if (!m_wndReBar.Create(this) || !m_wndReBar.AddBar(&m_wndToolBar) || !m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("未能创建 Rebar\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要工具提示，则将此移除
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sWebAddress;

	//获取编辑框用户输入的web地址
	m_wndDlgBar.GetDlgItem(IDC_EDIT_ADDRESS)->GetWindowText(sWebAddress);
	//浏览相应的网页
	//Navigate是CHtmlView类的常用方法之一，用于获取指定网址的页面，并将其返回给视图
	((CHtmlView *)GetActiveView())->Navigate(sWebAddress);

}

void CMainFrame::OnInputAddress(){

	// TODO: 在此添加控件通知处理程序代码
	CString sWebAddress;

	//获取编辑框用户输入的web地址
	m_wndDlgBar.GetDlgItem(IDC_EDIT_ADDRESS)->GetWindowText(sWebAddress);
	//浏览相应的网页
	//Navigate是CHtmlView类的常用方法之一，用于获取指定网址的页面，并将其返回给视图
	((CHtmlView *)GetActiveView())->Navigate(sWebAddress);

}

//浏览器地址栏同步刷新
void CMainFrame::SetURL(LPCTSTR lpszURL)
{
	m_wndDlgBar.GetDlgItem(IDC_EDIT_ADDRESS)->SetWindowText(lpszURL);
}
