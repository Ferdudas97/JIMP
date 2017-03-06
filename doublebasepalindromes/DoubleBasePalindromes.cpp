//
// Created by radek on 03.03.17.
//

#include "DoubleBasePalindromes.h"
#include <cstdint>
#include <string>
#include <iostream>

using namespace std;
uint64_t DoubleBasePalindromes(int max_vaule_exculsive) {
    
    uint64_t sum=0;
     int x,pal10, pal2;
    string str, str2;
    for (int i = 0; i <=max_vaule_exculsive; i++) {

        str = to_string(i);
        
        x = i;
        while (x != 0) {
            if (x % 2 == 1) str2 = "1" + str2;
            else str2 = "0" + str2;
            x=x/2;



        }
       

        for (int j = 0; j < str.length(); j++) {
            if (str[j] != str[str.length() - 1 - j]) {
                pal10 = 0;
                break;
                
            } else pal10 = 1;


        }
        for (int j = 0; j < str2.length(); j++) {
            if (str2[j] != str2[str2.length() - 1 - j]) {
                pal2 = 0;
                break;



            } else pal2 = 1;
        }
    str2="";
    if (pal2==1  and pal10==1) sum=sum+i;
    }
    return sum;
}