cmake_minimum_required(VERSION 3.22.1)
project(optBinaryTree_test)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(${PROJECT_NAME} 
  src/optBinaryTree_test.cc
  src/binaryTree_test.cc
)

target_link_libraries(${PROJECT_NAME}
 PRIVATE
  GTest::GTest
  lib::optSearch
  lib::binaryTree
)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main gmock_main)

add_test(sort_gtests
  optBinaryTree_test
)


