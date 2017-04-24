//
// Created by Radek on 17.04.2017.
//

#include "Shape.h"

Kolo::Kolo() {

}
void Kolo::rysuj() {
    cout<<"O"<<endl;
}
Kwadrat::Kwadrat() {}
void Kwadrat::rysuj() {
    string tmp="@",tmp1="@",tmp2="@";
    for (int i = 0; i <4;i++) {
        tmp+=" ";
        tmp1+="@";
        tmp2+="@";
    }
    tmp+="@";
    tmp1+="@";
    tmp2+="@";
    cout<<tmp1<<endl;
    for (int i = 0; i <4 ;i++) {
        cout<<tmp<<endl;
    }
    cout<<tmp2<<endl;

}
Trojkat::Trojkat() {}
void Trojkat::rysuj() {
    cout << "  # " << endl;
    cout << " ###" << endl;
    cout << "#####" << endl;
}

void Ksztalt::rysuj() {
    cout<<"rysuje"<<endl;
}