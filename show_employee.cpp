#include "WorkerManager.h"
void WorkerManager::ShowEmp()
{
	if (this->FileEmpty)
	{
		cout << "ְ�������ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->MEmpNum; i++)
		{
			this->MEmpArr[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}