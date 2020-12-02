#pragma once
#include <iostream>
#include <list>
#include <string>
#include <iomanip>
using namespace std;

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

class Player
{
private:
   list<Item> itemList;
   char* playerName;
   int playerMoney;
public:
   Player() : playerName(NULL), playerMoney(0) {}
   Player(char* name, int money) : playerName(name), playerMoney(돈) {}
   ~Player() { itemList.clear(); }

   void addItem(const Item& item, bool newItem = false);
   bool removeItem(string& itemName);
   void showItemList();
   void showPlayerInfo();
   bool buyItem(const Item& item);
   void getItem(string& itemName, Item& item);
};

class Shop
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
