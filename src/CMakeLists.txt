PROJECT( rash )
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

ADD_EXECUTABLE(rash
               rash_main.cpp)

include_directories(rash ${CMAKE_CURRENT_SOURCE_DIR} ${CURSES_INCLUDE_DIR} ${LUA_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../swig)

target_link_libraries(rash ${CURSES_LIBRARIES} linenoise ${LUA_LIBRARIES})
