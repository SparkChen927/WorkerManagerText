#pragma once
#include <iostream>
#include <string>
using namespace std;
//职工抽象类
class Worker
{
public:
	//显示个人信息
	virtual void ShowInfo() = 0;
	//获取岗位名称
	virtual string GetDeptName() = 0;
	int MID;//职工编号
	string MName;//职工姓名
	int MDeptID;//部门编号
};