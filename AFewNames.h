#pragma once
#include "afxdialogex.h"
#include "DeleteWorker.h"

// AFewNames 对话框

class AFewNames : public CDialogEx
{
	DECLARE_DYNAMIC(AFewNames)
	friend class DeleteWorker;

public:
	AFewNames(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AFewNames();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AFewNames };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list;
	DeleteWorker* worker;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk2();
};
