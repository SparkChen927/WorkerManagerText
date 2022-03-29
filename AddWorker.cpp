// AddWorker.cpp: 实现文件
//

#include "pch.h"
#include "WorkerManager.h"
#include "AddWorker.h"


// AddWorker

IMPLEMENT_DYNCREATE(AddWorker, CFormView)

AddWorker::AddWorker()
	: CFormView(IDD_AddWorker)
	, m_wage(0)
	, m_name(_T(""))
{

}

AddWorker::~AddWorker()
{
}

void AddWorker::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_job);
	DDX_Text(pDX, IDC_EDIT4, m_wage);
	DDX_Text(pDX, IDC_EDIT1, m_name);
}

BEGIN_MESSAGE_MAP(AddWorker, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &AddWorker::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &AddWorker::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT4, &AddWorker::OnEnChangeEdit4)
END_MESSAGE_MAP()


// AddWorker 诊断

#ifdef _DEBUG
void AddWorker::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void AddWorker::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// AddWorker 消息处理程序



void AddWorker::OnBnClickedButton1()
{
	//拿到最新的数据
	UpdateData(TRUE);

	// TODO: 在此添加控件通知处理程序代码

	//验证数据的有效性
	if (m_name.IsEmpty())
	{
		MessageBox(TEXT("输入信息有误"));
		return;
	}

	WorkerManager file;
	file.Read();
	//获取职位名称
	int index = m_job.GetCurSel();
	//根据索引获取到具体内容
	CString job;
	m_job.GetLBText(index, job);
	file.Add(m_name, job, m_wage);
	file.Write();
	MessageBox(TEXT("添加职工成功"));

	//清空添加的新数据
	m_name.Empty();
	m_job.Clear();
	m_wage = 0;
	UpdateData(FALSE);
}

void AddWorker::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_name.Empty();
	m_job.Clear();
	m_wage = 0;
	UpdateData(FALSE);
}


void AddWorker::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void AddWorker::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	void InitData();//防止修改数据文件中的编号导致错误
}
