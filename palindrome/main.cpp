//
// Created by radek on 03.03.17.
//
#include "Palindrome.h"
#include <iostream>
using namespace std;
int main()
{
    int option;
    string word;
    bool end=false,palin;
    while (end!=true)
    {
        cout<<"1.Sprawdz czy jest palindromem\n 2.Wyjscie\n";
        cin>>option;
        if (option==1)
        {
            cout<<"podaj słowo"<<endl;
            cin>>word;
            palin=is_palindrome(word);
            if (palin==false) cout<<"nie jest palindromem\n";
            else cout<<"jest palindormem\n";
        }
        else end=1;
    }
    return 0;
}
