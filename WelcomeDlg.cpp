// WelcomeDlg.cpp: 实现文件
//

#include "pch.h"
#include "WorkerManager.h"
#include "WelcomeDlg.h"


// WelcomeDlg

IMPLEMENT_DYNCREATE(WelcomeDlg, CFormView)

WelcomeDlg::WelcomeDlg()
	: CFormView(IDD_Welcome)
{

}

WelcomeDlg::~WelcomeDlg()
{
}

void WelcomeDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(WelcomeDlg, CFormView)
END_MESSAGE_MAP()


// WelcomeDlg 诊断

#ifdef _DEBUG
void WelcomeDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void WelcomeDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// WelcomeDlg 消息处理程序


void WelcomeDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	ifstream ifs(FILENAME);//打开文件
	if (ifs.eof())//若文件为空加入表头
	{
		ofstream ofs(FILENAME);
		ofs << "职工编号|职工姓名|职工级别|职工薪水" << endl;
	}

	else//防止修改文件编号发生错误
	{
		InitData();
	}
}
