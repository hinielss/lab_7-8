cmake_minimum_required(VERSION 3.10)
project(PCB)

set(CMAKE_CXX_STANDARD 17)

# Все исходные файлы
set(SOURCES
    main.cpp
    ListNode.cpp
    ProcessList.cpp
)

add_executable(PCB ${SOURCES})