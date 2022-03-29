#pragma once
#include "ChangeConfirm.h"
#include "ConfirmChange.h"
#include "SomeName.h"


// ChangeWorker 窗体视图

class ChangeWorker : public CFormView
{
	DECLARE_DYNCREATE(ChangeWorker)
	friend class ChangeConfirm;
	friend class ConfirmChange;
	friend class SomeName;

protected:
	ChangeWorker();           // 动态创建所使用的受保护的构造函数
	virtual ~ChangeWorker();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ChangeWorker };
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
public:
	afx_msg void OnBnClickedButton1();
private:
	int m_id;
	CString m_name;
public:
	afx_msg void OnBnClickedButton6();
	virtual void OnInitialUpdate();
};


