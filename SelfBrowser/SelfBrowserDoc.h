
// SelfBrowserDoc.h : CSelfBrowserDoc ��Ľӿ�
//


#pragma once


class CSelfBrowserDoc : public CDocument
{
protected: // �������л�����
	CSelfBrowserDoc();
	DECLARE_DYNCREATE(CSelfBrowserDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CSelfBrowserDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

