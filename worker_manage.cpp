#include "WorkerManager.h"
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//若文件不存在
	if (!ifs.is_open())
	{
		cout << "提示：职工数据文件暂未创建" << endl;
		this->MEmpNum = 0;
		this->FileEmpty = true;
		this->MEmpArr = NULL;
		ifs.close();
		return;
	}
	//若文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "提示：职工数据文件为空" << endl;
		this->MEmpNum = 0;
		this->MEmpArr = NULL;
		this->FileEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，记录数据
	int sum = this->GetEmpSum();
	cout << "提示：当前职工总数为" << sum << endl;
	this->MEmpNum = sum;
	//开辟空间
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