//
// Created by vladi on 5/14/2024.
//

#ifndef COURSE_PROJECT_COMMANDS_H
#define COURSE_PROJECT_COMMANDS_H
#include "FrequencyDict.h"
namespace melnikov
{
    void print(const FrequencyDict& src);
    void count(FrequencyDict& src);
    void deleteCommand(FrequencyDict& src);
    void mostFrequent(FrequencyDict& src);
    void leastFrequent(FrequencyDict& src);
    bool comparedFreq(const std::pair< std::string, size_t >& word1,
                      const std::pair< std::string, size_t >& word2);
    void byLetter(FrequencyDict& src);
    void compLess(FrequencyDict& src);
    void compMore(FrequencyDict& src);
    void insertComm(FrequencyDict& src);
}

#endif //COURSE_PROJECT_COMMANDS_H
