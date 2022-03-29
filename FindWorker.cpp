// FindWorker.cpp: 实现文件
//

#include "pch.h"
#include "WorkerManager.h"
#include "FindWorker.h"


// FindWorker

IMPLEMENT_DYNCREATE(FindWorker, CFormView)

FindWorker::FindWorker()
	: CFormView(IDD_FindWorker)
	, m_id(0)
	, m_name(_T(""))
{

}

FindWorker::~FindWorker()
{
}

void FindWorker::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT2, m_name);
}

BEGIN_MESSAGE_MAP(FindWorker, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &FindWorker::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &FindWorker::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &FindWorker::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &FindWorker::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &FindWorker::OnBnClickedButton5)
END_MESSAGE_MAP()


// FindWorker 诊断

#ifdef _DEBUG
void FindWorker::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FindWorker::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FindWorker 消息处理程序



void FindWorker::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_id = 0;
	UpdateData(FALSE);
}


void FindWorker::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_name.Empty();
	UpdateData(FALSE);
}


void FindWorker::OnBnClickedButton2()//按编号查找
{
	UpdateData(TRUE);
	ifstream ifs(FILENAME);//打开文件
	char buf[1024] = { 0 };//初始化数组
	ifs.getline(buf, sizeof(buf));//取出表头

	while (!ifs.eof())//未读取完毕
	{
		msg tmp;

		ifs.getline(buf, sizeof(buf));//读取一行

		char* sst = strtok(buf, "|");//用“|”分隔
		if (sst != NULL)
		{
			tmp.id = atoi(sst);//职工编号
		}
		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		tmp.name = sst;//职工姓名

		sst = strtok(NULL, "|");
		tmp.job = sst;//职工职位

		sst = strtok(NULL, "|");
		tmp.wage = atoi(sst);//职工薪水

		if (tmp.id == m_id)
		{
			CString str1, str2, str3, str4;
			str1.Format(_T("%d"), tmp.id);
			m_list.InsertItem(0, str1);
			int column = 1;
			m_list.SetItemText(0, column++, (CString)tmp.name.c_str());
			m_list.SetItemText(0, column++, (CString)tmp.job.c_str());
			str4.Format(_T("%d"), tmp.wage);
			m_list.SetItemText(0, column++, str4);
			break;
		}
	}
	ifs.close();//关闭文件
	WorkerManager file;
	file.Read();
	if (m_id > file.sum - 1)
	{
		MessageBox(TEXT("未找到该职工"));
	}
	UpdateData(FALSE);
	m_id = 0;
}


void FindWorker::OnInitialUpdate()
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
}


void FindWorker::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	ifstream ifs(FILENAME);//打开文件
	char buf[1024] = { 0 };//初始化数组
	ifs.getline(buf, sizeof(buf));//取出表头

	while (!ifs.eof())//未读取完毕
	{
		msg tmp;

		ifs.getline(buf, sizeof(buf));//读取一行

		char* sst = strtok(buf, "|");//用“|”分隔
		if (sst != NULL)
		{
			tmp.id = atoi(sst);//职工编号
		}
		else
		{
			break;
		}

		sst = strtok(NULL, "|");
		tmp.name = sst;//职工姓名

		sst = strtok(NULL, "|");
		tmp.job = sst;//职工职位

		sst = strtok(NULL, "|");
		tmp.wage = atoi(sst);//职工薪水

		string str = CT2A(m_name.GetBuffer());//将CString类型转化为string类型

		if (tmp.name == str)//输出到列表
		{
			CString str1, str2, str3, str4;
			str1.Format(_T("%d"), tmp.id);
			m_list.InsertItem(0, str1);
			int column = 1;
			m_list.SetItemText(0, column++, (CString)tmp.name.c_str());
			m_list.SetItemText(0, column++, (CString)tmp.job.c_str());
			str4.Format(_T("%d"), tmp.wage);
			m_list.SetItemText(0, column++, str4);
		}
	}
	ifs.close();//关闭文件
	FindWorker find;
	if (find.FindName(m_name))
	{
		MessageBox(TEXT("未找到该职工"));
	}
	UpdateData(FALSE);
	m_name.Empty();
}



void FindWorker::OnBnClickedButton5()//清空
{
	// TODO: 在此添加控件通知处理程序代码
	m_list.DeleteAllItems();//删除所有内容
}
