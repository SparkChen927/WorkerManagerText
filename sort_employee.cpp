#include "WorkerManager.h"
void WorkerManager::SortEmp()
{
	if (this->FileEmpty)
	{
		cout << "ְ�������ļ������ڻ��ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��\n1.����\n2.����" << endl;
		int sel;
		cin >> sel;
		for (int i = 0; i < this->MEmpNum; i++)
		{
			int m = 1;
			for (int j = i + 1; j < this->MEmpNum; j++)
			{
				if (sel == 1)//����
				{
					if (this->MEmpArr[m]->MID > this->MEmpArr[j]->MID)
					{
						m = j;
					}
				}
				else//����
				{
					if (this->MEmpArr[m]->MID < this->MEmpArr[j]->MID)
					{
						m = j;
					}
				}
			}
			if (i != m)
			{
				Worker* temp = this->MEmpArr[i];
				this->MEmpArr[i] = this->MEmpArr[m];
				this->MEmpArr[m] = temp;
			}
		}
		cout << "����ɹ�" << endl;
		this->save();
		cout << "������Ϊ��" << endl;
		this->ShowEmp();
	}
}