//
// Created by radek on 11.03.17.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using  namespace std;

int Xor(char ch,char key);
string XorCypherBreaker(const vector<char> &cryptogram,
                             int key_length,
                             const vector<string> &dictionary);

#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
