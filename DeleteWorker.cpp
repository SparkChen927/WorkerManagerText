// DeleteWorker.cpp: 实现文件
//

#include "pch.h"
#include "WorkerManager.h"
#include "DeleteWorker.h"


// DeleteWorker

IMPLEMENT_DYNCREATE(DeleteWorker, CFormView)

DeleteWorker::DeleteWorker()
	: CFormView(IDD_DeleteWorker)
	, m_id(0)
	, m_name(_T(""))
{

}

DeleteWorker::~DeleteWorker()
{
}

void DeleteWorker::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT5, m_name);
}

BEGIN_MESSAGE_MAP(DeleteWorker, CFormView)
	ON_BN_CLICKED(IDC_BUTTON6, &DeleteWorker::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &DeleteWorker::OnBnClickedButton1)
END_MESSAGE_MAP()


// DeleteWorker 诊断

#ifdef _DEBUG
void DeleteWorker::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void DeleteWorker::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// DeleteWorker 消息处理程序


void DeleteWorker::OnBnClickedButton6()
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
		ConfirmDelete m;
		m.worker = this;
		m.DoModal();
	}
	else if (num > 1)
	{
		AFewNames s;
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


void DeleteWorker::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	ifstream ifs(FILENAME);//打开文件
	char buf[1024] = { 0 };//初始化数组
	ifs.getline(buf, sizeof(buf));//取出表头
	int num = 0;//记录出现次数，以提示未找到职工

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
			num++;
			break;
		}
	}
	if (num == 1)
	{
		DeleteConfirm m;
		m.worker = this;
		m.DoModal();
	}
	else
	{
		MessageBox(TEXT("未找到该职工"));
	}
	UpdateData(FALSE);
	ifs.close();//关闭文件
	m_id = 0;
}


void DeleteWorker::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	void InitData();//防止修改数据文件中的编号导致错误
}
