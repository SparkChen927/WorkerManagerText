#pragma once
#include "afxdialogex.h"
#include "DeleteWorker.h"


// DeleteConfirm 对话框

class DeleteConfirm : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteConfirm)
	friend class DeleteWorker;

public:
	DeleteConfirm(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DeleteConfirm();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DeleteConfirm };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list;
	DeleteWorker* worker;
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
