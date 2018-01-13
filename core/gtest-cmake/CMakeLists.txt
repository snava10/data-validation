CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
PROJECT(gtest-fecher CXX)
INCLUDE(ExternalProject)
FIND_PACKAGE(Git REQUIRED)

####### Download and Generate #######
set(GTEST_EXTERNAL_ROOT ${CMAKE_BINARY_DIR}/externals/gtest)
set(GTEST_LOCAL_ROOT ${CMAKE_BINARY_DIR}/locals/gtest)

ExternalProject_Add(
 gtest
 PREFIX ${GTEST_LOCAL_ROOT}
 GIT_REPOSITORY https://github.com/google/googletest.git
 GIT_TAG master
 TIMEOUT 10
 UPDATE_COMMAND ${GIT_EXECUTABLE} pull
 CONFIGURE_COMMAND ""
 BUILD_COMMAND ""
 INSTALL_COMMAND ""
 LOG_DOWNLOAD ON
)
