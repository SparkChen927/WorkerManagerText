#include "WorkerManager.h"
void WorkerManager::FindEmp()
{
	if (this->FileEmpty)
	{
		cout << "ְ�������ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��\n1.����Ų���\n2.����������" << endl;
		int sel;
		cin >> sel;
		if (sel == 1)
		{
			int id;
			cout << "������ְ����ţ�"; cin >> id;
			int ret = this->ExistOrNot(id);
			if (ret != -1)
			{
				cout << "���ҵ���" << endl;
				this->MEmpArr[ret]->ShowInfo();
			}
			else
			{
				cout << "δ�ҵ���ְ��" << endl;
			}
		}
		else if (sel == 2)
		{
			string name;
			cout << "������ְ��������"; cin >> name;
			bool flag = false;
			for (int i = 0; i < this->MEmpNum; i++)
			{
				if (this->MEmpArr[i]->MName == name)
				{
					flag = true;
					this->MEmpArr[i]->ShowInfo();
				}
			}
			if (flag == false)
			{
				cout << "δ�ҵ���ְ��" << endl;
			}
		}
		else
		{
			cout << "ѡ�����" << endl;
		}
	}
	system("pause");
	system("cls");
}