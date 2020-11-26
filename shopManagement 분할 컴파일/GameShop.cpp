#include "GameShop.h"

// Item class
void Item::showItemInfo()
{
	cout << "name: " << itemName << " id: " << itemID << " price: " << itemPrice << " count: " << itemCount << endl;
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
void Player::addItem(const Item& item, bool newItem = false)
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
		cout << "(" << i << ") " << (*it).getItemName() << " x "
			<< (*it).getItemCount() << " price : " << (*it).getItemPrice() << "\n";
	}
	cout << "" << endl;
}

void Player::showPlayerInfo()
{
	cout << "Player name : " << playerName << endl;
	cout << "Left money : " << playerMoney << endl;
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
void Shop::addItem(const Item& item, bool newItem = false)
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
		cout << "(" << i << ") " << (*it).getItemName() << " x "
			<< (*it).getItemCount() << " price : " << (*it).getItemPrice() << "\n";
	}
	cout << "" << endl;
}

void Shop::showShopInfo()
{
	cout << "Welcome to " << shopName << endl;
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
	cout << "What item do you want to buy" << endl;
	cout << "item : ";

	string input;
	cin.ignore();
	getline(cin, input);
	cout << endl;

	Item item;
	getItem(input, item);

	if (item.getItemName() == "Default")
	{
		cout << "It doesn't exist\n";
		return false;
	}

	if (player.buyItem(item) == false)
	{
		cout << "Sorry, you don't have enough money\n";
		return false;
	}
	else
	{
		cout << "Thanks, God be with you\n";
		removeItem(input);
		return true;
	}
	return true;
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
		cout << "what are you going to do?\n" << endl;
		cout << "1. go back" << "   " << "2. buy item \n" << endl;
		cin >> a;

		if (a == 1)
		{
			cout << "thanks for yout visiting\n" << endl;
			exitShop = true;
		}
		else if (a == 2)
		{
			sellItem(player);
		}
		else
		{
			cout << "Invalid option" << endl;
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
		cout << "(" << num << ") " << (*it).getShopName() << endl;
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
	cout << "\n\t\t\t==============================\n";
	cout << "\n\t\t\t     WELCOME TO THE SHOP  \n";
	cout << "\n\t\t\t==============================\n\n";
	cout << "\n\t\t\t* * * * * * * * * * * * * * * *\n";
	cout << "\n\t\t\t1. Shop editor mode\n\n\t\t\t2. Player mode\n\n\t\t\t3. Save data\n\n\t\t\t4. Load data\n\n\t\t\t5. Exit\n";
	cout << "\n\n\t\t\tSelect your choice ";
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
		cout << "Input player name : ";
		cin >> input;

		Player player(input, 10000);
		player.addItem(Item("short sword", 0, 10, 1), true);
		player.addItem(Item("shoes", 0, 10, 1), true);

		list<Shop> shops;
		shopInitialize(shops);

		bool exitShop = false;
		while (!exitShop)
		{
			cout << "\n";
			cout << "Available shop list\n";
			showAllShops(shops);

			cout << "input shop name that you want to use\n";
			// cout << "if you want to go back menu, put 'quit'\n";
			// quit 입력 시 다시 enterSystem()
			string input2;
			getline(cin, input2);

			if (!isValidShop(shops, input2, player))
			{
				cout << "Invalid option\n" << endl;
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
		cout << "Invalid option\n" << endl;
	}
}
