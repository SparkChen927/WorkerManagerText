#pragma once
#include "Worker.h"
class Employee :public Worker
{
public:
	//���캯��
	Employee(int id, string name, int dID);
	//��ʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string GetDeptName();
};