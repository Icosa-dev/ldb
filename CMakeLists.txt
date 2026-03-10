cmake_minimum_required(VERSION 3.10.0)
project(ldb VERSION 0.1.0 LANGUAGES CXX)

include_directories(
    "src/"
)

add_executable(ldb 
    "src/main.cpp"
)