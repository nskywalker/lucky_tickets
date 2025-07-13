#include "LuckyTicketsSolver.h"

#include <iostream>
#include <numeric>
#include <ranges>

std::vector<uint64_t> LuckyTicketsSolver::calc_n_ticket(const uint64_t N)
{
    if (N == 1) {
        return std::vector<uint64_t>(numberPerRow, 1);
    }
    const auto prevAns = calc_n_ticket(N - 1);
    const auto elemsInRow = (N * 9 + 1);
    std::vector<uint64_t> temp(numberPerRow * elemsInRow, 0);
    for (uint64_t i = 0; i < numberPerRow; ++i) {
        auto begin = temp.begin();
        std::advance(begin, i * elemsInRow + i);
        std::ranges::copy(prevAns, begin);
    }
    std::vector<uint64_t> result(elemsInRow, 0);
    auto temp_view = temp | std::ranges::views::enumerate;
    for (const auto [i, elem] : result | std::ranges::views::enumerate) {
        auto col = temp_view
        | std::ranges::views::filter([elemsInRow, i](const auto& idX){return std::get<0>(idX) % elemsInRow == i;})
        | std::ranges::views::transform([](const auto& idX){return std::get<1>(idX);})
        | std::ranges::views::common;
        elem = std::accumulate(col.cbegin(), col.cend(), 0ull);
    }
    return result;
}

uint64_t LuckyTicketsSolver::calc_tickets(const uint64_t N)
{
    auto sqr = [](const uint64_t x){
        return x * x;
    };
    const auto res = calc_n_ticket(N)
    | std::ranges::views::transform(sqr)
    | std::ranges::views::common;
    return std::accumulate(res.cbegin(), res.cend(), 0ull);
}
