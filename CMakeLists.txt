CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

###############################################
# Setup build type and special compiler flags #
###############################################

SET(CMAKE_BUILD_TYPE Debug)

SET(CMAKE_C_FLAGS, "-Wall -Wextra -Wpedantic -Wformat=2 -Wno-unused-parameter -Wshadow -Wwrite-strings -Wstrict-prototypes -Wold-style-definition -Wredunndant-decls -Wnested-externs -Wmissing-include-dirs")


#################
# Setup testing #
#################

ENABLE_TESTING()

# DOWNLOAD GOOGLE TEST FROM GITHUB #
configure_FILE(gtest-download/CMakeLists.txt.in
               gtest-download/CMakeLists.txt)
EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gtest-download )
EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} --build .
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gtest-download )

SET(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

ADD_SUBDIRECTORY(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build )


###############################
# SETUP EXTERNAL DEPENDENCIES #
###############################

# Setup Swig
FIND_PACKAGE(SWIG REQUIRED)

# Setup lua
find_package(Lua 5.3 REQUIRED)
INCLUDE_DIRECTORIES(${LUA_INCLUDE_DIR})

# Setup curses
SET(CURSES_USE_NCURSES TRUE)
find_package(Curses 6.1 REQUIRED)


##################################################

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

ADD_SUBDIRECTORY(applications)
ADD_SUBDIRECTORY(standalone)
ADD_SUBDIRECTORY(test)
