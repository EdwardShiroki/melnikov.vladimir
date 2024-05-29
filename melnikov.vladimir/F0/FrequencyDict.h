#ifndef COURSE_PROJECT_FREQUENCYDICT_H
#define COURSE_PROJECT_FREQUENCYDICT_H
#include <iostream>
#include <map>
namespace melnikov
{
    struct FrequencyDict {
        std::map< std::string, size_t> dict;
        std::_Rb_tree_iterator<std::pair<const std::basic_string<char>,
        unsigned long long int>> find(std::string& arg);
        void insert(std::string key, size_t value = 1);
    };
    std::ostream &operator <<(std::ostream &out, const std::pair< std::string, size_t >& word );
}



#endif //COURSE_PROJECT_FREQUENCYDICT_H
