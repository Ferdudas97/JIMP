//
// Created by radek on 07.03.17.
//

    #include "Polybius.h"





string PolybiusCrypt(string message) {
    map<char, string> v;
        unsigned long siz = message.length();
        string tmp;
    int ch=97;
        map<char , string>::iterator it;
    for (int i=0;i<siz;i++)
    {
        if(int(message[i])>=65 and int(message[i])<=90 ){
            message[i]=char(int(message[i])+32);
        }}


    for(int i=1;i<=5;i++) {
        for (int j = 1; j <= 5; j++) {
            if (ch != 106) {
                v[char(ch)]= to_string(10 * i + j);
                ch++;
            } else {
                v[char(ch)] =to_string(24);
                ch++;
                j--;
            }

        }
    }

        for (int i = 0; i <siz ; i++) {


            for (it = v.begin(); it != v.end(); ++it) {

                if (it->first == message[i])
                { tmp +=it->second;


                }
            }}


        return tmp;

    }
    string PolybiusDecrypt(string crypted){
        map<char, string> v;
        unsigned long siz = crypted.length();
        string tmp="aa";
        string encrypted;
        int ch =97;
        string res;

        map<char , string>::iterator it;
        for(int i=1;i<=5;i++) {
            for (int j = 1; j <= 5; j++) {
                if (ch != 106) {
                    v[char(ch)]= to_string(10 * i + j);
                    ch++;
                } else {
                    v[char(ch)] =to_string(24);
                    ch++;
                    j--;
                }

            }
        }

        for (int i = 0; i <siz ; i=i+2) {
            tmp[0]=crypted[i];
            tmp[1]= crypted[i+1];


            for (it = v.begin(); it != v.end(); ++it) {

                if (it->second == tmp) {

                    encrypted +=it->first;
                    if (it->second=="24") it++;
                }
            }

        }
        return  encrypted ;



    }

