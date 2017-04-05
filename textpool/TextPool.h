//
// Created by radek on 29.03.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
using namespace std;
namespace pool {
    class TextPool {
        experimental::string_view strv;
        experimental::string_view tmp;
        set<string> set1;


    public:
        TextPool();

        TextPool(initializer_list<string> initstr);

        TextPool(const TextPool &other)= delete;

        //2. konstruktor przenoszący
        TextPool(TextPool &&other)noexcept ;

        //3. operator przypisania kopiujący
        TextPool &operator=(const TextPool &other)= delete;


        //4. operator przypisania przenoszący
        TextPool &operator=(TextPool &&other)noexcept;

        friend void swap(TextPool& lhs, TextPool& rhs) noexcept;
        //TextPool& operator=(TextPool copy);

      /* TextPool(const TextPool &other)= default;

        //2. konstruktor przenoszący
        TextPool(TextPool &&other)= default;

        //3. operator przypisania kopiujący
        TextPool &operator=(const TextPool &other)= default;


        //4. operator przypisania przenoszący
        TextPool &operator=(TextPool &&other)noexcept= default;
        //5. Destruktor*/
        ~TextPool();

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;


    };
};

#endif //JIMP_EXERCISES_TEXTPOOL_H
