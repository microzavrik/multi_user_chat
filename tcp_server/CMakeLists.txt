cmake_minimum_required(VERSION 3.0)

project(tcp_server)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)

add_executable(tcp_server main.cpp chat_server.cpp client_session.cpp server_log.cpp)

include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(tcp_server ${Boost_LIBRARIES})