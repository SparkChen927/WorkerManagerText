#include "WorkerManager.h"
void WorkerManager::CleamFile()
{
	cout << "�Ƿ�ȷ����գ�\n1.��\n2.��" << endl;
	int sel;
	cin >> sel;
	if (sel == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->MEmpArr != NULL)
		{
			for (int i = 0; i < this->MEmpNum; i++)
			{
				if (this->MEmpArr[i] != NULL)
				{
					delete this->MEmpArr[i];
				}
			}
			this->MEmpNum = 0;
			delete[] this->MEmpArr;
			this->FileEmpty = true;
		}
	}
	system("pause");
	system("cls");
}