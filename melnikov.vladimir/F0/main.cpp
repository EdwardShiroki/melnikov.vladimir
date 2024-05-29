#include <iostream>
#include "FrequencyDict.h"
#include <fstream>
#include <functional>
#include <sstream>
#include <iterator>
#include "WordInput.h"
#include "Commands.h"
#include <limits>
#include <vector>
#include <algorithm>
const std::string INVALID_COMMAND = "<INVALID COMMAND>\n";
int main(int argc, char** argv)
{
    using namespace melnikov;
    if (argc < 2)
    {
        return 1;
    }
    std::ifstream input(argv[1]);
    if (!input)
    {
        return 1;
    }
    FrequencyDict source;
    auto t = std::istream_iterator< WordInput >();
    std::map < std::string, std::function <
            void (std::istream &in, std::ostream &out, FrequencyDict& dictionary)>> command;
    std::string toParse;
    std::vector < WordInput > words;
    command["PRINT"] = print;
    command["COUNT"] = count;
    command["DELETE"] = deleteCommand;
    command["FREQUENT"] = frequent;
    command["BYLETTER"] = byLetter;
    command["COMPARE_LESS"] = compLess;
    command["COMPARE_MORE"] = compMore;
    while (!input.eof())
    {
        std::copy(
                std::istream_iterator< WordInput >(input),
                std::istream_iterator< WordInput >(),
                std::back_inserter(words)
        );
    }
    std::for_each(words.begin(), words.end(),
                  [&source](const WordInput& key)
                  {
                        if (isValidWord(key.word))
                        {
                            source.insert(key.word);
                        }
                  });
    std::cout << "Доступные команды:\n"
                 "PRINT [ALL | Letter] - вывод словаря (всего или слов начинающихся на букву)\n"
                 "COUNT [WORD] - кол-во вхождений слова\n"
                 "DELETE [WORD] [FULL| num-of-words] - удаление слова "
                 "из словаря полностью или кол-во его вхождений\n"
                 "FREQUENT [MOST | LEAST] - самое частое слово\n"
                 "BY_LETTER [CHAR]- кол-во слов на букву\n"
                 "COMPARE_MORE [num] - кол-во слов, встречающихся чаще, чем значение аргумента\n"
                 "COMPARE_LESS [num] - кол-во слов, встречающихся реже, чем значение аргумента\n";
    std::string cmd;
    while (!std::cin.eof())
    {
        if (std::cin.fail())
        {
            std::cin.clear();
        }
        try
        {
            std::cin >> cmd;
            if (std::cin.eof())
            {
                break;
            }
            auto func = command.find(cmd);
            if (func == command.end()) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument(INVALID_COMMAND);
            }
            func->second(std::cin, std::cout, source);
        }
        catch (std::invalid_argument& e)
        {
            std::cout << e.what();
        }
    }
    return 0;
}

