// Wage.cpp: 实现文件
//

#include "pch.h"
#include "WorkerManager.h"
#include "Wage.h"


// Wage

IMPLEMENT_DYNCREATE(Wage, CFormView)

Wage::Wage()
	: CFormView(IDD_Wage)
	, m_id1(0)
	, m_hour(0)
	, m_id2(0)
	, m_yuan(0)
{

}

Wage::~Wage()
{
}

void Wage::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_id1);
	DDX_Text(pDX, IDC_EDIT2, m_hour);
	DDX_Text(pDX, IDC_EDIT6, m_id2);
	DDX_Text(pDX, IDC_EDIT7, m_yuan);
}

BEGIN_MESSAGE_MAP(Wage, CFormView)
	ON_BN_CLICKED(IDC_BUTTON2, &Wage::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Wage::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &Wage::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON5, &Wage::OnBnClickedButton5)
END_MESSAGE_MAP()


// Wage 诊断

#ifdef _DEBUG
void Wage::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void Wage::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// Wage 消息处理程序


void Wage::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	MessageBox(TEXT("经理拿固定月薪\n兼职技术人员按工作小时数领取月薪（每小时18元）\n兼职推销员的报酬按该推销员当月销售额提成（85%）\n销售经理既拿固定月薪也领取销售提成（6%）"));
}


void Wage::OnBnClickedButton3()
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

		if (tmp.id == m_id1)
		{
			if (tmp.job != "兼职技术人员")
			{
				MessageBox(TEXT("该职工不符合选定职工类型"));
				break;
			}
			else
			{
				Hour h;
				h.wage = this;
				h.DoModal();
			}
			break;
		}
	}
	ifs.close();//关闭文件
	WorkerManager file;
	file.Read();
	if (m_id1 > file.sum - 1)
	{
		MessageBox(TEXT("未找到该职工"));
	}
	UpdateData(FALSE);
	m_id1 = 0;
}


void Wage::OnBnClickedButton7()
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

		if (tmp.id == m_id2)
		{
			if (tmp.job != "兼职推销员")
			{
				MessageBox(TEXT("该职工不符合选定职工类型"));
				break;
			}
			else
			{
				Yuan y;
				y.wage = this;
				y.DoModal();
			}
			break;
		}
	}
	ifs.close();//关闭文件
	WorkerManager file;
	file.Read();
	if (m_id2 > file.sum - 1)
	{
		MessageBox(TEXT("未找到该职工"));
	}
	UpdateData(FALSE);
	m_id2 = 0;
}


void Wage::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	ifstream ifs(FILENAME);//打开文件
	char buf[1024] = { 0 };//初始化数组
	ifs.getline(buf, sizeof(buf));//取出表头
	int i = 0;//推销员数组

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

		if (tmp.job == "兼职推销员")
		{
			int a = tmp.wage / 0.85;
			arr[i] = a;
			length++;
			i++;
		}
	}
	ifs.close();//关闭文件

	for (int j = 0; j < length; j++)
	{
		n_wage = n_wage + arr[j] * 0.06;
	}

	SellManager s;
	s.wage = this;
	s.DoModal();

	UpdateData(FALSE);
}
