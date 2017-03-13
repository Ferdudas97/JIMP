//
// Created by radek on 11.03.17.
//
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
int Xor(char ch,char key)
{
    int asci,it=7;
    int tab[8],tabkey[8],res[8];
    asci=int(ch);
    for(int i=0;i<8;i++)
    {
        tabkey[i]=0;
        tab[i]=0;
    }

    while(asci>0)
    {
        tab[it]=asci%2;
        asci=asci/2;
        it--;
    }
    it=7;
    asci=int(key);
    while(asci>0)
    {
        tabkey[it]=asci%2;
        asci=asci/2;
        it--;
    }
    for(int i=0;i<8;i++)
    {
        if (tab[i]!=tabkey[i]) res[i]=1;
        else res[i]=0;
    }
    int liczba=0;
    for(int i=0; i<8;i++){
        liczba=liczba+res[i]*pow(2,(7-i));
         cout<<tabkey[i]<<endl;
    }
    //cout<<tab<<endl;
    //  cout<<tabkey<<endl;

    // cout<<liczba<<endl;
    return liczba;

}
int main()
{

}