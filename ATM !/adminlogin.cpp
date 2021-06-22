#include<iostream>
#include<conio.h>
#include<fstream>
#include"info.h"
int main(void)
{
    fstream f;
    char ch;
    getac g;
    f.open("adm.db",ios::out|ios::app|ios::binary);
    do
        {
         system("cls");
         g.admin() ;
         f.write((char*)&g,sizeof(g));
         cout<<"\n                                                         Add More Admin(y/n)..";
         cin>>ch;
    }
    while(ch=='y');
    f.close();
}
