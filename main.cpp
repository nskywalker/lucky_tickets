#include "TestLuckyTickets.h"
#include "LuckyTicketsSolver.h"

int main() {
    const TestLuckyTickets test_lucky(&LuckyTicketsSolver::calc_tickets);
    test_lucky.run();
    return 0;
}
