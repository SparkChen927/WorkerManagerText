#include "WorkerManager.h"
int main()
{
	WorkerManager wm;
	int choice = 0;
	while (1)
	{
		wm.ShowMenu();
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ£º" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
		{
			wm.ExitSystem();
			break;
		}
		case 1:
		{
			wm.AddEmploy();
			break;
		}
		case 2:
		{
			wm.ShowEmp();
			break;
		}
		case 3:
		{
			wm.DelEmp();
			break;
		}
		case 4:
		{
			wm.ChaEmp();
			break;
		}
		case 5:
		{
			wm.FindEmp();
			break;
		}
		case 6:
		{
			wm.SortEmp();
			break;
		}
		case 7:
		{
			wm.CleamFile();
			break;
		}
		default:
		{
			system("cls");
			break;
		}
		}
	}
	return 0;
}