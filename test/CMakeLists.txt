CMAKE_MINIMUM_REQUIRED(VERSION 3.5)


ADD_EXECUTABLE(rash.t
               rash.t.cpp)

TARGET_INCLUDE_DIRECTORIES(rash.t PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}")
TARGET_LINK_LIBRARIES(rash.t
                      gtest gmock gtest_main)


set_property(TARGET rash.t PROPERTY CXX_STANDARD 11)
set_property(TARGET rash.t PROPERTY CXX_STANDARD_REQUIRED ON)
