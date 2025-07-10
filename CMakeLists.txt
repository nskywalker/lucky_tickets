cmake_minimum_required(VERSION 3.31)
project(lucky_tickets)

set(CMAKE_CXX_STANDARD 23)

add_executable(lucky_tickets TestLuckyTickets.cpp LuckyTicketsSolver.cpp main.cpp)