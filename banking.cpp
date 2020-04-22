#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>

using namespace std;

class banking{
    char name[20];
    long accountno;
    char phoneno[20];
    char pin[10];
    int balance,initialbal=0;
    char accounttype[20];
public:
    banking(){
    accountno=1001054355;
    }
    void getdata();
    void getmdata();
    void showall();
    void showdata();
    void check_balance();
    void modify();
    void assignaccountno();
    int adddeposit(int);
    int withdraw(int);
    char *getname(){return name;}
    char *getpin(){return pin;}
};
void banking::getdata()
{
    cout<<"Enter name of the Account holder : ";
    cin>>name;cout<<endl;
    cout<<"Enter contact no. of the Account holder : ";
    cin>>phoneno;
    int x=strlen(phoneno);
    while (x!=10)
    {       cout<<endl;
            cout<<"Enter Valid Phone no : ";
            cin>>phoneno;
            x=strlen(phoneno);
    }cout<<endl;
    cout<<"Enter Pin of 4 digits for your Account you want to Set : ";
    cin>>pin;
     int y=strlen(pin);
    while (y!=4)
    {       cout<<endl;
            cout<<"Enter Valid Pin : ";
            cin>>pin;
            y=strlen(pin);
    }cout<<endl;
    cout<<"Select the Type of Account You want to open (Current/Savings)"<<endl;
    cout<<"\t \t \t \t \t \t 1.Current"<<endl;
    cout<<"\t \t \t \t \t \t 2.Savings"<<endl;
    int a;
    cin>>a;
    if(a==1)
    strcpy(accounttype,"Current");
    else if(a==2)
    strcpy(accounttype,"Savings");
    else
    cout<<"Enter valid Choice";
    cout<<"Enter the initial deposit amount you want to give (min rs500)";
    cin>>initialbal;
    if(initialbal<500)
    {   cout<<"Enter amount greater Than minimum limit";
        cin>>initialbal;
    }
    balance=initialbal;
    cout<<endl;
    cout<<endl;

    cout<<"\t \t \t \t \t Congratulations your account has been Created";
}
void banking::getmdata()
{     char ch;

do{

    system("cls");
    cout<<endl<<endl;
    cout<<"\t \t \t \t \t Select the option you want to Change "<<endl;
    cout<<"\t \t \t \t 1.Change Name";
    cout<<endl<<endl;
    cout<<"\t \t \t \t 2.Change Phoneno";
    cout<<endl<<endl;
    cout<<"\t \t \t \t 3.Change Pin";
    cout<<endl<<endl;
    cout<<"\t \t \t \t 4.Change Account Type";
    cout<<endl<<endl;
    cout<<"\t \t \t \t 5.Exit to main menu";
    cout<<endl<<endl;
    cout<<"\t \t \t \t Enter your choice(1-4) : ";
    ch=getch();


    switch(ch)
    {
        case '1':   system("cls");
                    cout<<"Enter new name of the Account holder : ";
                    cin>>name;
                    cout<<endl;
                    getch();
                    break;
        case '2':   {
                    system("cls");
                    cout<<"Enter new contact no. of the Account holder : ";
                    cin>>phoneno;
                    int x=strlen(phoneno);
                    while (x!=10)
                    {        cout<<endl;
                            cout<<"Enter Valid Phone no : ";
                            cin>>phoneno;
                            x=strlen(phoneno);
                    }
                    cout<<endl;
                    }getch();
                    break;
         case '3':  {
                    system("cls");
                    cout<<"Enter  New Pin of 4 digits for your Account you want to Set : ";
                    cin>>pin;
                    int y=strlen(pin);
                    while (y!=4)
                    {
                        cout<<endl;
                        cout<<"Enter Valid Pin : ";
                        cin>>pin;
                        y=strlen(pin);
                    }
                    cout<<endl;
                    }getch();
                    break;
         case '4':  {
                    system("cls");
                    cout<<"Change the Type of Your Account(Current/Savings)"<<endl;
                    cout<<"\t \t \t \t \t \t 1.Current"<<endl;
                    cout<<"\t \t \t \t \t \t 2.Savings"<<endl;
                    int a;
                    cin>>a;
                    if(a==1)
                    strcpy(accounttype,"Current");
                    else if(a==2)
                    strcpy(accounttype,"Savings");
                    else
                    cout<<"Enter valid Choice";
                    cout<<endl;
                    }
                    getch();
                    break;
         case '5' : break;
         default : cout<<"Enter Valid Choice";
                    break;
    }
    if(ch!='5')
    cout<<"\t \t \t \t \t Congratulations your account details have been Updated";

}while(ch=='4');

}
void banking::check_balance()
{
    cout<<balance;
}
void banking::showall()
{
cout<<"\n" ;
	cout<<"Name: "<<name<<endl;
	cout<<"Phoneno:  "<<phoneno<<endl;
	cout<<"Accounttype: "<<accounttype<<endl;
}
void banking::showdata()
{
cout<<"\n" ;
	cout<<"Name: "<<name<<endl;
	cout<<"Phoneno:  "<<phoneno<<endl;
	cout<<"Accountno: "<<accountno<<endl;
	cout<<"Accounttype: "<<accounttype<<endl;
	cout<<"Account Balance :"<<balance<<endl;
}
banking b;
fstream fp;
void write_account()
{

    fp.open("Accountdetails.txt",ios::app);
        b.getdata();
        b.assignaccountno();
        fp.write((char*)&b,sizeof(b));
        fp.close();

}
void accountdetails()
{
            char nm[30];
            char pinn[10];
            int found =0;
            cout<<"Enter Name of the Account Holder  :";
            cin>>nm;
            cout<<endl;
            cout<<"Enter Pin  :";
            cin>>pinn;
            fp.open("Accountdetails.txt",ios::in);
            while(fp.read((char*)&b,sizeof(b)))
            {
                if(strcmp(b.getname(),nm)==0)
                {    found++;
                    cout<<"The Account You Searched For is :"<<endl;
                    b.showdata();
                }
            }
            if(found==0)
            cout<<endl<<"No Account Found with these Credentials";
            fp.close();
}
void showaccounts()
{
fp.open("Accountdetails.txt",ios::in);
        while(fp.read((char*)&b,sizeof(b)))
        {
            b.showall();
            cout<<"\n\n====================================\n";
            getch();
        }
        fp.close();
}
void banking::assignaccountno()
{
      accountno++;
}
int banking::adddeposit(int deposit)
{
    balance=balance+deposit;
}
int banking::withdraw(int money)
{
    balance=balance-money;
}
void changedetails()
{   int found =0;
    char nm[30],pinn[10];
    cout<<"Enter Name of the account holder :";
    cin>>nm;
    cout<<"Enter Pin :";
    cin>>pinn;
    fp.open("Accountdetails.txt",ios::in|ios::out);
    while(fp.read((char*)&b,sizeof(b)))
    {
    if(strcmp(b.getname(),nm)==0)
    {
        if(strcmp(b.getpin(),pinn)==0)
            {   found++;
                b.showdata();
                getch();
                cout<<endl;
                b.getmdata();
                int pos=-1*sizeof(b);
                fp.seekp(pos,ios::cur);
                fp.write((char*)&b,sizeof(b));
            }

    }


}
if(found==0)
cout<<endl<<"No Account Found with these Credentials";
fp.close();


}

void transact()
{           int deposit,money,option,found=0;
            cout<<"\t \t \t \t \t \t Enter your Choice :(Deposit/Withdraw)"<<endl;
            cout<<"\t \t \t \t \t 1.Deposit"<<endl;
            cout<<"\t \t \t \t \t 2.Withdraw"<<endl;
            cout<<"\t \t \t \t \t 3.Exit to MAin Menu"<<endl;
            cin>>option;
            cout<<endl;
            if(option ==3)
             return;
            if(option==1)
            {
                char nm[30];
                char pinn[10];
                cout<<"Enter Name of the Account Holder  :";
                cin>>nm;
                cout<<endl;
                cout<<"Enter Pin  :";
                cin>>pinn;
                cout<<endl;
                fp.open("Accountdetails.txt",ios::in|ios::out);
                    while(fp.read((char*)&b,sizeof(b)))
                        {
                        if(strcmp(b.getname(),nm)==0)
                            {
                            if(strcmp(b.getpin(),pinn)==0)
                                {
                             found++;
                    cout<<"Enter the amount to be Deposited :";
                    cin>>deposit;
                    b.adddeposit(deposit);
                    int pos=-1*sizeof(b);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&b,sizeof(b));
                    cout<<"Your account Balance is: ";
                    b.check_balance();

                    }
                            }
                        }
                    }
            if(option==2)
                {
                char nm[30];
                char pinn[10];
                cout<<"Enter Name of the Account Holder  :";
                cin>>nm;
                cout<<endl;
                cout<<"Enter Pin  :";
                cin>>pinn;
                cout<<endl;
                fp.open("Accountdetails.txt",ios::in|ios::out);
                while(fp.read((char*)&b,sizeof(b)))
                    {
                    if(strcmp(b.getname(),nm)==0)
                        {
                        if(strcmp(b.getpin(),pinn)==0)
                        {
                         found++;
                    cout<<"Enter the amount to be Withdrawn :";
                    cin>>money;
                    b.withdraw(money);
                    int pos=-1*sizeof(b);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&b,sizeof(b));
                    cout<<"Your account Balance is: ";
                    b.check_balance();
                    }

                      }
                }
            }
            if(found==0)
            cout<<endl<<"No Account Found with these Credentials";
            fp.close();
}
void closeaccount()
{
     int found =0;
     char confirm ='n';
     fstream fp2;
     fp2.open("Temp.txt",ios::in|ios::out|ios::app);
     char nm[30];
     char pinn[10];
    cout<<"Enter Name of the Account Holder  :";
    cin>>nm;
    cout<<endl;
    cout<<"Enter Pin  :";
    cin>>pinn;
    cout<<endl;
    fp.open("Accountdetails.txt",ios::in|ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&b,sizeof(b)))
        {
            if(strcmp(b.getname(),nm)==0)
                {
                    if(strcmp(b.getpin(),pinn)==0)
                        {     cout<<endl;
                              b.showdata();
                              found=1;
                              cout<<endl<<"Are you Sure you want to Delete your account (y/n) :";
                              cin>>confirm;
                              if(confirm =='n')
                            {
                                fp2.write((char*)&b,sizeof(b));
                                cout<<endl<<"Account Still Open ";
                            }
                        }
                }
              else
              fp2.write((char*)&b,sizeof(b));
        }
    if(confirm =='y')
    cout<<endl<<"Account Deleted..";
    fp.close();
    fp2.close();
    remove("Accountdetails.txt");
    rename("Temp.txt","Accountdetails.txt");
    if(found==0)
    cout<<endl<<"No Account Found With these Credentials";
    getch();
}

void menu()
{

    char ch;
    do
    {
        system("cls");
        cout<<endl<<endl<<endl<<endl;
 cout<<"\t \t \t \t \t \t Banking System";
 cout<<endl<<endl;
 cout<<"\t \t \t \t \t 1.Open Account";
 cout<<endl<<endl;
 cout<<"\t \t \t \t \t 2.See All Accounts";
 cout<<endl<<endl;
 cout<<"\t \t \t \t \t 3.Account Details";
 cout<<endl<<endl;
 cout<<"\t \t \t \t \t 4.Deposit Money/Withdraw Money";
 cout<<endl<<endl;
 cout<<"\t \t \t \t \t 5.Change Details";
 cout<<endl<<endl;
 cout<<"\t \t \t \t \t 6.Close Account";
 cout<<endl<<endl;
 cout<<"\t \t \t \t \t 7.Exit";
 cout<<endl<<endl;
 cout<<"\t \t \t \t \t Enter your choice(1-7) : ";

    ch=getch();

 switch (ch){

            case '1':system("cls");
            write_account();
            getch();
            break;

            case '2': system("cls");
            showaccounts();
            getch();
            break;

            case '3':system("cls");
            accountdetails();
            getch();
            break;

            case '4': system("cls");
            transact();
            getch();
            break;

            case '5': system("cls");
            changedetails();
            getch();
            break;

            case '6': system("cls");
            closeaccount();
            getch();
            break;

            case '7': system("cls");
            exit(0);
            default:cout<<"ENTER VALID CHOICE";
            system("cls");
            }

}
while(ch!='7');
}
int main()
{
   menu();
   return 0;
}
