#pragma once
#include "afxdialogex.h"
#include "Wage.h"

// Yuan 对话框

class Yuan : public CDialogEx
{
	DECLARE_DYNAMIC(Yuan)
	friend class Wage;

public:
	Yuan(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Yuan();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Yuan };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list1;
	CListCtrl m_list2;
public:
	afx_msg void OnBnClickedOk();
private:
	Wage* wage;
public:
	virtual BOOL OnInitDialog();
};
