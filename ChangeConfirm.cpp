// ChangeConfirm.cpp: 实现文件
//

#include "pch.h"
#include "WorkerManager.h"
#include "afxdialogex.h"
#include "ChangeConfirm.h"


// ChangeConfirm 对话框

IMPLEMENT_DYNAMIC(ChangeConfirm, CDialogEx)

ChangeConfirm::ChangeConfirm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChangeConfirm, pParent)
	, c_name(_T(""))
	, c_wage(0)
{

}

ChangeConfirm::~ChangeConfirm()
{
}

void ChangeConfirm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT4, c_name);
	DDX_Control(pDX, IDC_COMBO1, c_job);
	DDX_Text(pDX, IDC_EDIT3, c_wage);
}


BEGIN_MESSAGE_MAP(ChangeConfirm, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &ChangeConfirm::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &ChangeConfirm::OnBnClickedOk)
END_MESSAGE_MAP()


// ChangeConfirm 消息处理程序


BOOL ChangeConfirm::OnInitDialog()
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

		if (tmp.id == worker->m_id)
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

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ChangeConfirm::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void ChangeConfirm::OnBnClickedOk()
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

		if (tmp.id == worker->m_id)
		{
			CStringA str1, str2;
			str1 = c_name;
			tmp.name = str1.GetBuffer();
			//获取职位名称
			int index = c_job.GetCurSel();
			//根据索引获取到具体内容
			CString job;
			c_job.GetLBText(index, job);
			str2 = job;
			tmp.job = str2.GetBuffer();
			tmp.wage = c_wage;
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
	MessageBox(TEXT("修改成功"));
	CDialogEx::OnOK();
}
