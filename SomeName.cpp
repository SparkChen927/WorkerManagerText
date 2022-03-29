// SomeName.cpp: 实现文件
//

#include "pch.h"
#include "WorkerManager.h"
#include "afxdialogex.h"
#include "SomeName.h"


// SomeName 对话框

IMPLEMENT_DYNAMIC(SomeName, CDialogEx)

SomeName::SomeName(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SomeNames, pParent)
{

}

SomeName::~SomeName()
{
}

void SomeName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
}


BEGIN_MESSAGE_MAP(SomeName, CDialogEx)
END_MESSAGE_MAP()


// SomeName 消息处理程序


BOOL SomeName::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

			// 设置扩展风格
	//LVS_EX_FULLROWSELECT选中整行，LVS_EX_GRIDLINES网格
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 初始化表头
	CString field[] = { _T("职工编号"), _T("职工姓名"), _T("职工级别"), _T("职工薪水") };
	for (int i = 0; i < sizeof(field) / sizeof(field[0]); ++i)
	{
		m_list.InsertColumn(i, field[i], LVCFMT_CENTER, 105);
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

		CStringA str;
		str = worker->m_name;

		if (tmp.name == str.GetBuffer())
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

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
