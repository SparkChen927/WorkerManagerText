#pragma once
#include <string>


// FindWorker 窗体视图

class FindWorker : public CFormView
{
	DECLARE_DYNCREATE(FindWorker)

protected:
	FindWorker();           // 动态创建所使用的受保护的构造函数
	virtual ~FindWorker();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FindWorker };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list;
public:
//	virtual void OnInitialUpdate();
private:
	int m_id;
	CString m_name;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton4();


private:
	bool FindName(CString cstr)//构造判断职工是否存在函数
	{
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

			string str = CT2A(cstr.GetBuffer());

			if (tmp.name == str)
			{
				return FALSE;
				break;
			}
		}
		ifs.close();//关闭文件
		return TRUE;
	}
public:
	afx_msg void OnBnClickedButton5();
};


