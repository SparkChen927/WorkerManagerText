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
	int MEmpNum;//ͳ�������е�ְ������
	Worker** MEmpArr;//Ա��ָ������
	void save();//�����ļ�
	bool FileEmpty;//�ж��ļ��Ƿ�Ϊ��
	int GetEmpSum();//���ְ�������ļ��е�ְ������
	void InitEmp();//��ʼ��ְ��
	void ShowEmp();//��ʾְ������
	void DelEmp();//ɾ��ְ��
	int ExistOrNot(int id);//�ж�ְ���Ƿ����
	void ChaEmp();//�޸�ְ������
	void FindEmp();//����ְ��
	void SortEmp();//����ְ���������
	void CleamFile();//���ְ������
	~WorkerManager();
};