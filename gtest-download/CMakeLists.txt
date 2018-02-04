CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(gtest-download NONE)

INCLUDE(ExternalProject)
ExternalProject_Add(googletest
    GIT_REPOSITORY      https://github.com/google/googletest.git
    GIT_TAG             master
    SOURCE_DIR          "/Users/randallhelzerman/projects/src/rash/googletest-src"
    BINARY_DIR          "/Users/randallhelzerman/projects/src/rash/googletest-build"
    CONFIGURE_COMMAND   ""
    BUILD_COMMAND       ""
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
)
