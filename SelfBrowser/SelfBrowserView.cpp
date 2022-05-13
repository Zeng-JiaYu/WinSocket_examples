
// SelfBrowserView.cpp : CSelfBrowserView 类的实现
//

#include "stdafx.h"
#include "SelfBrowser.h"

#include "SelfBrowserDoc.h"
#include "SelfBrowserView.h"
#include "MainFrm.h"
#include "HtmlCodeViewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSelfBrowserView

IMPLEMENT_DYNCREATE(CSelfBrowserView, CHtmlView)

BEGIN_MESSAGE_MAP(CSelfBrowserView, CHtmlView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_COMMAND(ID_BACK, &CSelfBrowserView::OnBack)
	ON_COMMAND(ID_FORWARD, &CSelfBrowserView::OnForward)
	ON_COMMAND(ID_HOME, &CSelfBrowserView::OnHome)
	ON_COMMAND(ID_STOP, &CSelfBrowserView::OnStop)
	ON_COMMAND(ID_REFRESH, &CSelfBrowserView::OnRefresh)
	ON_COMMAND(ID_CODE, &CSelfBrowserView::OnCode)
END_MESSAGE_MAP()

// CSelfBrowserView 构造/析构

CSelfBrowserView::CSelfBrowserView()
{
	// TODO: 在此处添加构造代码

}

CSelfBrowserView::~CSelfBrowserView()
{
}

BOOL CSelfBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CHtmlView::PreCreateWindow(cs);
}

void CSelfBrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://www.msdn.microsoft.com/visualc/"),NULL,NULL);
}


// CSelfBrowserView 打印



// CSelfBrowserView 诊断

#ifdef _DEBUG
void CSelfBrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CSelfBrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CSelfBrowserDoc* CSelfBrowserView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSelfBrowserDoc)));
	return (CSelfBrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// CSelfBrowserView 消息处理程序
//后退子菜单事件处理程序
void CSelfBrowserView::OnBack()
{
	// TODO: 在此添加命令处理程序代码
	CSelfBrowserView::GoBack();//后退
}

void CSelfBrowserView::OnForward()
{
	// TODO: 在此添加命令处理程序代码
	CSelfBrowserView::GoForward();//前进
}

void CSelfBrowserView::OnHome()
{
	// TODO: 在此添加命令处理程序代码
	CSelfBrowserView::GoHome();//主页
}

void CSelfBrowserView::OnStop()
{
	// TODO: 在此添加命令处理程序代码
	CSelfBrowserView::Stop();//停止
}


void CSelfBrowserView::OnRefresh()
{
	// TODO: 在此添加命令处理程序代码
	CSelfBrowserView::Refresh();//刷新
}

void CSelfBrowserView::OnDocumentComplete(LPCTSTR lpszURL)
{
	// TODO: 在此添加专用代码和/或调用基类

	// 每次当前页面改变，更新地址栏的内容和窗口的标题
	((CMainFrame *)GetParentFrame())->SetURL(lpszURL);
	GetDocument()->SetTitle(lpszURL);

	CHtmlView::OnDocumentComplete(lpszURL);
}

//查看HTML源文件
void CSelfBrowserView::OnCode()
{
	// TODO: 在此添加命令处理程序代码
	CHtmlCodeViewDlg dlg;
	dlg.DoModal();//生成显示网页HTML源码的对话框
}
