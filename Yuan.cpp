// Yuan.cpp: 实现文件
//

#include "pch.h"
#include "WorkerManager.h"
#include "afxdialogex.h"
#include "Yuan.h"


// Yuan 对话框

IMPLEMENT_DYNAMIC(Yuan, CDialogEx)

Yuan::Yuan(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Yuan, pParent)
{

}

Yuan::~Yuan()
{
}

void Yuan::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_LIST3, m_list2);
}


BEGIN_MESSAGE_MAP(Yuan, CDialogEx)
	ON_BN_CLICKED(IDOK, &Yuan::OnBnClickedOk)
END_MESSAGE_MAP()


// Yuan 消息处理程序


void Yuan::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	ifstream ifs(FILENAME);//打开文件
	list<msg> ls;//数据容器
	char buf[1024] = { 0 };//初始化数组
	ls.clear();
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

		if (tmp.id == wage->m_id2)
		{
			tmp.wage = 0.85 * wage->m_yuan;
		}
		ls.push_back(tmp);//放在列表后面
	}
	ifs.close();//关闭文件

	ofstream ofs(FILENAME);//打开文件

	if (ls.size() > 0)//有内容
	{
		ofs << "职工编号|职工姓名|职工级别|职工薪水" << endl;//表头

		//写入文件
		for (list<msg>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			ofs << it->id << "|";
			ofs << it->name << "|";
			ofs << it->job << "|";
			ofs << it->wage << endl;
		}
	}

	ofs.close();//关闭文件
	MessageBox(TEXT("更新成功"));

	CDialogEx::OnOK();
}


BOOL Yuan::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	// 设置扩展风格
	//LVS_EX_FULLROWSELECT选中整行，LVS_EX_GRIDLINES网格
	m_list1.SetExtendedStyle(m_list1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list2.SetExtendedStyle(m_list2.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 初始化表头
	CString field[] = { _T("职工编号"), _T("职工姓名"), _T("职工级别"), _T("职工薪水") };
	for (int i = 0; i < sizeof(field) / sizeof(field[0]); ++i)
	{
		m_list1.InsertColumn(i, field[i], LVCFMT_CENTER, 105);
		m_list2.InsertColumn(i, field[i], LVCFMT_CENTER, 105);
	}
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

		int n_wage = 0.85 * wage->m_yuan;

		if (tmp.id == wage->m_id2)
		{
			CString str1, str2, str3, str4, str5;
			str1.Format(_T("%d"), tmp.id);
			m_list1.InsertItem(0, str1);
			int column = 1;
			m_list1.SetItemText(0, column++, (CString)tmp.name.c_str());
			m_list1.SetItemText(0, column++, (CString)tmp.job.c_str());
			str4.Format(_T("%d"), tmp.wage);
			m_list1.SetItemText(0, column++, str4);
			m_list2.InsertItem(0, str1);
			column = 1;
			m_list2.SetItemText(0, column++, (CString)tmp.name.c_str());
			m_list2.SetItemText(0, column++, (CString)tmp.job.c_str());
			str5.Format(_T("%d"), n_wage);
			m_list2.SetItemText(0, column++, str5);
			break;
		}
	}
	ifs.close();//关闭文件

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
