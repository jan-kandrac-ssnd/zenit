cmake_minimum_required(VERSION 3.17)
project(zenit2021)

set(CMAKE_CXX_STANDARD 14)

add_executable(zenit2021 zenit21ska/zenit21ska.cpp zenit21skb/zenit21skb.cpp zenit21skc/zenit21skc.cpp zenit21skd/zenit21skd.cpp zenit21ske/zenit21ske.cpp zenit21ski/zenit21ski.cpp)