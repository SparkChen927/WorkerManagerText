#pragma once
#include "afxdialogex.h"
#include "Wage.h"

// Hour 对话框

class Hour : public CDialogEx
{
	DECLARE_DYNAMIC(Hour)
	friend class Wage;

public:
	Hour(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Hour();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Hour };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list1;
	CListCtrl m_list2;
	Wage* wage;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
