
// SelfBrowserView.h : CSelfBrowserView 类的接口
//


#pragma once


class CSelfBrowserView : public CHtmlView
{
protected: // 仅从序列化创建
	CSelfBrowserView();
	DECLARE_DYNCREATE(CSelfBrowserView)

// 属性
public:
	CSelfBrowserDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CSelfBrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // SelfBrowserView.cpp 中的调试版本
inline CSelfBrowserDoc* CSelfBrowserView::GetDocument() const
   { return reinterpret_cast<CSelfBrowserDoc*>(m_pDocument); }
#endif

