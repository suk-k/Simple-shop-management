#include<fstream> // 이 클래스의 오브젝트는 파일버프 객체를 내부 스트림 버퍼로 유지, 이 버퍼가 연결된 파일(있는 경우)에서 입력/출력 작업 수행.
#include<iostream> // (기본) 문자 시퀀스의 입력을 읽고 해석 가능
#include<string> // 문자열을 담는 클래스 
#include<cstdlib> // 동적 메모리 관리, 난수 생성, 환경과의 통신, 정수산술, 검색, 정렬 및 변환을 포함한 몇 가지 범용 기능을 정의
#include <cstring> // C 문자열과 배열을 조작하는 몇 가지 기능을 정의

#include<stdio.h>           // C 언어의 표준 라이브러리 함수의 매크로 정의, 상수, 여러 형의 입출력 함수가 포함된 헤더 파일
using namespace std;
class file{
public:
    file(){
        ofstream fout;           // ofsream: 파일 쓰기 기능(ifstream: 파일 읽기) // https://blockdmask.tistory.com/322
        fout.open("anish.txt");  
        fout<<"anish";
        fout.close();
    }
};
class earn{
        public:
        double profit;
        void show()
		{
		ifstream x("ooo.txt");    // ifstream: 위 주석 참고
        if(!x)
        cout<<"PROFIT = 0 ";
        else{
        x>>profit;
        cout<<"\nTOTAL STARTING PROFIT:  "<<profit<<endl;
        x.close();
        }
        
        }

};
class product:public virtual earn{
public:
           int quan;
           char name[20];
           char id[20];
           double percost;
           double persell;
           double cost;
           double sell;
           void cal()
		   {
		    cost=percost*quan;
        	sell=persell*quan;
            profit=profit +(sell-cost)*365;
			}
           void file(); // 76번줄에 정의됨
           void get();  // 바로 밑에 정의됨

};
void product::get()
{
 int s;
cout<<"\nnumber of products produced?\n";
cin>>s;
for(int i=0;i<s;i++)
{
  cout<<"\ninput product name: \n";
  cin>>name;
  cout<<"\ninput product id: \n";
  cin>>id;
  cout<<"\ninput cost price of product: \n";
  cin>>percost;
  cout<<"\ninput selling price of product: \n";
  cin>>persell;
  cout<<"\ntotal product quantity: \n";
  cin>>quan;
    cal();     // 44번줄에 정의됨
    file();    // 76번줄에 정의됨
  }
 
}
void product::file()
{
char file[20];
strcpy(file,id);
strcat(file,".txt");
ofstream f(file);
f<< "\nproduct name: "<<name<< "\nproduct id: "<<id<<"\ncost price of product: " <<percost<<"\nselling price of product: "<<persell<<"\nquantity: "<<quan<<"\n total cost: "<<cost<<"\nsell: "<<sell;
f.close();
}

class staff:public virtual earn{
         protected:
         double salary;
         char post[12];
         char empid[10];
         int postquan;
         void cal()
         {
		 profit=(profit-salary*postquan)*12;
         }
         void getstaff();  //96 번줄에 정의
         void file();
};
void staff::getstaff()
{
  cout<<"\ninput salary: \n";
  cin>>salary;
  cout<<"\ninput number of employees: \n";
  cin>>postquan;
  for(int i=0;i<postquan;i++)
  {
  	cout<<"input employee name\n";
  	cin>>post;
  cout<<"\ninput employee ID\n";
  cin>>empid;
  cal();
  file();
}
}
 void staff::file()
{  char file[20];
strcpy(file,empid);
strcat(file,".txt");
ofstream f(file);
f<< "\nnumber of working employees: "<<postquan<< "\nemployee salary: "<<salary<< "\nemployee name :"<<post<<"\nemployee id: "<<empid;
f.close();
}

class amount:public staff, public product
{

 public:
    void add();          // 133 번줄 정의
    void update_item();  // 162 번줄 정의
    void update_emp();   // 195 번줄 정의

};
void amount::add()
{
	int ch;
	char name[20];
	while(1)
	{
		cout<<"1.)Input for product\n2.)Input for employee\n3.)Exit\n";
		cout<<"Enter choice\n";
		cin>>ch;
		if(ch==1){
				get();
				ofstream x("ooo.txt");
 				x<<profit;
 				x.close();
			}
			else if(ch==2){
				getstaff();
				ofstream x("ooo.txt");
 				x<<profit;
 				x.close();
				}
			else if(ch==3)
				break;
			else
				cout<<"Invaid Option. Please re-enter\n";
			}
		}

 
	void amount::update_item()
	{
	char id[20];
	char pid[20];
    char c;
    cout<<"\nINPUT product ID to modify\n";
    cin>>id;
    char file[20];
    char file2[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
    if(!fout)
    {
    	cout<<"file couldn't be opened. product ID not found. \n";
	}
	else {
	cout<<"file found! \n";
    cout<<"\nupdate product name: \n";
  	cin>>name;
 	cout<<"\nupdate percost of product: \n";
  	cin>>percost;
 	cout<<"\nupdate persell of product: \n";
  	cin>>persell;
 	cout<<"\nupdate total product quantity: \n";
 	cin>>quan;
    cost=percost*quan;
    sell=persell*quan;
	profit=profit +(sell-cost)*365;
  	fout<<"\nproduct name: "<<name<< "\nproduct id: "<<id<<"\npercost ofproduct: " <<percost<<"\npersell of product: "<<persell<<"\nquantity: "<<quan<<"\n total cost: "<<cost<<"\nsell: "<<sell;
	fout.close();
}
}
   void amount::update_emp()	
	{
	char id[20];
    char c;
    cout<<"\nINPUT employee ID to modify: ";
    cin>>id;
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
     if(!fout)
    {								
    	cout<<"file couldn't be opened. product ID not found. \n";
	}
	cout<<"modify employee name: \n";
  	cin>>post;
  	fout<< "\nnumber of working employees: "<<postquan<< "\nemployee salary: "<<salary<< "\nemployee name :"<<post<<"\nemployee id: "<<empid;
 	fout.close();
}

void admin()
{
  while(1)
  {
 	cout<<"\n\t\t\t==============================\n";
	cout<<"\n\t\t\t     WELCOME TO THE SHOP  \n";
	cout<<"\n\t\t\t==============================\n\n";
	cout<<"\n\t\t\t* * * * * * * * * * * * * * * *\n";
 	cout<<"\n\t\t\t1. Add Entries\n\n\t\t\t2. Show profit\n\n\t\t\t3. Search Product Details\n\n\t\t\t4. Search Employee Details\n\n\t\t\t5. Modify Product Details\n\n\t\t\t6. Modify Employee Details\n\n\t\t\t7. Exit\n";
  cout<<"\n\n\t\t\tSelect your choice\n";
  int u;
  cin>>u;
if(u==1)
  {
  amount a;
  a.show();  // 21번줄 정의
  a.add();   // 133번줄 정의
}
  else if(u==2)
  {
  amount d;
  d.show();  // 21번줄 정의
}
  else if(u==3)
  {  
   char id[20];
   char c;
    cout<<"\nINPUT ID to search\n";
    cin>>id;
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    ifstream x(file);
    if(!x)
    {
    	cout<<"file couldn't be opened. product ID not found. \n";
	}
    while(x)
    {x.get(c);   //54번줄 정의
     cout<<c;
    }
    

    x.close();
}
   else if(u==4)
   {
   	char eid[20];
   	char d;
   	cout<<"\nINPUT employee ID to search\n";
    cin>>eid;
   	char file[20];
   	strcpy(file,eid);
   	strcat(file,".txt");
   	ifstream y(file);
   	 if(!y)
    {
    	cout<<"file couldn't be opened. employee ID not found. \n";
	}
   	while(y)
   	{
   	y.get(d);   //54번줄 정의
   	cout<<d;
   }
 
   y.close();
}
else if(u==5)
{
	amount u;
	u.update_item();  // 162번줄 정의
}
 else if(u==6)
 {
 	amount v;
 	v.update_emp();  // 195번줄 정의
 }
  else if(u==7)
  {
  break;
}
  else cout<<"Invalid option. Please select one of the available options\n";
 }

}

int main(){
    int ch;
    char  username[20];
    char password[20];
    char pwd[20];
    while(1){
        cout<<"\n \t\t\t=========================\n";
        cout<<"\n\t\t\tWELCOME TO MY SHOP  \n";
        cout<<"\n \t\t\t=========================\n\n";
        cout<<"\n \t\t\t* * * * * * * * * * * * ";
        cout<<"\n\t\t\t  1. ENTER SYSTEM";
        cout<<"\n\t\t\t  2. EXIT";
        cout<<"\n\t\t\t* * * * * * * * * * * *\n";
        cout<<"\n\t\t\t Enter Your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                admin(); // 215번줄에 정의
                break;
            case 2:
                exit(0);
                break;
            default:
                cout<<"Enter valid choice\n";
                break;
        }
    }
    return 0;
}


