#include "FrequencyDict.h"
#include <algorithm>
#include <iterator>

const std::string INVALID_WORD = "Invalid word format.\n";
const std::string EMPTY_DICT = "Empty dictionary.\n";
const std::string ERROR_DELETE = "Error. Trying to delete too much.\n";
const std::string DELETE_NOT_FOUND = "Error. Word to delete is not found in text.\n";
const std::string INVALID_ARGUMENT = "Invalid command argument.\n";
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

void melnikov::FrequencyDict::print(std::istream &in, std::ostream &out, const std::string& arg) {
    if (dict_.empty())
    {
        throw std::invalid_argument(EMPTY_DICT);
    }
    if (arg == "ALL")
    {
        std::for_each(dict_.begin(), dict_.end(),
                      [&out](const std::pair< std::string, size_t >& word)
                      {
                          out << word;
                      });
    }
    else if (arg.size() == 1)
    {
        std::for_each(dict_.begin(), dict_.end(),
                      [&out, arg](const std::pair< std::string, size_t >& word)
                      {
                            if(word.first[0] == std::tolower(arg[0]))
                            {
                                out << word;
                            }
                      });
    }
    else
    {
        throw std::invalid_argument(INVALID_ARGUMENT);
    }
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
            dict_.erase(wordToLower(arg1));
            return {wordToLower(arg1), 0};
        }
        else
        {
            size_t delCount = std::stoull(arg2);
            if (findIter->second <= delCount)
            {
                throw std::invalid_argument(ERROR_DELETE);
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
        throw std::invalid_argument(DELETE_NOT_FOUND);
    }
}

std::pair<std::string, size_t> melnikov::FrequencyDict::frequent(const std::string& arg) {
    if (dict_.empty())
    {
        throw std::invalid_argument(EMPTY_DICT);
    }
    if (arg == "MOST")
    {
        auto maxEl = std::max_element(dict_.begin(), dict_.end(), comparedFreq);
        return *maxEl;
    }
    else if (arg == "LEAST")
    {
        auto minEl = std::min_element(dict_.begin(), dict_.end(), comparedFreq);
        return *minEl;
    }
    else
    {
        throw std::invalid_argument(INVALID_ARGUMENT);
    }
}

size_t melnikov::FrequencyDict::byLetter(const char &letter) {
    if (!iswalpha(letter))
    {
        throw std::invalid_argument(INVALID_ARGUMENT);
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
    std::ostream::sentry sentry(out);
    if (!sentry)
    {
        return out;
    }
     out << word.first << " " << word.second << '\n';
     return out;
}

bool melnikov::comparedFreq(const std::pair< std::string, size_t >& word1,
                  const std::pair< std::string, size_t >& word2)
{
    return word1.second < word2.second;
}
