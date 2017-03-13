//
// Created by radek on 07.03.17.
//

#include <fstream>
#include "Polybius.h"

int main(int argc, char **argv)
{
    ifstream myfile(argv[1]);
    string word;
    string crypted;

    if(!myfile)
        cout << "Nie można otworzyć pliku!";

    while(myfile >> word)

        myfile.close();

    if(argv[3] == (char *) 1){
        crypted=PolybiusCrypt(word);
    }
    else{
        crypted=PolybiusDecrypt(word);
    }
    ofstream myfile1 (argv[2], ios_base::in | ios_base::app);
    if(!myfile1) cout << "Nie można otworzyć pliku!";

    myfile1 << crypted;

    myfile1.close();

}