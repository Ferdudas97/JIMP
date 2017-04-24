//
// Created by Radek on 14.04.2017.
//

#include <cmath>
#include <ostream>
#include <iostream>
//#include <istream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora
Point::Point():x_(0),y_(0){
    std::cout << "Konstruktor bezparametrowy" << endl;
}

Point::Point(double x, double y){
    std::cout<< "Konstruktor parametrowy" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point(){
    std::cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
    std::cout << endl;
}
double Point::GetY() const {
    return y_;
}
double Point::GetX() const {
    return x_;
}

double Point::Distance(const Point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

void Point::ToString(ostream *out) const{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}
void Point::SetX(double x) {
    x_=x;
}
void Point::SetY(double y) {
    y_=y;
}
double Point3D::GetZ() const {
    return z_;
}
Point3D::Point3D(double x, double y, double z) : Point(x,y) {
    z_= z;
}
double Point3D::Distance(const Point3D &other) const {
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2) +pow(GetZ()-other.GetZ(),2));
}
void Point3D::SetZ(double z) {
    z_=z;
}
Point3D::~Point3D() {
   std:: cout<<"point3d usuwam"<<endl;
}
Point3D::Point3D()
{

}
std::ostream &operator<<(std::ostream &is,Point &point)
{
    is<<point.x_;
    is<<",";
    is<<point.y_;
}
