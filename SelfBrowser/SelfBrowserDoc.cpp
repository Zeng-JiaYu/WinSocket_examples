
// SelfBrowserDoc.cpp : CSelfBrowserDoc ���ʵ��
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


// CSelfBrowserDoc ����/����

CSelfBrowserDoc::CSelfBrowserDoc()
{
	// TODO: �ڴ�����һ���Թ������

}

CSelfBrowserDoc::~CSelfBrowserDoc()
{
}

BOOL CSelfBrowserDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ��������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CSelfBrowserDoc ���л�

void CSelfBrowserDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ����Ӵ洢����
	}
	else
	{
		// TODO: �ڴ����Ӽ��ش���
	}
}


// CSelfBrowserDoc ���

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


// CSelfBrowserDoc ����