#pragma once
#include "Hour.h"
#include "Yuan.h"
#include "SellManager.h"

// Wage 窗体视图

class Wage : public CFormView
{
	DECLARE_DYNCREATE(Wage)
	friend class Hour;
	friend class Yuan;
	friend class SellManager;

protected:
	Wage();           // 动态创建所使用的受保护的构造函数
	virtual ~Wage();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Wage };
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
	afx_msg void OnBnClickedButton2();
private:
	int arr[1024] = { 0 };//初始化数组，记录销售额
	int length = 0;//记录数组长度
	int m_id1;
	int m_hour;
	int m_id2;
	int m_yuan;
	int n_wage = 0;
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton5();
};


