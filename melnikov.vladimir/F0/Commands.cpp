#include "Commands.h"
#include "WordInput.h"
#include <algorithm>

namespace  melnikov
{
    void print(const FrequencyDict& src)
    {
        std::for_each(src.dict.begin(), src.dict.end(),
                      [](const std::pair<std::string, size_t>& wordPair)
                      {
                            std::cout << wordPair;
                      });
    }
    void count(FrequencyDict& src)
    {
        std::string arg;
        std::cin >> arg;
        if (!isValidWord(arg))
        {
            throw std::invalid_argument("");
        }
        auto findIter = src.find(arg);
        if (findIter != src.dict.end())
        {
            std::cout << findIter->second;
        }
        else
        {
            std::cout << 0;
        }
        std::cout << '\n';
    }

    void deleteCommand(FrequencyDict& src)
    {
        std::string arg1;
        std::cin >> arg1;
        if (!isValidWord(arg1))
        {
            throw std::invalid_argument("");
        }
        auto findIter = src.find(arg1);
        if (findIter != src.dict.end())
        {
            std::string arg2;
            std::cin >> arg2;
            if (arg2 == "FULL")
            {
                src.dict.erase(arg1);
                std::cout << arg1 << " " << 0 << '\n';
            }
            else
            {
                size_t delCount = std::stoull(arg2);
                if (findIter->second <= delCount)
                {
                    throw std::invalid_argument("");
                }
                else
                {
                    findIter->second -= delCount;
                    std::cout << *findIter;
                }
            }
        }
        else
        {
            throw std::invalid_argument("");
        }

    }

    bool comparedFreq(const std::pair< std::string, size_t >& word1,
                      const std::pair< std::string, size_t >& word2)
    {
        return word1.second < word2.second;
    }
    void mostFrequent(FrequencyDict& src)
    {
        if (src.dict.empty())
        {
            throw std::invalid_argument("");
        }
        auto maxEl = std::max_element(src.dict.begin(), src.dict.end(), comparedFreq);
        std::cout << *maxEl;
    }
    void leastFrequent(FrequencyDict& src)
    {
        if (src.dict.size() == 0)
        {
            throw std::invalid_argument("");
        }
        auto minEl = std::min_element(src.dict.begin(), src.dict.end(), comparedFreq);
        std::cout << *minEl;
    }
    void byLetter(FrequencyDict& src)
    {
        char letter;
        std::cin >> letter;
        if (!iswalpha(letter))
        {
            throw std::invalid_argument("");
        }
        auto count = std::count_if(src.dict.begin(), src.dict.end(),
                               [letter](const std::pair< std::string, size_t >& word)
                               {
                                   return word.first[0] == std::tolower(letter);
                               });
        std::cout << count << '\n';
    }
    void compMore(FrequencyDict& src)
    {
        size_t arg = 0;
        std::cin >> arg;
        auto count = std::count_if(src.dict.begin(), src.dict.end(),
                                   [arg](const std::pair< std::string, size_t >& word)
                                   {
                                       return word.second > arg;
                                   });
        std::cout << count << '\n';
    }

    void compLess(FrequencyDict& src)
    {
        size_t arg = 0;
        std::cin >> arg;
        auto count = std::count_if(src.dict.begin(), src.dict.end(),
                                   [arg](const std::pair< std::string, size_t >& word)
                                   {
                                       return word.second < arg;
                                   });
        std::cout << count << '\n';
    }

    void insertComm(FrequencyDict& src)
    {
        std::string arg;
        std::cin >> arg;
        if (!isValidWord(arg))
        {
            throw std::invalid_argument("");
        }
        size_t value;
        std::cin >> value;
        src.insert(arg, value);
        std::cout << *src.find(arg);
    }
}
