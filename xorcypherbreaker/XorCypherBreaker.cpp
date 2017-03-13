//
// Created by radek on 11.03.17.
//
#include "XorCypherBreaker.h"
#include <string>
#include <vector>
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
    }
    return liczba;
}
string XorCypherBreaker(const vector<char> &cryptogram,
                             int key_length,
                             const vector<string> &dictionary)
{

    string key="abc";
    int words=0;
    int sig;
    string wysz;
    string encrypted;
        for (int j = 97; j <123 ; j++) {
            for (int k = 97; k <123 ; k++) {
                {
                    for (int l = 97; l <123 ; l++) {
                        for (int i = 0; i <cryptogram.size() ; i++) {
                            key[0]=char(j);
                            key[1]=char(k);
                            key[2]=char(l);
                            sig=Xor(cryptogram[i],key[i%3]);
                            encrypted+=char(sig);
                        }
                        for (int i = 0; i <dictionary.size() ; i++) {
                            wysz=" "+dictionary[i]+" ";
                        if (encrypted.find(wysz)<=encrypted.size()) words++;
                        wysz.clear();
                        }
                        if (words>6){
                            return key;
                            }
                        encrypted.clear();
                            words=0;
                    }
                }
            }
        }
    return key;
}

