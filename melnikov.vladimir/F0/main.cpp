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
    input >> source;
    commandWork(std::cin, std::cout, source);
    return 0;
}

