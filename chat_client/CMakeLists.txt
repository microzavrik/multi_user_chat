cmake_minimum_required(VERSION 3.0)

project(chat_client)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)

add_executable(ChatClient main.cpp chat_client.cpp input_message.cpp)

include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(chat_client ${Boost_LIBRARIES})

target_link_libraries(chat_client termcolor)