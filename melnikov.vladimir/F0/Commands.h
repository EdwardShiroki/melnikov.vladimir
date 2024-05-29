//
// Created by vladi on 5/14/2024.
//

#ifndef COURSE_PROJECT_COMMANDS_H
#define COURSE_PROJECT_COMMANDS_H
#include "FrequencyDict.h"
namespace melnikov
{
    void count(std::istream & in, std::ostream & out, FrequencyDict& src);
    void print(std::istream & in, std::ostream & out, FrequencyDict& src);
    void deleteCommand(std::istream & in, std::ostream & out, FrequencyDict& src);
    void mostFrequent(std::istream & in, std::ostream & out, FrequencyDict& src);
    void leastFrequent(std::istream & in, std::ostream & out, FrequencyDict& src);
    void byLetter(std::istream & in, std::ostream & out, FrequencyDict& src);
    void compLess(std::istream & in, std::ostream & out, FrequencyDict& src);
    void compMore(std::istream & in, std::ostream & out, FrequencyDict& src);
}

#endif //COURSE_PROJECT_COMMANDS_H
