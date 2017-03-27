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
    int i=0,x=0;
    for (auto &mod: model) {
       if (txt.find("{{" + mod.first + "}}") < txt.length()){
            txt.replace(txt.find("{{" + mod.first +"}}"),mod.first.size()+4,mod.second);
       }
    }
    for (auto &mod: model) {
        i++;
       
        if (i>model.size())break;
        while (txt.find("{{" + mod.first + "}}") < txt.length() and text.find(mod.second)>=txt.find("{{" + mod.first + "}}")) {

            txt.replace(txt.find("{{" + mod.first + "}}"), mod.first.size() + 4, mod.second);
        }
    }



   for (auto &mod: model) {
            if (txt.find("{{") < txt.size() and txt.find("}}") < txt.size() and txt.find("}}") < txt.find("} ") and (txt.find(mod.second)>=txt.length() or txt.find("{{" + mod.first + "}}")>=txt.length())){
                txt.replace(txt.find("{{"), txt.find("}}") - txt.find("{{") + 2, "");
            }
        }
    return  txt;
}
