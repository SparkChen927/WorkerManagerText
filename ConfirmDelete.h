#pragma once
#include "afxdialogex.h"
#include "DeleteWorker.h"

// ConfirmDelete 对话框

class ConfirmDelete : public CDialogEx
{
	DECLARE_DYNAMIC(ConfirmDelete)
	friend class DeleteWorker;

public:
	ConfirmDelete(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ConfirmDelete();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ConfirmDelete };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list;
	DeleteWorker* worker;
//	virtual void PreInitDialog();
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
