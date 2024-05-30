#ifndef COURSE_PROJECT_FREQUENCYDICT_H
#define COURSE_PROJECT_FREQUENCYDICT_H
#include <iostream>
#include <map>
namespace melnikov
{
    class FrequencyDict {
    private:
        std::map< std::string, size_t> dict_;
        std::map< std::string, size_t>::iterator find(const std::string& arg);
    public:
        void print(std::ostream & out, const std::string& arg);
        size_t countHelp(const std::string& word);
        void insert(const std::string& key);
        std::pair< std::string, size_t >
        deleteHelp(const std::string& arg1,const std::string& arg2);
        std::pair< std::string, size_t > frequent(const std::string& arg);
        size_t byLetter(const char & letter);
        size_t compMore(size_t frequency);
        size_t compLess(size_t frequency);
    };
    std::istream &operator >>(std::istream& in, FrequencyDict& dest);
    std::ostream &operator <<(std::ostream &out, const std::pair< std::string, size_t >& word );
    bool comparedFreq(const std::pair< std::string, size_t >& word1,
                      const std::pair< std::string, size_t >& word2);
}



#endif //COURSE_PROJECT_FREQUENCYDICT_H
