#include "Game Shop.h"

// Item class
void Item::showItemInfo()
{
	cout << setw(42) << "name: " << itemName << " id: " << itemID << " price: " << itemPrice << " count: " << itemCount << endl;
}

void Item::addItemCount()
{
	itemCount++;
}

void Item::removeItemCount()
{
	itemCount--;
}

/* void Item::showItem(list<string>& itemList)
	{
		for (auto it = itemList.begin(); it != itemList.end(); ++it)
		{
			cout << *it << endl;
		}
		cout << "" << endl;
	}
*/


// Player class
void Player::addItem(const Item& item, bool newItem)
{
	for (auto it = itemList.begin(); it != itemList.end(); ++it)
	{
		if ((*it).getItemName() == item.getItemName())
		{
			(*it).addItemCount();
			return;
		}
	}

	itemList.push_back(item);

	if (newItem == false)
	{
		itemList.back().setItemCount(1);
	}
}

bool Player::removeItem(string& itemName)
{
	for (auto it = itemList.begin(); it != itemList.end(); ++it)
	{
		if ((*it).getItemName() == itemName)
		{
			(*it).removeItemCount();
		}

		if ((*it).getItemCount() <= 0)
		{
			itemList.erase(it);
			return true;
		}
	}
	return false;
}

void Player::showItemList()
{
	int i = 1;
	for (auto it = itemList.begin(); it != itemList.end(); ++it, ++i)
	{
		cout << setw(26) << "(" << i << ") " << (*it).getItemName() << " x "
			<< (*it).getItemCount() << " price : " << (*it).getItemPrice() << "\n";
	}
	cout << "" << endl;
}

void Player::showPlayerInfo()
{
	cout << setw(39) << "Player name : " << playerName << endl;
	cout << setw(38) << "Left money : " << playerMoney << endl;
	showItemList();
}

bool Player::buyItem(const Item& item)
{
	if (playerMoney >= item.getItemPrice())
	{
		playerMoney -= item.getItemPrice();
		addItem(item);
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

void Player::getItem(string& itemName, Item& item)
{
	for (auto it = itemList.begin(); it != itemList.end(); ++it)
	{
		if ((*it).getItemName() == itemName)
			item = (*it);
	}
}


// Shop class
void Shop::addItem(const Item& item, bool newItem)
{
	for (auto it = itemList.begin(); it != itemList.end(); ++it)
	{
		if ((*it).getItemName() == item.getItemName())
		{
			(*it).addItemCount();
			return;
		}
	}

	itemList.push_back(item);

	if (newItem == false)
	{
		itemList.back().setItemCount(1);
	}
}

bool Shop::removeItem(string& itemName)
{
	for (auto it = itemList.begin(); it != itemList.end(); ++it)
	{
		if ((*it).getItemName() == itemName)
		{
			(*it).removeItemCount();
		}

		if ((*it).getItemCount() <= 0)
		{
			itemList.erase(it);
			return true;
		}
	}
	return false;
}

void Shop::showItemList()
{
	int i = 1;
	for (auto it = itemList.begin(); it != itemList.end(); ++it, ++i)
	{
		cout << setw(26) << "(" << i << ") " << (*it).getItemName() << " x "
			<< (*it).getItemCount() << " price : " << (*it).getItemPrice() << "\n";
	}
	cout << "" << endl;
}

void Shop::showShopInfo()
{
	cout << "\n" << setw(56) << "* * * * * * * * * * * * * * * *\n";
	cout << "\n" << setw(42) << "Welcome to " << shopName << "\n" << endl;
	showItemList();
}

void Shop::getItem(string& itemName, Item& item)
{
	for (auto it = itemList.begin(); it != itemList.end(); ++it)
	{
		if ((*it).getItemName() == itemName)
			item = *it;
	}
}

bool Shop::sellItem(Player& player)
{
	cout << "\n " << setw(53) << "What item do you want to buy\n" << endl;
	cout << setw(32) << "item : ";

	string input;
	cin.ignore();
	getline(cin, input);
	cout << endl;

	Item item;
	getItem(input, item);

	if (item.getItemName() == "Default")
	{
		cout << "\n" << setw(43) << "It doesn't exist\n\n";
		return false;
	}

	if (player.buyItem(item) == false)
	{
		cout << setw(60) << "Sorry, you don't have enough money\n";
		return false;
	}
	else
	{
		cout << "\n" << setw(56) << "* * * * * * * * * * * * * * * *\n";
		cout << "\n" << setw(52) << "Thanks, God be with you\n";
		cout << "\n" << setw(56) << "* * * * * * * * * * * * * * * *\n";
		removeItem(input);
		return true;
	}
}

void Shop::enterShop(Player& player)
{
	bool exitShop = false;

	while (!exitShop)
	{
		// cout << "성공했다면 이 문구가 출력됨" << endl;
		showShopInfo();
		player.showPlayerInfo();

		int a;
		cout << setw(51) << "what are you going to do?\n" << endl;
		cout << setw(35) << "1. go back" << "   " << "2. buy item \n" << endl;
		cout << setw(25) << "";
		cin >> a;

		if (a == 1)
		{
			cout << "\n" << setw(56) << "* * * * * * * * * * * * * * * *\n\n";
			cout << setw(50) << "thanks for yout visiting" << endl;
			cout << "\n" << setw(55) << "* * * * * * * * * * * * * * * *\n";
			exitShop = true;
		}
		else if (a == 2)
		{
			sellItem(player);
		}
		else
		{
			cout << setw(47) << "Invalid option" << endl;
			exitShop = false;
		}
		system("pause");
		system("cls");
	}
}


// Function
bool isValidShop(list<Shop>& shops, string& shopName, Player& player)
{
	for (auto it = shops.begin(); it != shops.end(); ++it)
	{
		if ((*it).getShopName() == shopName)
		{
			(*it).enterShop(player);
			return true;
		}
	}
	return false;
}

void showAllShops(const list<Shop>& shops)
{
	int num = 1;
	for (auto it = shops.begin(); it != shops.end(); ++it, ++num)
	{
		cout << "\n" << setw(26) << "(" << num << ") " << (*it).getShopName() << endl;
	}
	cout << endl;
}

void shopInitialize(list<Shop>& shops)
{
	shops.push_back(Shop("equip"));
	shops.back().addItem((Item("broad sword", 0, 1000, 10)), true);
	shops.back().addItem((Item("steel sword", 0, 1500, 15)), true);
	shops.back().addItem((Item("bastard sword", 0, 2000, 10)), true);
	shops.back().addItem((Item("rapier", 0, 2500, 5)), true);

	shops.push_back(Shop("potion"));
	shops.back().addItem((Item("red potion", 0, 250, 20)), true);
	shops.back().addItem((Item("blue potion", 0, 500, 20)), true);
	shops.back().addItem((Item("purple potion", 0, 750, 10)), true);
	shops.back().addItem((Item("white potion", 0, 1000, 10)), true);

	shops.push_back(Shop("restaurant"));
	shops.back().addItem((Item("bread", 0, 50, 50)), true);
	shops.back().addItem((Item("chicken", 0, 150, 20)), true);
	shops.back().addItem((Item("beef", 0, 350, 15)), true);
	shops.back().addItem((Item("potato", 0, 25, 90)), true);
}

void enterSystem()
{
	int u;
	cout << "\n" << setw(56) << "===============================\n";
	cout << "\n" << setw(52) << "WELCOME TO THE SHOP  \n";
	cout << "\n" << setw(57) << "===============================\n\n";
	cout << "\n" << setw(56) << "* * * * * * * * * * * * * * * *\n";
	cout << "\n" << setw(47) << "1. Shop editor mode\n\n" << setw(42) << "2. Player mode\n\n" << setw(40) << "3. Save data\n\n" << setw(40) << "4. Load data\n\n" << setw(34) << "5. Exit\n";
	cout << "\n" << setw(56) << "* * * * * * * * * * * * * * * *\n";
	cout << "\n" << setw(46) << "Select your choice : ";
	cin >> u;
	cout << endl;


	if (u == 1)
	{
		// shop editor mode
	}
	else if (u == 2)
	{
		char* input = new char;
		int a;
		cout << setw(57) << "* * * * * * * * * * * * * * * *\n\n";
		cout << setw(45) << "Input player name : ";
		cin >> input;

		Player player(input, 10000);
		player.addItem(Item("short sword", 0, 10, 1), true);
		player.addItem(Item("shoes", 0, 10, 1), true);

		list<Shop> shops;
		shopInitialize(shops);

		bool exitShop = false;
		while (!exitShop)
		{
			cout << "\n\n" << setw(57) << "===============================\n\n";
			cout << setw(50) << "Available shop list\n";
			showAllShops(shops);

			cout << setw(61) << "input shop name that you want to use";
			// cout << "if you want to go back menu, put 'quit'\n";
			// quit 입력 시 다시 enterSystem()
			string input2;
			cout << "\n" << setw(25) << "";
			getline(cin, input2);

			if (!isValidShop(shops, input2, player))
			{
				cout << setw(14) << "Invalid option" << endl;
			}
			system("pause");
			system("cls");
		}
	}
	else if (u == 3)
	{
		// Save data
	}
	else if (u == 4)
	{
		// Load data
	}
	else if (u == 5)
	{
		exit(0);
	}
	else
	{
		cout << setw(32) << "Invalid option\n" << endl;
	}
}
