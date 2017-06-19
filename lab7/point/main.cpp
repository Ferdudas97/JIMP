//
// Created by Radek on 14.04.2017.
//

#include <iostream>
#include <ostream>
#include "Point.h"
using namespace std;

int main()
{
    Point3D punkt3d(1,10,5);
    Point punkt2d(2,6);
    cout<<punkt2d.Distance(punkt3d);
    Point3D p3d(1,2,3);
    cout<<punkt2d<<endl;
    cout<<p3d<<endl;
    //zadanie 5
    //pierwszy wywoływane jest konstruktor klasy bazowej 2d
    //drugi wywoływany jest konstruktor klasy pochodnej 3d
    //w przypadku dekonstruktorów pierwszy wywoływany jest dla klasy pochodnej, później dla klasy bazowej
    // zadanie 6
    // zwraca odleglosc miedzy punktami punkt2d i wspołrzednymi x i y punkt3d(ktory jest rzutowany na klase bazowa Point)
    //zadanie 7
    //ponieważ klasa Point3D nie ma przeciążonego operatora <<
    //dlatego zostanie wywołany operator klazsy bazowej

    return 0;
}