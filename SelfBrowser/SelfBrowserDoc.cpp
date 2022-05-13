
// SelfBrowserDoc.cpp : CSelfBrowserDoc 类的实现
//

#include "stdafx.h"
#include "SelfBrowser.h"

#include "SelfBrowserDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSelfBrowserDoc

IMPLEMENT_DYNCREATE(CSelfBrowserDoc, CDocument)

BEGIN_MESSAGE_MAP(CSelfBrowserDoc, CDocument)
END_MESSAGE_MAP()


// CSelfBrowserDoc 构造/析构

CSelfBrowserDoc::CSelfBrowserDoc()
{
	// TODO: 在此添加一次性构造代码

}

CSelfBrowserDoc::~CSelfBrowserDoc()
{
}

BOOL CSelfBrowserDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CSelfBrowserDoc 序列化

void CSelfBrowserDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CSelfBrowserDoc 诊断

#ifdef _DEBUG
void CSelfBrowserDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSelfBrowserDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSelfBrowserDoc 命令
