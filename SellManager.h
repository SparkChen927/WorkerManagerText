#pragma once
#include "afxdialogex.h"
#include "Wage.h"

// SellManager 对话框

class SellManager : public CDialogEx
{
	DECLARE_DYNAMIC(SellManager)
	friend class Wage;

public:
	SellManager(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SellManager();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SellManager };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list1;
	CListCtrl m_list2;
	Wage* wage;
//	virtual void PreInitDialog();
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
