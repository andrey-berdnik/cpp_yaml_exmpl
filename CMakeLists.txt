project(DeLorianExecutionManager)
cmake_minimum_required(VERSION 2.8) 

add_executable(main 
              src/main.cpp 
              src/yaml_parse.cpp)	

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  tests
  tests/tests.cpp
  tests/yaml_parse_test.cpp
)
target_link_libraries(
  tests
  gtest_main
  gmock_main
)

include(GoogleTest)
gtest_discover_tests(tests)
