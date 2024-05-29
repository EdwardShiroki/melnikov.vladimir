#include "WordInput.h"
#include <regex>
namespace melnikov
{
    std::istream &operator >>(std::istream &in, WordInput &dest)
    {
        std::istream::sentry sentry(in);
        if (!sentry)
        {
            return in;
        }
        char letter = '0';
        dest.word = "";
        in >> std::noskipws >> letter;
        while (in && !in.eof() && isAllowedLetter(letter))
        {
            dest.word += std::tolower(letter);
            in >> letter;
        }
        if (!in)
        {
            in.clear();
            in.ignore();
        }
        return in;
    }

    bool isValidWord(const std::string& word)
    {
        std::regex engRegex("[a-zA-Z\'-]{1,30}");
        std::regex rusRegex("[à-ÿÀ-ß\'-]{1,30}");
        return std::regex_match(word, engRegex) || std::regex_match(word, rusRegex);
    }

    bool isAllowedLetter(const char& letter)
    {
        std::regex letterRegex("[à-ÿÀ-ßa-zA-Z\'-]{1,30}");
        std::string toCheck = "" ;
        return std::regex_match(toCheck + letter, letterRegex);
    }

    std::string wordToLower(const std::string& word)
    {
        std::string lowWord = "";
        for (char letter : word)
        {
            lowWord += std::tolower(letter);
        }
        return lowWord;
    }
}


