//
// Created by radek on 14.03.17.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>
#include <iostream>
using namespace std;
namespace tinyurl {
    struct TinyUrlCodec {
        std::array<char, 6> state;
        std::map<std::string, string> p;
        std::map<string,string> p2;
    };

    std::unique_ptr<TinyUrlCodec> Init();

    void NextHash(std::array<char, 6> *state);

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}
#endif //JIMP_EXERCISES_TINYURL_H
