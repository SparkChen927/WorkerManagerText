// ListWorker.cpp: 实现文件
//

#include "pch.h"
#include "WorkerManager.h"
#include "ListWorker.h"


// ListWorker

IMPLEMENT_DYNCREATE(ListWorker, CFormView)

ListWorker::ListWorker()
	: CFormView(IDD_ListWorker)
{

}

ListWorker::~ListWorker()
{
}

void ListWorker::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(ListWorker, CFormView)
END_MESSAGE_MAP()


// ListWorker 诊断

#ifdef _DEBUG
void ListWorker::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void ListWorker::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// ListWorker 消息处理程序


void ListWorker::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	void InitData();//防止修改数据文件中的编号导致错误

	// 设置扩展风格
	//LVS_EX_FULLROWSELECT选中整行，LVS_EX_GRIDLINES网格
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 初始化表头
	CString field[] = { _T("职工编号"), _T("职工姓名"), _T("职工级别"), _T("职工薪水") };
	for (int i = 0; i < sizeof(field) / sizeof(field[0]); ++i)
	{
		m_list.InsertColumn(i, field[i], LVCFMT_CENTER, 105);
	}

	WorkerManager file;
	file.Read(); //读取商品信息

	//添加数据
	int i = 0;
	CString str1;
	CString str2;
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		str1.Format(_T("%d"), it->id);
		m_list.InsertItem(i, str1);
		int column = 1;
		m_list.SetItemText(i, column++, (CString)it->name.c_str());
		m_list.SetItemText(i, column++, (CString)it->job.c_str());
		str2.Format(_T("%d"), it->wage);
		m_list.SetItemText(i, column++, str2);
		str1.Format(_T("%d"), it->sum);
		i++;
	}

}
