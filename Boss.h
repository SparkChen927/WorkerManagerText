#pragma once
#include "Worker.h"
class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int dID);
	//��ʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string GetDeptName();
};