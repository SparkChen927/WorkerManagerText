#include "WorkerManager.h"
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->MEmpNum; i++)
	{
		ofs << this->MEmpArr[i]->MID << " " << this->MEmpArr[i]->MName << " " << this->MEmpArr[i]->MDeptID << endl;
	}
	ofs.close();
}