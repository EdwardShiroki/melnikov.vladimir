//
// Created by vladi on 5/14/2024.
//

#include "FrequencyDict.h"
#include <algorithm>


void melnikov::FrequencyDict::insert(std::string key, size_t value) {
    std::transform(key.begin(), key.end(), key.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    if (dict.find(key) != dict.end())
    {
        dict.find(key) ->second+= value;
    }
    else
    {
        dict.insert({key, value});
    }
}

std::_Rb_tree_iterator<std::pair<const std::basic_string<char>, unsigned long long int>>
melnikov::FrequencyDict::find(std::string &arg) {
    std::transform(arg.begin(), arg.end(), arg.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return dict.find(arg);
}

std::ostream &melnikov::operator <<(std::ostream &out, const std::pair< std::string, size_t >& word)
{
     out << word.first << " " << word.second << '\n';
     return out;
}
