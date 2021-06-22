/* Header file to include as required to open and read account and search also*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
   class getac
{
 protected:
   char name[30],adder[70];
   int acno,pss,amt,pass,id;
   long balance;
   int cbal=0,tbal=0,wbal=0,dbal=0;
public:
   void openaccount()
{
 cout<<"\n Enter Account Number..";
 cin>>acno;
 cout<<"\n Enter Name..";
 fflush(stdin);
 gets(name);
 cout<<"\n Enter Address..";
 gets(adder);
 cout<<"\n Enter Balance..";
 cin>>balance;
 cout<<"\n Enter Password You Want To Choose..";
 cin>>pss;
}
 void bal()
 {
     cout<<"\n========================================================================================================================";
     cout<<"\n                                                            Balance.."<<balance<<endl;
     cout<<endl;
 }
  void show()
{
    cout<<"\n======================================================================================================================";
    cout<<"\n                                                            WELCOME \n";
    cout<<"                                                          "<<name<<endl;
    cout<<"========================================================================================================================\n";
}
 void update()
 {
 cout<<"\n Enter Account Number..";
 cin>>acno;
 cout<<"\n Enter Name..";
 gets(name);
 cout<<"\n Enter Address..";
 gets(adder);

 }
  void showaccount()
{
 cout<<"\n Account Number.."<<acno;
 cout<<"\n Name.."<<name;
 cout<<"\n Address.."<<adder;
 cout<<"\n Balance.."<<balance<<endl;
}
void deposit()
{
    system("cls");
    int amt;
    cbal=balance;
    cout<<"=======================================================================================================================";
    cout<<"                                                    Current Balance.."<<cbal<<endl;
    cout<<"=======================================================================================================================";
    cout<<"                                                    Enter Amount To Deposit..";cin>>amt;
    balance=balance+amt;
    system("cls");
    dbal=amt;
    cout<<"=======================================================================================================================";
    cout<<"                                                        Amount Deposit.."<<dbal<<endl;
    cout<<"=======================================================================================================================";
    tbal=balance;
    cout<<"                                                        Total Balance.."<<tbal;
    Sleep(1500);
}
void withdraw()
{
    system("cls");
    int amt;

    cbal=balance;
    cout<<"=======================================================================================================================";
    cout<<"                                                     Current Balance.."<<cbal<<endl;
    cout<<"=======================================================================================================================";
    cout<<"                                                    Enter Amount To Withdraw..";cin>>amt;
    if(balance>amt)
{

    wbal=amt;
balance=balance-amt;
system("cls");
cout<<"=======================================================================================================================";
cout<<"                                                         Amount Withdraw.."<<amt<<endl;
cout<<"=======================================================================================================================";

 tbal=balance;
cout<<"                                                         Total Balance.."<<tbal;
Sleep(1500);
    }
    else{
        cout<<"=======================================================================================================================";
        cout<<"                                                        Insufficient Balance..";
        Sleep(1500);
    }
}
void passbook()
{
     time_t now = time(0);
    char* dt = ctime(&now);
    cout<<" Balance.."<<cbal<<endl;
    cout<<" Deposit.."<<dbal<<endl;
    cout<<" Withdraw.."<<wbal<<endl;
    cout<<" Total Balance.."<<tbal<<endl;
    cout<<dt;
}
void admin()
{
    cout<<"Enter Admin Id..";
    cin>>id;
    cout<<"Enter Admin password..";
    cin>>pass;
}
int search(int acno,int pss)
{
if(this -> acno==acno && this -> pss==pss)
            {
                show();
         return(1);
     }
     else
     {
        return(0);
     }
}
int em(int id,int pass)
{
if(this -> id==id && this -> pass==pass)
            {

         return(1);
     }
     else
     {
        return(0);
     }
}

};





