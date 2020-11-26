#include "GameShop.h"

int main()
{
	int a;
	while (1)
	{
		cout << "\n \t\t\t=========================\n";
		cout << "\n\t\t\tWELCOME TO MY SHOP" << "\n";
		cout << "\n \t\t\t=========================\n\n";
		cout << "\n \t\t\t* * * * * * * * * * * * ";
		cout << "\n\t\t\t  1. ENTER SYSTEM";
		cout << "\n\t\t\t  2. EXIT";
		cout << "\n\t\t\t* * * * * * * * * * * *\n";
		cout << "\n\t\t\t Enter Your choice: ";
		cin >> a;
		if (a == 1)
		{
			enterSystem();
		}
		else if (a == 2)
		{
			exit(0);
		}
		else
		{
			cout << "Invalid option\n" << endl;
		}
		break;
	}
	system("pause");

	return 0;
}
