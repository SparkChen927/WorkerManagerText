#pragma once
#include "Worker.h"
class Manager :public Worker
{
public:
	//���캯��
	Manager(int id, string name, int dID);
	//��ʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string GetDeptName();
};