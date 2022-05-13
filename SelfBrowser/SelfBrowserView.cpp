
// SelfBrowserView.cpp : CSelfBrowserView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_COMMAND(ID_BACK, &CSelfBrowserView::OnBack)
	ON_COMMAND(ID_FORWARD, &CSelfBrowserView::OnForward)
	ON_COMMAND(ID_HOME, &CSelfBrowserView::OnHome)
	ON_COMMAND(ID_STOP, &CSelfBrowserView::OnStop)
	ON_COMMAND(ID_REFRESH, &CSelfBrowserView::OnRefresh)
	ON_COMMAND(ID_CODE, &CSelfBrowserView::OnCode)
END_MESSAGE_MAP()

// CSelfBrowserView ����/����

CSelfBrowserView::CSelfBrowserView()
{
	// TODO: �ڴ˴����ӹ������

}

CSelfBrowserView::~CSelfBrowserView()
{
}

BOOL CSelfBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CHtmlView::PreCreateWindow(cs);
}

void CSelfBrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://www.msdn.microsoft.com/visualc/"),NULL,NULL);
}


// CSelfBrowserView ��ӡ



// CSelfBrowserView ���

#ifdef _DEBUG
void CSelfBrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CSelfBrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CSelfBrowserDoc* CSelfBrowserView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSelfBrowserDoc)));
	return (CSelfBrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// CSelfBrowserView ��Ϣ��������
//�����Ӳ˵��¼���������
void CSelfBrowserView::OnBack()
{
	// TODO: �ڴ�����������������
	CSelfBrowserView::GoBack();//����
}

void CSelfBrowserView::OnForward()
{
	// TODO: �ڴ�����������������
	CSelfBrowserView::GoForward();//ǰ��
}

void CSelfBrowserView::OnHome()
{
	// TODO: �ڴ�����������������
	CSelfBrowserView::GoHome();//��ҳ
}

void CSelfBrowserView::OnStop()
{
	// TODO: �ڴ�����������������
	CSelfBrowserView::Stop();//ֹͣ
}


void CSelfBrowserView::OnRefresh()
{
	// TODO: �ڴ�����������������
	CSelfBrowserView::Refresh();//ˢ��
}

void CSelfBrowserView::OnDocumentComplete(LPCTSTR lpszURL)
{
	// TODO: �ڴ�����ר�ô����/����û���

	// ÿ�ε�ǰҳ��ı䣬���µ�ַ�������ݺʹ��ڵı���
	((CMainFrame *)GetParentFrame())->SetURL(lpszURL);
	GetDocument()->SetTitle(lpszURL);

	CHtmlView::OnDocumentComplete(lpszURL);
}

//�鿴HTMLԴ�ļ�
void CSelfBrowserView::OnCode()
{
	// TODO: �ڴ�����������������
	CHtmlCodeViewDlg dlg;
	dlg.DoModal();//������ʾ��ҳHTMLԴ��ĶԻ���
}