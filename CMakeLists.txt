
project(hello_world)			# Название проекта

cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.

add_executable(main src/main.cpp src/yaml_parce.cpp)		# Создает исполняемый файл с именем main
									# из исходника main.cpp

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
  yaml_parce_test
  tests/yaml_parce.cpp
)
target_link_libraries(
  yaml_parce_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(yaml_parce_test)