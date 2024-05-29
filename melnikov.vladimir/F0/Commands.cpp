#include "Commands.h"
#include "WordInput.h"
#include <algorithm>

namespace  melnikov
{
    void count(std::istream & in, std::ostream & out, FrequencyDict& src)
    {
        std::string arg;
        in >> arg;
        out << src.countHelp(arg) << '\n';
    }

    void print(std::istream & in, std::ostream & out, FrequencyDict& src)
    {
        std::string arg;
        in >> arg;
        src.print(in, out, arg);
    }
    void deleteCommand(std::istream & in, std::ostream & out, FrequencyDict& src)
    {
        std::string arg1;
        std::cin >> arg1;
        std::string arg2;
        std::cin >> arg2;
        out << src.deleteHelp(arg1, arg2);
    }

    void frequent(std::istream & in, std::ostream & out, FrequencyDict& src)
    {
        std::string arg;
        in >> arg;
        out << src.frequent(arg);
    }
    void byLetter(std::istream & in, std::ostream & out, FrequencyDict& src)
    {
        char letter;
        in >> letter;
        out << src.byLetter(letter) << '\n';
    }
    void compMore(std::istream & in, std::ostream & out, FrequencyDict& src)
    {
        size_t arg = 0;
        in >> arg;
        out << src.compMore(arg) << '\n';
    }

    void compLess(std::istream & in, std::ostream & out, FrequencyDict& src)
    {
        size_t arg = 0;
        in >> arg;
        out << src.compLess(arg) << '\n';
    }

}
