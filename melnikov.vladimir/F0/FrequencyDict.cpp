//
// Created by vladi on 5/14/2024.
//

#include "FrequencyDict.h"
#include <algorithm>
const std::string INVALID_WORD = "Invalid word format.\n";
const std::string EMPTY_DICT = "Empty dictionary.\n";

void melnikov::FrequencyDict::insert(const std::string& key) {
    auto insertWord = wordToLower(key);
    if (dict_.find(insertWord) != dict_.end())
    {
        dict_.find(insertWord) -> second++;
    }
    else
    {
        dict_.insert({insertWord, 1});
    }
}

std::map< std::string, size_t>::iterator
melnikov::FrequencyDict::find(const std::string &arg)
{
    if (!isValidWord(arg))
    {
        throw std::invalid_argument(INVALID_WORD);
    }
    return dict_.find(wordToLower(arg));
}

size_t melnikov::FrequencyDict::countHelp(const std::string &word) {
    if (!isValidWord(word))
    {
        throw std::invalid_argument(INVALID_WORD);
    }
    if (dict_.empty())
    {
        throw std::invalid_argument(EMPTY_DICT);
    }
    auto findIter = find(word);
    if (findIter != dict_.end())
    {
        return findIter->second;
    }
    else
    {
        return 0;
    }
}

void melnikov::FrequencyDict::print(std::istream &in, std::ostream &out) {
    if (dict_.empty())
    {
        throw std::invalid_argument(EMPTY_DICT);
    }
    std::for_each(dict_.begin(), dict_.end(),
                  [&out](const std::pair< std::string, size_t >& word)
                  {
                        out << word;
                  });
}

std::pair<std::string, size_t> melnikov::FrequencyDict::deleteHelp(const std::string &arg1,const std::string &arg2) {
    if (!isValidWord(arg1))
    {
        throw std::invalid_argument(INVALID_WORD);
    }
    if (dict_.empty())
    {
        throw std::invalid_argument(EMPTY_DICT);
    }
    auto findIter = find(arg1);
    if (findIter != dict_.end())
    {
        if (arg2 == "FULL")
        {
            dict_.erase(arg1);
            return {arg1, 0};
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
                return *findIter;
            }
        }
    }
    else
    {
        throw std::invalid_argument("");
    }
}

std::pair<std::string, size_t> melnikov::FrequencyDict::mostFrequent() {
    if (dict_.empty())
    {
        throw std::invalid_argument(EMPTY_DICT);
    }
    auto maxEl = std::max_element(dict_.begin(), dict_.end(), comparedFreq);
    return *maxEl;
}

std::pair<std::string, size_t> melnikov::FrequencyDict::leastFrequent() {
    if (dict_.empty())
    {
        throw std::invalid_argument(EMPTY_DICT);
    }
    auto minEl = std::min_element(dict_.begin(), dict_.end(), comparedFreq);
    return *minEl;
}

size_t melnikov::FrequencyDict::byLetter(const char &letter) {
    if (!iswalpha(letter))
    {
        throw std::invalid_argument("");
    }
    if (dict_.empty())
    {
        throw std::invalid_argument(EMPTY_DICT);
    }
    auto count = std::count_if(dict_.begin(), dict_.end(),
                               [letter](const std::pair< std::string, size_t >& word)
                               {
                                   return word.first[0] == std::tolower(letter);
                               });
    return count;
}

size_t melnikov::FrequencyDict::compMore(size_t frequency) {
    if (dict_.empty())
    {
        throw std::invalid_argument(EMPTY_DICT);
    }
    auto count = std::count_if(dict_.begin(), dict_.end(),
                               [frequency](const std::pair< std::string, size_t >& word)
                               {
                                   return word.second > frequency;
                               });
    return count;
}

size_t melnikov::FrequencyDict::compLess(size_t frequency) {
    if (dict_.empty())
    {
        throw std::invalid_argument(EMPTY_DICT);
    }
    auto count = std::count_if(dict_.begin(), dict_.end(),
                               [frequency](const std::pair< std::string, size_t >& word)
                               {
                                   return word.second < frequency;
                               });
    return count;
}

std::ostream &melnikov::operator <<(std::ostream &out, const std::pair< std::string, size_t >& word)
{
     out << word.first << " " << word.second << '\n';
     return out;
}

bool melnikov::comparedFreq(const std::pair< std::string, size_t >& word1,
                  const std::pair< std::string, size_t >& word2)
{
    return word1.second < word2.second;
}