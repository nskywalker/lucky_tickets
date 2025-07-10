#ifndef TESTLUCKYTICKETS_H
#define TESTLUCKYTICKETS_H

#include <cstdint>
#include <functional>

class TestLuckyTickets {
public:
    using LuckyTicketsFunc = std::function<uint64_t(uint64_t)>;
    explicit TestLuckyTickets(LuckyTicketsFunc f);
    ~TestLuckyTickets() = default;
    void run() const;
private:
    LuckyTicketsFunc luckyTicketsFunc;
};

#endif //TESTLUCKYTICKETS_H
