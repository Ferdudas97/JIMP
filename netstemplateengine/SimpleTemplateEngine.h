//
// Created by radek on 26.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <string>
#include <unordered_map>
using namespace std;
namespace nets{
    class View
    {
        string text;
    public:

        View(string txt);
        std::string Render(const std::unordered_map <std::string, std::string> &model) const;
    };





}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
