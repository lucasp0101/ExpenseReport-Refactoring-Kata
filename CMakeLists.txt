cmake_minimum_required(VERSION 3.23)

project(ExpenseReport)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(FetchContent)
FetchContent_Declare(
    catch2 
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.0
    GIT_SHALLOW TRUE
  )
FetchContent_MakeAvailable(catch2)

# uncomment this line to enable coverage measurements using gcov
set(CMAKE_CXX_FLAGS "--coverage -O0 -g")

include(CTest)
enable_testing()
add_subdirectory(src)
add_subdirectory(test)