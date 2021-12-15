#pragma once
#include <iostream>
#include "Worker.h"
#include "Boss.h"
#include "Employee.h"
#include "Manager.h"
#include <fstream>
#define FILENAME "emp_file.txt"
using namespace std;
class WorkerManager
{
public:
	WorkerManager();
	void ShowMenu();
	void ExitSystem();
	void AddEmploy();
	int MEmpNum;//统计数组中的职工人数
	Worker** MEmpArr;//员工指针数组
	void save();//保存文件
	bool FileEmpty;//判断文件是否为空
	int GetEmpSum();//获得职工数据文件中的职工人数
	void InitEmp();//初始化职工
	void ShowEmp();//显示职工数据
	void DelEmp();//删除职工
	int ExistOrNot(int id);//判断职工是否存在
	void ChaEmp();//修改职工数据
	void FindEmp();//查找职工
	void SortEmp();//按照职工编号排序
	void CleamFile();//清空职工数据
	~WorkerManager();
};