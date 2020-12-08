#include "GameShop.h"

list<Shop> shops;

void ConcreteStrategyA::Algorithminterface()
{
    /*int i = 0;
    while (i != 1)
    {
        cout << "editor mode" << endl;
        cout << "press '1' to go to main menu." << endl;
        cin >> i;
    }
    enterSystem();
    */
}

void ConcreteStrategyB::Algorithminterface()
{
    char* input = new char;
    cout << setw(45) << "Input player name : ";
    cin >> input;

    Player player(input, 10000);
    player.addItem(Item("short sword", 0, 10, 1), true);
    player.addItem(Item("shoes", 0, 10, 1), true);

    // shopInitialize(shops);

    bool exitShop = false;
    while (!exitShop)
    {
        cout << "\n\n" << setw(57) << "===============================\n\n";
        cout << setw(50) << "Available shop list\n";
        showAllShops(shops);

        cout << "input shop name that you want to use : ";
        // cout << "if you want to go back menu, put 'quit'\n";
        // quit 입력 시 리턴 메뉴
        getchar();

        string input2;
        getline(cin, input2);
        system("cls");

        /* if (input2 == "quit")
        {
            returnToMenu();
        } */

        if (!isValidShop(shops, input2, player))
        {
            cout << setw(14) << "Invalid option" << endl;
        }
    }
}

void ConcreteStrategyC::Algorithminterface()
{
    /*
    int i = 0;
    while (i != 1)
    {
        cout << "save data" << endl;
        cout << "press '1' to go to main menu." << endl;
        cin >> i;
    }
    enterSystem();
    */
}

void ConcreteStrategyD::Algorithminterface()
{
    /*
    int i = 0;
    while (i != 1)
    {
        cout << "load data" << endl;
        cout << "press '1' to go to main menu." << endl;
        cin >> i;
    }
    enterSystem();
    */
}

Context::Context() : m_pStrategy(0) {};

Context::~Context() 
{ 
    if (m_pStrategy) delete m_pStrategy; 
}

void Context::ChangeStrategy(Strategy* pStrategy)
{
    if (m_pStrategy) delete m_pStrategy;
    m_pStrategy = pStrategy;
}

void Context::ContextInterface()
{
    m_pStrategy->Algorithminterface();
}

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
        system("pause");
        system("cls");
        return false;
    }

    if (player.buyItem(item) == false)
    {
        cout << setw(60) << "Sorry, you don't have enough money\n";
        return false;
        system("cls");
    }
    else
    {
        system("cls");
        cout << "\n" << setw(56) << "* * * * * * * * * * * * * * * *\n";
        cout << "\n" << setw(52) << "Thanks, God be with you\n";
        cout << "\n" << setw(56) << "* * * * * * * * * * * * * * * *\n";
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
        //system("pause");
        //system("cls");
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

void shopEditMode()
{
    cout << "Shop Edit Mode\n" << endl;
    // shopInitialize(shops);

    // char* input = new char;
    int a;
    cout << "what function would you like to use\n" << endl;
    cout << "1. add item  2. plus item count  3. minus item count  4. quit" << endl;
    cin >> a;

    if (a == 1)
    {
        // 초기화된 상점 리스트 보여주기
        // 어떤 상점의 아이템을 추가할건지 물어보기
        // 상점 고른 후 해당 상점 아이템 리스트 보여주고
        // 입력받은 아이템 해당 상점에 추가
        // 돌아가기
    }
    else if (a == 2)
    {
        // 초기화된 상점 리스트 보여주기
        // 어떤 상점의 아이템을 추가할건지 물어보기
        // 어떤 상점의 어떤 아이템의 갯수를 증가할껀지 물어보기
        // 해당 아이템 몇개 증가할껀지 물어보기
        // 입력받은 수(정수) 만큼 반복문으로 additemcount()
        // 돌아가기
    }
    else if (a == 3)
    {
        // 2번과 비슷함
    }
    else if (a == 4)
    {
        // 현재 상태 저장하고 entersystem으로 돌아가야함
        // 근데 entersystem에서 상점을 초기화하기 때문에
        // editmode에서 저장된 상태가 다시 초기화됨 < -returntomenu 함수 구현
    }
    else
    {
        cout << "Invalid option\n" << endl;
    }
}

/* void returnToMenu(Player& player, list<Shop>& shop)
{
    // 반환값이 있는 함수
    // edit모드나 player모드 경우에 따라
    // 각각 저장해야 하는 값을 반환해서 저장해 놔야함
    // save load 기능을 구현해야 하기 때문에
} */


void enterSystem()
{
    Context* pContext = new Context();

    shopInitialize(shops);

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
        pContext->ChangeStrategy(new ConcreteStrategyA());
        pContext->ContextInterface();
    }
    else if (u == 2)
    {
        pContext->ChangeStrategy(new ConcreteStrategyB());
        pContext->ContextInterface();
    }
    else if (u == 3)
    {
        pContext->ChangeStrategy(new ConcreteStrategyC());
        pContext->ContextInterface();
    }
    else if (u == 4)
    {
        pContext->ChangeStrategy(new ConcreteStrategyD());
        pContext->ContextInterface();
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