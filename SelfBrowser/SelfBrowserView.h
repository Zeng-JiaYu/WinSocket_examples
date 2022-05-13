
// SelfBrowserView.h : CSelfBrowserView ��Ľӿ�
//


#pragma once


class CSelfBrowserView : public CHtmlView
{
protected: // �������л�����
	CSelfBrowserView();
	DECLARE_DYNCREATE(CSelfBrowserView)

// ����
public:
	CSelfBrowserDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CSelfBrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBack();
	afx_msg void OnForward();
	afx_msg void OnHome();
	afx_msg void OnStop();
	afx_msg void OnRefresh();
	virtual void OnDocumentComplete(LPCTSTR lpszURL);
	afx_msg void OnCode();
};

#ifndef _DEBUG  // SelfBrowserView.cpp �еĵ��԰汾
inline CSelfBrowserDoc* CSelfBrowserView::GetDocument() const
   { return reinterpret_cast<CSelfBrowserDoc*>(m_pDocument); }
#endif
