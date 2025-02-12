cmake_minimum_required(VERSION 3.29)
project(Code)

set(CMAKE_CXX_STANDARD 20)

add_executable(Test1
        TestPrograms/first.cpp
        TestPrograms/Sales_item.h
        TestPrograms/Sales_data.h
        TestPrograms/Sales_data.cpp
)
add_executable(Lab1.1
        Assignments/Lab1.1.cpp
)
add_executable(Lab1.2
        Assignments/Lab1.2.cpp
)
add_executable(Lab2.1
        Assignments/Lab2.1.cpp
)
add_executable(Lab2.2
        Assignments/Lab2.2.cpp
)
add_executable(Lab3.1
        Assignments/Lab3.1.cpp
)
add_executable(Lab3.2
        Assignments/Lab3.2.cpp
)
add_executable(Lab4
        Assignments/Lab4/Lab4.cpp
        Assignments/Lab4/item.cpp
        Assignments/Lab4/item.h
)
add_executable(Lab6
        Assignments/Lab6/Lab6.cpp
        Assignments/Lab6/house.cpp
        Assignments/Lab6/house.h
        Assignments/Lab6/apartment.cpp
        Assignments/Lab6/apartment.h

)