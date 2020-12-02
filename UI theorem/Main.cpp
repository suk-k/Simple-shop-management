#include "Game Shop.h"

int main()
{
	int a;
	while (1)
	{
		cout << "\n\n" << setw(56) << "===============================\n";
		cout << "\n" << setw(49) << "WELCOME TO MY SHOP" << "\n";
		cout << "\n" << setw(57) << "===============================\n\n";
		cout << "\n" << setw(55) << "* * * * * * * * * * * * * * * *";
		cout << "\n\n" << setw(41) << "1. ENTER SYSTEM";
		cout << "\n\n" << setw(33) << "2. EXIT";
		cout << "\n\n" << setw(56) << "* * * * * * * * * * * * * * * *\n";
		cout << "\n" << setw(44) << "Enter Your choice : ";
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
			cout << setw(40) << "Invalid option\n" << endl;
		}
		break;
	}
	system("pause");
	return 0;
}
