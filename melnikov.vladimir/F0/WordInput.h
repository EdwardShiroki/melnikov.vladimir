#ifndef COURSE_PROJECT_WORDINPUT_H
#define COURSE_PROJECT_WORDINPUT_H
#include <iostream>
namespace melnikov
{
    struct WordInput
    {
        std::string word;
    };
    std::istream &operator >>(std::istream &in, WordInput &dest);
    bool isValidWord(const std::string& word);
    bool isAllowedLetter(const char& letter);
    std::string wordToLower(const std::string& word);
}




#endif //COURSE_PROJECT_WORDINPUT_H
