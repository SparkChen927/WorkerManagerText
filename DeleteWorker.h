#pragma once
#include "AFewNames.h"
#include "ConfirmDelete.h"
#include "DeleteConfirm.h"


// DeleteWorker 窗体视图

class DeleteWorker : public CFormView
{
	DECLARE_DYNCREATE(DeleteWorker)
	friend class AFewNames;
	friend class ConfirmDelete;
	friend class DeleteConfirm;

protected:
	DeleteWorker();           // 动态创建所使用的受保护的构造函数
	virtual ~DeleteWorker();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DeleteWorker };
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
	int m_id;
	CString m_name;
public:
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton1();
	virtual void OnInitialUpdate();
};


