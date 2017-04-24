//
// Created by Radek on 17.04.2017.
//
#include <list>
#include "Shape.h"
int main()
{
    list<Ksztalt*> list1{new Kwadrat,new Kolo, new Trojkat,new Trojkat, new Kolo,new Kwadrat};
    for(auto &n:list1)
    {
        n->rysuj();
    }
    return  0;
}