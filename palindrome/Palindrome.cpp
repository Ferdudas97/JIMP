//
// Created by radek on 03.03.17.
//

#include "Palindrome.h"
#include <string>
bool is_palindrome(std::string str)
{

    for (int i = 0; i <str.length() ;i++) {
        if (str[i]!=str[str.length()-1-i]) return false;

    }
    return  true;
}