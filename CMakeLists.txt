 cmake_minimum_required(VERSION 3.10)
project(LowLatencyNetworkCommunication)

set(CMAKE_CXX_STANDARD 11)
find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(NetworkCommunication main.cpp network.cpp)
target_link_libraries(NetworkCommunication ${Boost_LIBRARIES})

