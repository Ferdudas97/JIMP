//
// Created by radek on 26.03.17.
//

#include "SimpleTemplateEngine.h"
#include <iostream>

nets::View::View(string txt) {

    text=txt;
}
std::string nets::View::Render(const std::unordered_map<std::string, std::string> &model) const {

    string txt=text;
    for (auto &mod: model) {
       // string tmp=mod.first;
       // string tmp2=mod.second;
        cout<<txt<<endl;
       // cout<<txt.find("{{" + tmp = "}}")<<endl;
        while (txt.find("{{" + mod.first + "}}") < txt.length()) {
           // cout<<txt.find("{{" + tmp = "}}")<<"tutaj"<<endl;
            //txt.replace(txt.find("{{" + tmp + "}}"), tmp.size() + 4, tmp2);
            txt.replace(txt.find("{{" + mod.first +"}}"),mod.first.size()+4,mod.second);
        }
    }
    while (txt.find("{{")<txt.size() and txt.find("}}")<txt.size() and txt.find("}}")<txt.find("} "))
    {
        if (txt.find("}}")<txt.size() and txt.find("}}")<txt.find("} "))
        {
            txt.replace(txt.find("{{"),txt.find("}}")-txt.find("{{")+2,"");
        }
    }
    //cout<<txt<<"teraz ja"<<endl;
    return  txt;
}