//
// Created by Radek on 17.04.2017.
//

#ifndef JIMP_EXERCISES_SHAPE_H
#define JIMP_EXERCISES_SHAPE_H

#include <iostream>
using namespace std;
class Ksztalt{
public:
    virtual void rysuj();
};
class Kolo:public Ksztalt{
    double r_,s_;
public:
    Kolo();
    virtual void rysuj()override ;
};
class Trojkat:public Ksztalt{
    double a_,b_,c_;
public:
    Trojkat();
    Trojkat(double a, double b, double c);
    virtual void rysuj()override ;
};
class Kwadrat:public Ksztalt{
    double a_;
public:
    Kwadrat();
    Kwadrat(double a);
    virtual void rysuj()override ;
};
#endif //JIMP_EXERCISES_SHAPE_H
