// CSelectView.cpp: 实现文件
//

#include "pch.h"
#include "WorkerManager.h"
#include "CSelectView.h"
#include "MainFrm.h"


// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView 诊断

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView 消息处理程序


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	//加载图标资源 IDI_ICON_RE
	HICON icon = AfxGetApp()->LoadIconW(IDI_ICON_RE);

	//创建图标列表
	m_imageList.Create(30, 30, ILC_COLOR32, 1, 1);

	//图片列表追加图标
	m_imageList.Add(icon);

	//获取数视图中的树控件
	m_treeCtrl = &GetTreeCtrl();

	//数控件设置图片列表
	m_treeCtrl->SetImageList(&m_imageList, TVSIL_NORMAL);

	//树控件设置节点
	m_treeCtrl->InsertItem(TEXT("主界面"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("添加职工信息"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("查看职工信息"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("修改职工信息"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("删除离职职工"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("查找指定职工"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("更新工资信息"), 0, 0, NULL);
}


void CSelectView::OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	//获取当前节点选中项目 CTreeCtrl::GetSelectedItem
	HTREEITEM item = m_treeCtrl->GetSelectedItem();

	//获取选中项的文本内容 CTreeCtrl::GetItemText
	CString str = m_treeCtrl->GetItemText(item);


	if (str == TEXT("主界面"))
	{
		//CWnd::PostMessage 将一个消息放入窗口的消息队列
		//AfxGetMainWnd()：框架窗口对象的指针
		//AfxGetMainWnd()->GetSafeHwnd()：获取返回窗口的句柄，CWnd::GetSafeHwnd
		//NM_A：发送自定义消息
		//(WPARAM)NM_A：指定了附加的消息信息
		//(LPARAM)0：指定了附加的消息信息，此参数这里没有意义
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}
	else if (str == TEXT("添加职工信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	else if (str == TEXT("查看职工信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	else if (str == TEXT("修改职工信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}
	else if (str == TEXT("删除离职职工"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
	}
	else if (str == TEXT("查找指定职工"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_F, (WPARAM)NM_F, (LPARAM)0);
	}
	else if (str == TEXT("更新工资信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_G, (WPARAM)NM_G, (LPARAM)0);
	}

}
