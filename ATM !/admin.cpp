/***********************Admin Page**********************/
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
#include"info.h"
#include<cstdlib>
#include<fstream>
using namespace std;
int main(void)
{ fstream f3;
getac g;
      int s,id,pass,found=0;
     time_t now = time(0);
    char* dt = ctime(&now);
    system("cls");
    system("COLOR fc");
        f3.open("adm.db",ios::in|ios::binary);  //Admin File

    if(f3==NULL)
    {
        cout<<"file not found"<<endl;
    }
    else
    {
        cout<<"Enter Admin Id..";
        cin>>id;
        cout<<"Enter Admin password..";
        cin>>pass;

            while(!f3.eof())
    {
        f3.read((char *)&g,sizeof(g));
        if(f3.eof())
        {
       break;
        }
    found = g.em(id,pass);
    if(found)
    {
        cout<<"LOADING PLEASE WAIT...";
        for(int i=0;i<=7;i++)
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
        break;

    }
    }
    f3.close();
    if(found)
    {
 do{
  system("cls");
  cout<<"\t           1 >> Open Account                                           2 >> Read all account Info\n";
  cout<<"\t           3 >> Update Account                                         4 >> Delete Account\n";
  cout<<"                                                        5 >> Exit \n";
  cout<<dt;
  cout<<"                                                           ";cin>>s;
  switch(s)
  {
case 1: //Open Account
          {
                  fstream f;
    char ch;
    getac g;
    f.open("atm.db",ios::out|ios::app|ios::binary);
    do
        {
         system("cls");
         g.openaccount();
         f.write((char*)&g,sizeof(g));
         cout<<"\n                                                         Add More Account(y/n)..";
         cin>>ch;
    }
    while(ch=='y');
    f.close();
    break;
          }

case 2:  //Read All

      {
           fstream f1;
 getac g;
 f1.open("atm.db",ios::in|ios::binary);
 if(f1==NULL)
 {
     cout<<"file not found"<<endl;
 }
 else
 {
     while(!f1.eof())
     {
         f1.read((char *)&g,sizeof(g));
         if(f1.eof())
         {
             break;
         }
         g.showaccount(); //at info
     }
     system("pause");
 }
 f1.close();
 break;
      }
case 3:  //Update Account
    {
          int ch;
    getac g;
    fstream f1,f2;
    int acno,found=0,pss;
    f1.open("atm.db",ios::in|ios::binary);

    if(f1==NULL)
    {
        cout<<"file not found"<<endl;
    }
    else
    {
        system("cls");

    cout<<"                                                     Enter Account Number..";cin>>acno;
    cout<<"\n                                                     Enter Password..";cin>>pss;

    while(!f1.eof())
    {
        f1.read((char *)&g,sizeof(g));
        if(f1.eof())
        {
       break;
        }
    found = g.search(acno,pss);
    if(found)
    {
        Sleep(2000);
        break;

    }
    }
    f1.close();
    if(found)
    {

            f1.open("atm.db",ios::in|ios::binary);
            f2.open("temp.db",ios::out|ios::binary);
       system("cls");

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
        system("cls");
     g.showaccount();
     Sleep(2000);
     g.openaccount();
     }

   f2.write((char *)&g,sizeof(g));
   }
   f1.close();
   f2.close();
   remove("atm.db");
   rename("temp.db","atm.db");
   }
   else
      cout<<"                                                            Account Not Found";
    }
    }

break;
case 4: // Delete Account
    {
          int ch;
    getac g;
    fstream f1,f2;
    int acno,found=0,pss;
    f1.open("atm.db",ios::in|ios::binary);
    if(f1==NULL)
    {
        cout<<"file not found"<<endl;
    }
    else
    {
        system("cls");

    cout<<"                                              Enter Account Number Do You Want To Delete..";cin>>acno;
    cout<<"                                              Enter Password..";cin>>pss;
           while(!f1.eof())
    {
        f1.read((char *)&g,sizeof(g));
        if(f1.eof())
        {
       break;
        }
    found = g.search(acno,pss);
    if(found)
    {
        break;

    }
    }
    f1.close();
    if(found)
    {

            f1.open("atm.db",ios::in|ios::binary);
            f2.open("temp.db",ios::out|ios::binary);
       system("cls");

     while(!f1.eof())
    {
        f1.read((char *)&g,sizeof(g));
        if(f1.eof())
        {
       break;
        }
    found=g.search(acno,pss);
     cout<<"                                                                       Account Deleted";
    Sleep(2000);
    if(!found)
   f2.write((char *)&g,sizeof(g));
   }
   f1.close();
   f2.close();
   remove("atm.db");
   rename("temp.db","atm.db");
   }
   else
      cout<<"                                                                      Account Not Found";
    }
    }
break;
case 5:

          system("cls");
          cout<<"                                                                     Welcome Back";
          break;
  }
 }
while(s!=5);
}
if(!found)
{
    cout<<"Invalid User";
}
}
}
