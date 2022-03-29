#pragma once



// AddWorker 窗体视图

class AddWorker : public CFormView
{
	DECLARE_DYNCREATE(AddWorker)

protected:
	AddWorker();           // 动态创建所使用的受保护的构造函数
	virtual ~AddWorker();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AddWorker };
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
private:
	int m_id;
	CString m_name;
	CComboBox m_job;
	int m_wage;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit4();
	virtual void OnInitialUpdate();
};


