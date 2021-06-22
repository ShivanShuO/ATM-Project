/* To perform all operation that required at any atm */

#include"info.h"
#include<conio.h>
#include<iostream>
#include<fstream>
#include<ctime>
#include<windows.h>
#include<stdio.h>
#include<cstdlib>  //for clear screen in code blocks
using namespace std;
int main()
{
    int ch;
    getac g;
    fstream f1,f2;
    int acno,found=0,pss;
    system("COLOR fc");
     time_t now = time(0);
    char* dt = ctime(&now);
    f1.open("atm.db",ios::in|ios::binary); //Open File

    if(f1==NULL)
    {
        cout<<"file not found"<<endl;
    }
    else
    {
        system("cls");
        cout<<"            ||=========================================================================================||\n";
        cout<<"            ||+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++||\n";
        cout<<"            ||                                                                                         ||\n";
        cout<<"            ||                                       WELCOME TO ATM!                                   ||\n";
        cout<<"            ||                                                                                         ||\n";
        cout<<"            ||                                                                                         ||\n";
        cout<<"            ||                                                                                         ||\n";
        cout<<"            ||                                                                                         ||\n";
        cout<<"            ||                                                                                         ||\n";
        cout<<"            ||                                                                                         ||\n";
        cout<<"            ||                                                                                         ||\n";
        cout<<"            ||                                                                                         ||\n";
        cout<<"            ||                                                                                         ||\n";
        cout<<"            ||                                                                          by shivanshu   ||\n";
        cout<<"            ||+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++||\n";
        cout<<"            ||=========================================================================================||\n";
        system("pause");
    system("cls");
    cout<<"=======================================================================================================================";
    cout<<"                                                  Enter Account Number..";cin>>acno;
    cout<<"=======================================================================================================================";
    cout<<"\n                                                 Enter Password..";cin>>pss;
    cout<<"=======================================================================================================================\n";
{
       cout<<"loading Please Wait...  ";
       for(int i=0;i<=4;i++)
        {
        Sleep(100);
        cout<<"\b-"<<flush;
        Sleep(100);
        cout<<"\b\\"<<flush;
        Sleep(100);
        cout<<"\b|"<<flush;
        Sleep(100);
        cout<<"\b/"<<flush;
       }
}
    while(!f1.eof())
    {
        f1.read((char *)&g,sizeof(g));
        if(f1.eof())
        {
       break;
        }
    found = g.search(acno,pss); //Search Account
    if(found)
    {
        Sleep(2000);
        break;

    }
    }
    f1.close();
    if(found)
    {

    do {

            f1.open("atm.db",ios::in|ios::binary);
            f2.open("temp.db",ios::out|ios::app|ios::binary);
       system("cls");
       Sleep(300);
       g.show();
   cout<<"\n========================================================================================================================";
   cout<<"\n                                1 >> Deposit                             2 >> Withdraw    ";
   cout<<"\n                                3 >> Balance                             4 >> Statement    ";
   cout<<"\n                                                         5 >> Exit";
   cout<<"\n                                                                                        "<<dt;
   cout<<"\n                                                                 "; cin>>ch;
   cout<<"\n======================================================================================================================\n";
   switch(ch)
   {
   case 1: //Deposit
       system("cls");
       Sleep(300);

     while(!f1.eof())
    {
        f1.read((char *)&g,sizeof(g));
        if(f1.eof())
        {
       break;
        }
    found=g.search(acno,pss);
    if(found)
    {
     g.deposit();}

   f2.write((char *)&g,sizeof(g));
   }
   f1.close();
   f2.close();
   remove("atm.db");
   rename("temp.db","atm.db");
     break;
   case 2:    //Withdraw
       system("cls");
       Sleep(300);
     while(!f1.eof())
    {
        f1.read((char *)&g,sizeof(g));
        if(f1.eof())
        {
       break;
        }
    found=g.search(acno,pss);
    if(found)
    {
     g.withdraw();}

   f2.write((char *)&g,sizeof(g));
   }
   f1.close();
   f2.close();
   remove("atm.db");
   rename("temp.db","atm.db");
    break;
    case 3:   //Balance
         system("cls");
         Sleep(300);
     while(!f1.eof())
    {
        f1.read((char *)&g,sizeof(g));
        if(f1.eof())
        {
       break;
        }
    found=g.search(acno,pss);
    if(found)
    {
     g.bal();
     Sleep(2000);}

   f2.write((char *)&g,sizeof(g));
   }
   f1.close();
   f2.close();
   remove("atm.db");
   rename("temp.db","atm.db");
  break;
    case 4:  //Statement
              system("cls");
              Sleep(100);
     while(!f1.eof())
    {
        f1.read((char *)&g,sizeof(g));
        if(f1.eof())
        {
       break;
        }
    found=g.search(acno,pss);
    if(found)
    {
     g.passbook();
     Sleep(4000);}
   }
   f1.close();
   f2.close();
   break;
   case 5:  //Exit
       system("cls");
     cout<<"\n\n\t\t\t\t\t\t --____-- Have A Nice Day --____-- \n\n\n";
     break;
   }
}

while(ch!=5);

    }
    else
    {
        cout<<" \n         |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
        cout<<"         |                                                                                           |\n";
        cout<<"         |                                         Invalid Account \a\a\a\a                              |\n";
        cout<<"         |                                                                                           |\n";
        cout<<"         |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|";
    }
    }
}


