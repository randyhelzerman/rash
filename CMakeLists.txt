CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

ENABLE_TESTING()

SET(CMAKE_BUILD_TYPE Debug)

SET(CMAKE_C_FLAGS, "-Wall -Wextra -Wpedantic -Wformat=2 -Wno-unused-parameter -Wshadow -Wwrite-strings -Wstrict-prototypes -Wold-style-definition -Wredunndant-decls -Wnested-externs -Wmissing-include-dirs")




####################################
# DOWNLOAD GOOGLE TEST FROM GITHUB #
####################################
configure_FILE(gtest-download/CMakeLists.txt.in
               gtest-download/CMakeLists.txt)
EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gtest-download )
EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} --build .
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gtest-download )

SET(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

ADD_SUBDIRECTORY(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build )


##################################################

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)

find_package(Lua 5.3 REQUIRED)
