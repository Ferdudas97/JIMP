//
// Created by Radek on 14.04.2017.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H


#include <iostream>
#include <string>
#include <iomanip>
#include <strstream>
#include <istream>
#include <fstream>
class Point {
public:
    //Konstruktor bezparametrowy
    Point();
    //Konstruktor parametrowy
    Point(double x, double y);
    //Destruktor wykonywany przed zwolnieniem pamięci
    ~Point();

    //Metody nie modyfikujące stanu obiektu (const na końcu metody)
    //nie mogą zmodyfikować tego obiektu.
    void ToString(std::ostream *out) const;
    double Distance(const Point &other) const;


    double GetY() const;
    double GetX() const;

    //metody seterów pozwalające zmienić stan obiektu
    //po jego zainicjalizowaniu
    void SetX(double x);
    void SetY(double y);
    friend std::ostream &operator<<(std::ostream &is, Point &point);

private:
    //w przeciwienstwie do pythona C++ wymaga jawnej deklaracji składowych pól klasy:
    double x_, y_;
};
std::ostream &operator<<(std::ostream &is,Point &point);
class Point3D: public Point{
    double z_;
public:
    Point3D(double x, double y, double z);
    Point3D();
    ~Point3D();
    double GetZ() const ;
    double Distance(const Point3D &other) const ;
    void SetZ(double z);


};

#endif //JIMP_EXERCISES_POINT_H
