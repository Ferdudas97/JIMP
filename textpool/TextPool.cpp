//
// Created by radek on 29.03.17.
//

#include <iostream>
#include "TextPool.h"

namespace pool {
    TextPool::TextPool() {

    }

    TextPool::TextPool(initializer_list<string> initstr) {
        for (const string &n :initstr) {
            if (set1.find(n) != set1.end()) {}
            else {
                set1.emplace(n);
            }
        }
    }

/*    TextPool::TextPool(const TextPool &other) {
         set1.operator=(other.set1);
        strv=other.strv;

    }*/

    TextPool::TextPool(TextPool &&other) noexcept {
        swap(*this, other);
    }
   /* TextPool::TextPool(TextPool &&other)  // the expression "arg.member" is lvalue
{
        swap(strv, other.strv);
        swap(set1, other.set1);
       // swap(*this, other);




}*/
     void swap(TextPool& lhs, TextPool& rhs) noexcept
    {
        std::swap(lhs.strv, rhs.strv);
        std::swap(lhs.set1, rhs.set1);
    }
    /*TextPool &TextPool::operator=(const TextPool &other) {
        if (this == &other) {
            return *this;
        }
        //TextPool copy(other);
        //swap(*this, copy);
        this->strv=other.strv;
        this->set1=other.set1;
        return *this;
    }*/

    TextPool &TextPool::operator=(TextPool &&other) noexcept {

        if (this == &other) {
            return other;
        }
        this->set1=other.set1;
        this->strv=other.strv;
        cout<<"huj";
         //   cout<<this<<"---"<<&other;

        return other;


    }
    /*TextPool& TextPool::operator=(TextPool copy)
    {
        swap(*this, copy);
        return *this;
    }*/

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        if (set1.find(str) != set1.end()) {
           // cout<<strv.substr(strv.find(str),str.length()+1);
            if (tmp.find(str)<=tmp.size())return tmp;
            else{
                tmp=str;
                return tmp;
            }
        }
        else {

            set1.emplace(str);
            strv = str;
            return strv;
        }


    }

    size_t TextPool::StoredStringCount() const {
        return set1.size();
    }

    TextPool::~TextPool() {
        set1.clear();

    }
};
