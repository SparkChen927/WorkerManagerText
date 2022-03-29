// ChangeWorker.cpp: 实现文件
//

#include "pch.h"
#include "WorkerManager.h"
#include "ChangeWorker.h"
#include "ChangeConfirm.h"
#include "FindWorker.h"


// ChangeWorker

IMPLEMENT_DYNCREATE(ChangeWorker, CFormView)

ChangeWorker::ChangeWorker()
	: CFormView(IDD_ChangeWorker)
	, m_id(0)
	, m_name(_T(""))
{

}

ChangeWorker::~ChangeWorker()
{
}

void ChangeWorker::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT5, m_name);
}

BEGIN_MESSAGE_MAP(ChangeWorker, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &ChangeWorker::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &ChangeWorker::OnBnClickedButton6)
END_MESSAGE_MAP()


// ChangeWorker 诊断

#ifdef _DEBUG
void ChangeWorker::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void ChangeWorker::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// ChangeWorker 消息处理程序


void ChangeWorker::OnBnClickedButton1()
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

		if (tmp.id == m_id)
		{
			ChangeConfirm m;
			m.worker = this;
			m.DoModal();
			break;
		}
	}
	WorkerManager file;
	file.Read();
	if (m_id > file.sum - 1)
	{
		MessageBox(TEXT("未找到该职工"));
	}
	UpdateData(FALSE);
	ifs.close();//关闭文件
	m_id = 0;
}


void ChangeWorker::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	ifstream ifs(FILENAME);//打开文件
	char buf[1024] = { 0 };//初始化数组
	ifs.getline(buf, sizeof(buf));//取出表头
	int num = 0;//记录同名职工数量

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

		CStringA str;
		str = m_name;
		if (tmp.name == str.GetBuffer())
		{
			num++;
		}
	}
	if (num == 1)
	{
		ConfirmChange m;
		m.worker = this;
		m.DoModal();
	}
	else if (num > 1)
	{
		SomeName s;
		s.worker = this;
		s.DoModal();
	}
	else
	{
		MessageBox(TEXT("未找到该职工"));
	}
	UpdateData(FALSE);
	ifs.close();//关闭文件
	m_name.Empty();
}


void ChangeWorker::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	void InitData();//防止修改数据文件中的编号导致错误
}
