//
// Created by radek on 14.03.17.
//

#include "TinyUrl.h"
#include <iostream>

using namespace std;
namespace  tinyurl{

    std::unique_ptr<TinyUrlCodec> Init(){
        TinyUrlCodec url;

        unique_ptr<TinyUrlCodec> ptr=make_unique<TinyUrlCodec>(url);
        return ptr;
    }
    void NextHash(std::array<char, 6> *state){
        for(int i=5; i>-1;i--){
            int a=int((*state)[i]);
            if((a>47 and a<57) or (a>96 and a<122) or( a>65 and a<90)){
                (*state)[i]=char(a+1);
                i=-1;
            }
            if(a==57 or a==58){
                (*state)[i]=char(65);
                i=-1;
            }
            if(a==90 or a==91){
                (*state)[i]=char(97);
                i=-1;
            }
            if(a>=122){
                (*state)[i]='0';
                int b=int((*state)[i-1]);
                (*state)[i-1]=char(b+1);
                b=int((*state)[i-1]);
                if( b!=58  and b!=91 and b!=123){
                    i=-1;
                }
            }
        }

    }
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec)
    {
        string res="123456";
        for (int i = 0; i <6 ; ++i) {
            res[i]=(*codec)->state[i];

        }
        (*codec)->p[url]=res;
       (*codec)->p2[res]=url;
        NextHash(&(*codec)->state);
        return res;

    }
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash)
    {
        if(codec->p2.find(hash)!=codec->p2.end())return codec->p2[hash];
        else return "nie ma takiego adresu";

    }}
