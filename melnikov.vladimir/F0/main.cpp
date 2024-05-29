#include "FrequencyDict.h"
#include <fstream>
#include <iterator>
#include "WordInput.h"
#include "Commands.h"
#include <vector>
#include <algorithm>

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
    std::vector < WordInput > words;
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
    commandWork(std::cin, std::cout, source);
    return 0;
}

