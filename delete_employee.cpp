#include "WorkerManager.h"
void WorkerManager::DelEmp()
{
	if (this->FileEmpty)
	{
		cout << "ְ�������ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ��ְ���ı�ţ�";
		int id;
		cin >> id;
		int index = this->ExistOrNot(id);
		if (index != -1)//ְ�����ڣ�ɾ����ְ��
		{
			int ret = this->ExistOrNot(id);
			cout << "���ҵ���" << endl;
			this->MEmpArr[ret]->ShowInfo();
			cout << "�Ƿ�ȷ�ϣ�\n1.��\n2.��" << endl;
			int sel;
			cin >> sel;
			if (sel == 1)
			{
				for (int i = index; i < this->MEmpNum - 1; i++)
				{
					this->MEmpArr[i] = this->MEmpArr[i + 1];//����ǰ��
				}
				this->MEmpNum--;//��������
				this->save();
				cout << "ɾ���ɹ�" << endl;
			}
			else if (sel == 2)
			{
				cout << "��ȡ��" << endl;
			}
			else
			{
				cout << "ѡ�����" << endl;
			}
		}
		else
		{
			cout << "δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}