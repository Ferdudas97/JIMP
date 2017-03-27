//
// Created by radek on 26.03.17.
//

#include "SimpleJson.h"

#include "SimpleJson.h"
#include <experimental/optional>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <regex>
namespace nets {
    using ::std::vector;
    using ::std::map;
    using ::std::cout;
    using ::std::endl;
    using ::std::string;
    using ::nets::JsonValue;
    using ::std::literals::operator ""s;

    JsonValue::JsonValue(int intvalue) {
        intvalue_ = intvalue;
        isInt = 1;
    }

    JsonValue::JsonValue(bool boolvalue) {
        boolvalue_ = boolvalue;
        isBool = 1;
    }

    JsonValue::JsonValue(double doublevalue) {
        doublevalue_ = doublevalue;
        isDouble = 1;
    }

    JsonValue::JsonValue(string str) {
        str_ = str;
        isString = 1;
    }

    JsonValue::JsonValue(vector<JsonValue> vector1) {
        vector1_ = vector1;
        isVector = 1;
    }

    JsonValue::JsonValue(map<string, JsonValue> mapa) {
        mapa_ = mapa;
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        JsonValue tmp;
        for (auto &n:mapa_) {
            if (name == n.first) {
                return std::experimental::make_optional(n.second);
            }
        }
        return {};

    }
    std::string JsonValue::ToString() const{
        if(isInt==1){
            return to_string(intvalue_);
        }
        if(isDouble==1){
            string tmp=to_string(doublevalue_);
            return tmp.substr(0,tmp.find(".")+3);
        }
        if(isBool==1){
            if(boolvalue_)return "true";
            else return "false";
        }
        if(isString==1){
            string tmp;
            int howmany=0;
            for (int i = 0; i <str_.size() ; i++) {
                tmp+=str_[i];
                if(int(str_[i])==92)
                {
                    tmp.insert(i,"\\");
                }
                if(str_[i] ==char(92))
                {
                    tmp.insert(i,"\\");

                }
                cout<<tmp<<endl;
            }
            return tmp;
        }
        if(isVector==1){
             string tmp;
            for(auto &n:vector1_){
                tmp+=to_string(n.isInt);

            }

            return tmp;
        }
        return "";
    }
}