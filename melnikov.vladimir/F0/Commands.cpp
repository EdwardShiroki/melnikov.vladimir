#include "Commands.h"
#include "WordInput.h"
#include <functional>
#include <iterator>
#include <limits>
const std::string INVALID_COMMAND = "<INVALID COMMAND>\n";
const std::string COMMANDS = "Доступные команды:\n"
                             "PRINT [ALL | Letter] - вывод словаря (всего или слов начинающихся на букву)\n"
                             "COUNT [WORD] - кол-во вхождений слова\n"
                             "DELETE [WORD] [FULL| num-of-words] - удаление слова "
                             "из словаря полностью или кол-во его вхождений\n"
                             "FREQUENT [MOST | LEAST] - самое частое слово\n"
                             "BY_LETTER [CHAR]- кол-во слов на букву\n"
                             "COMPARE_MORE [num] - кол-во слов, встречающихся чаще, чем значение аргумента\n"
                             "COMPARE_LESS [num] - кол-во слов, встречающихся реже, чем значение аргумента\n";
namespace  melnikov
{
    void commandWork(std::istream & in, std::ostream & out, FrequencyDict& src)
    {
        auto t = std::istream_iterator< WordInput >();
        std::map < std::string, std::function <
                void (std::istream &in, std::ostream &out, FrequencyDict& dictionary)>> command;
        command["PRINT"] = print;
        command["COUNT"] = count;
        command["DELETE"] = deleteCommand;
        command["FREQUENT"] = frequent;
        command["BY_LETTER"] = byLetter;
        command["COMPARE_LESS"] = compLess;
        command["COMPARE_MORE"] = compMore;
        out << COMMANDS;
        std::string cmd;
        while (!in.eof())
        {
            if (in.fail())
            {
                in.clear();
            }
            try
            {
                in >> cmd;
                if (in.eof())
                {
                    break;
                }
                auto func = command.find(cmd);
                if (func == command.end()) {
                    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument(INVALID_COMMAND);
                }
                func->second(in, out, src);
            }
            catch (std::invalid_argument& e)
            {
                out << e.what();
            }
        }
    }
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
        src.print(out, arg);
    }
    void deleteCommand(std::istream & in, std::ostream & out, FrequencyDict& src)
    {
        std::string arg1;
        in >> arg1;
        std::string arg2;
        in >> arg2;
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
