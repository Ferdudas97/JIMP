//
// Created by radek on 08.03.17.
//

#include "GreatestProduct.h"



using namespace std;

int GreatestProduct(const vector<int> &numbers, int k)
{

    int *tab= new int [k];
    int *tab2= new int [k];
    int *tab3= new int [k];
    int maxint=0;
    int tmp,il1=1,il2=1,il3=1,il4=1;
    int minuslb=0;
    for (int j = 0; j <k ; j++) {
        tab[j]=INT_MIN;
        tab2[j]=0;
        tab3[j]=INT_MAX;
    }


    for (int i=0;i<numbers.size();i++) {
        if (tab[0]<numbers[i]) tab[0]=numbers[i];
        if (tab3[k-1]>numbers[i]) tab3[k-1]=numbers[i];
        for (int j = 0; j <k ; j++) {
            for (int l = 0; l <k-1 ; l++) {
                if (tab[l]>tab[l+1])
                {
                    tmp=tab[l];
                    tab[l]=tab[l+1];
                    tab[l+1]=tmp;
                }
                if (tab3[l]>tab3[l+1])
                {
                    tmp=tab3[l];
                    tab3[l]=tab3[l+1];
                    tab3[l+1]=tmp;
                }
            }
        }
    }
    for (int j = 0; j <k ; j++) {
        il1=il1*tab[j];
        il3=il3*tab3[j];
    }
        for (int m = 0; m < (k / 2) * 2; m = m + 2) {
            if (tab3[m] * tab3[m + 1] >= tab[maxint] * tab[maxint + 1])
            {tmp = tab3[m] * tab3[m + 1];
                maxint+=2;}
            for (int i = m + 2; i < k; ++i) {
                tmp = tmp * tab[i];
            }
            il4 = tmp;
        }


    for (int n = 0; n <k ; n++) {
        if(tab3[n]<0) minuslb++;

    }
    delete(tab);
    delete(tab2);
    delete(tab3);
    if (il1>il4) return il1;

    return  il4;}
