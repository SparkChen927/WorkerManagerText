#pragma once



// ListWorker 窗体视图

class ListWorker : public CFormView
{
	DECLARE_DYNCREATE(ListWorker)

protected:
	ListWorker();           // 动态创建所使用的受保护的构造函数
	virtual ~ListWorker();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ListWorker };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list;
public:
	virtual void OnInitialUpdate();
};


