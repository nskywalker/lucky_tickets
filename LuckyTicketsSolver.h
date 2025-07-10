#ifndef LUCKYTICKETSSOLVER_H
#define LUCKYTICKETSSOLVER_H

#include <cstdint>
#include <vector>

class LuckyTicketsSolver {
    static constexpr uint64_t numberPerRow = 10;
    static std::vector<uint64_t> calc_n_ticket(uint64_t N);
public:
    explicit LuckyTicketsSolver() = default;
    ~LuckyTicketsSolver() = default;
    static uint64_t calc_tickets(uint64_t N);
};



#endif //LUCKYTICKETSSOLVER_H
