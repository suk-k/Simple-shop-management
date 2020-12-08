#include <iostream>
#include <list>
#include <string>
#include <iomanip>

using namespace std;

class Strategy
{
public:
	virtual void Algorithminterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
	void Algorithminterface();
};

class ConcreteStrategyB : public Strategy
{
public:
	void Algorithminterface();
};

class ConcreteStrategyC : public Strategy
{
public:
	void Algorithminterface();
};

class ConcreteStrategyD : public Strategy
{
public:
	void Algorithminterface();
};

class Context
{
	Strategy* m_pStrategy;
public:
	Context();
	~Context();
	void ChangeStrategy(Strategy* pStrategy);
	void ContextInterface();
};

class Item
{
private:
	const char* itemName;
	int itemID;
	int itemPrice;
	int itemCount;
public:
	Item() : itemName("Default"), itemID(0), itemPrice(0), itemCount(0) {}
	Item(const char* name, int id, int price, int count)
		: itemName(name), itemID(id), itemPrice(price), itemCount(count)
	{
		if (itemCount < 0)
			itemCount = 0;
	}
	Item(const char* name) : itemName(name) {}

	void showItemInfo();
	void addItemCount();
	void removeItemCount();
	// void showItem(list<string>& itemList)

	string getItemName() const { return itemName; }
	int getItemID() const { return itemID; }
	int getItemPrice() const { return itemPrice; }
	int getItemCount() const { return itemCount; }

	void setItemName(const char* name) { itemName = name; }
	void setItemID(const int id) { itemID = id; }
	void setItemPrice(const int price) { itemPrice = price; }
	void setItemCount(const int count) { itemCount = count; }
};

class Character
{
public:
	virtual ~Character() {}
	virtual void addItem(const Item& item, bool newItem = false) = 0;
	virtual bool removeItem(string& itemName) = 0;
	virtual void showItemList() = 0;
	virtual void getItem(string& itemName, Item& item) = 0;
};

class Player : public Character
{
private:
	list<Item> itemList;
	char* playerName;
	int playerMoney;
public:
	Player() : playerName(NULL), playerMoney(0) {}
	Player(char* name, int money) : playerName(name), playerMoney(money) {}
	~Player() { itemList.clear(); }

	void addItem(const Item& item, bool newItem = false);
	bool removeItem(string& itemName);
	void showItemList();
	void showPlayerInfo();
	bool buyItem(const Item& item);
	void getItem(string& itemName, Item& item);
};

class Shop : public Character
{
private:
	list<Item> itemList;
	const char* shopName;
public:
	Shop() : shopName("Default") {}
	Shop(const char* name) : shopName(name) {}
	~Shop() { itemList.clear(); }

	void addItem(const Item& item, bool newItem = false);
	bool removeItem(string& itemName);
	void showItemList();
	void showShopInfo();
	void getItem(string& itemName, Item& item);
	bool sellItem(Player& player);
	void enterShop(Player& player);

	const char* getShopName() const { return shopName; }
	void setShopName(char* name) { shopName = name; }
};

bool isValidShop(list<Shop>& shops, string& shopName, Player& player);
void showAllShops(const list<Shop>& shops);
void shopInitialize(list<Shop>& shops);
void enterSystem();
void playerMode();
void shopEditMode();
void returnToMenu(Player& player, list<Shop>& shop);