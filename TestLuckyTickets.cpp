#include "TestLuckyTickets.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

TestLuckyTickets::TestLuckyTickets(LuckyTicketsFunc f) : luckyTicketsFunc(std::move(f)) {}

void TestLuckyTickets::run() const
{
    int iter = 0;
    const auto ticketsDir = std::filesystem::current_path() / "1.Tickets";
    while (true)
    {

        const auto inFile = ticketsDir / std::format("test.{}.in", iter);
        const auto outFile = ticketsDir / std::format("test.{}.out", iter);
        if (!std::filesystem::exists(inFile) || !std::filesystem::exists(outFile))
        {
            break;
        }
        std::ifstream inFileStream(inFile);
        std::ifstream answerFileStream(outFile);
        std::string line;
        std::getline(inFileStream, line);
        const auto ans = luckyTicketsFunc(std::stoll(line));
        std::getline(answerFileStream, line);
        std::cout << std::format("Test{} ", iter);
        if (std::to_string(ans) == line)
        {
            std::cout << std::format("OK") << std::endl;
        } else
        {
            std::cout << std::format("FAIL, EXPECTED {}", line) << std::endl;
        }
        ++iter;
    }
}
