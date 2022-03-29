#pragma once
#include "afxdialogex.h"
#include "ChangeWorker.h"


// ChangeConfirm 对话框

class ChangeConfirm : public CDialogEx
{
	DECLARE_DYNAMIC(ChangeConfirm)
	friend class ChangeWorker;

public:
	ChangeConfirm(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChangeConfirm();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ChangeConfirm };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list;
public:
	virtual BOOL OnInitDialog();
private:
	ChangeWorker* worker;
public:
	afx_msg void OnBnClickedCancel();
private:
	CString c_name;
	CComboBox c_job;
	int c_wage;
public:
	afx_msg void OnBnClickedOk();
};
