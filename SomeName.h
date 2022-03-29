#pragma once
#include "afxdialogex.h"
#include "ChangeWorker.h"


// SomeName 对话框

class SomeName : public CDialogEx
{
	DECLARE_DYNAMIC(SomeName)
	friend class ChangeWorker;

public:
	SomeName(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SomeName();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SomeNames };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list;
	ChangeWorker* worker;
public:
	virtual BOOL OnInitDialog();
};
