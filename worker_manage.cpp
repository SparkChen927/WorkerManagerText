#include "WorkerManager.h"
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//���ļ�������
	if (!ifs.is_open())
	{
		cout << "��ʾ��ְ�������ļ���δ����" << endl;
		this->MEmpNum = 0;
		this->FileEmpty = true;
		this->MEmpArr = NULL;
		ifs.close();
		return;
	}
	//���ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "��ʾ��ְ�������ļ�Ϊ��" << endl;
		this->MEmpNum = 0;
		this->MEmpArr = NULL;
		this->FileEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ���¼����
	int sum = this->GetEmpSum();
	cout << "��ʾ����ǰְ������Ϊ" << sum << endl;
	this->MEmpNum = sum;
	//���ٿռ�
	this->MEmpArr = new Worker * [this->MEmpNum];
	this->InitEmp();
}

WorkerManager::~WorkerManager()
{
	if (this->MEmpArr != NULL)
	{
		delete[] this->MEmpArr;
		this->MEmpArr = NULL;
	}
}