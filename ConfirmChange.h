#pragma once
#include "afxdialogex.h"
#include "ChangeWorker.h"


// ConfirmChange 对话框

class ConfirmChange : public CDialogEx
{
	DECLARE_DYNAMIC(ConfirmChange)
	friend class ChangeWorker;

public:
	ConfirmChange(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ConfirmChange();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ConfirmChange };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list;
	CString c_name;
	CComboBox c_job;
	int c_wage;

	ChangeWorker* worker;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
