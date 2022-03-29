
// WorkerManager.h: WorkerManager 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#define FILENAME "file.txt"
using namespace std;


// CWorkerManagerApp:
// 有关此类的实现，请参阅 WorkerManager.cpp
//

class CWorkerManagerApp : public CWinApp
{
public:
	CWorkerManagerApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWorkerManagerApp theApp;

struct msg
{
	int id;//职工编号
	string name;//姓名
	string job;//级别
	int wage;//薪水
	int sum;//职工总数
};

class WorkerManager
{
public:
	WorkerManager();//构造
	~WorkerManager();//析构

	void Read();//读取职工数据
	void Write();//导出职工数据
	void Add(CString name, CString job, int wage);//添加职工

	list<msg> ls;//数据容器
	int sum;//记录员工数量
};

void InitData();
