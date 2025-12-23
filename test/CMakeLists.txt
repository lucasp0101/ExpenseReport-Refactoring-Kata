include(FetchContent)

FetchContent_Declare(
    catch2 
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.0
    GIT_SHALLOW TRUE
  )
FetchContent_MakeAvailable(catch2)

set(TEST_NAME ExpenseReportApprovalTests)
add_executable(${TEST_NAME})
target_sources(${TEST_NAME} PRIVATE ExpenseReportApprovalTests.cc)
target_include_directories(${TEST_NAME} PUBLIC ../third_party)
target_link_libraries(${TEST_NAME} ExpenseReportLib Catch2::Catch2 Catch2::Catch2WithMain)
set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 14)
add_test(
NAME ${TEST_NAME}
COMMAND ${TEST_NAME}
WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set compiler option /FC for Visual Studio to to make the __FILE__ macro expand to full path. 
# The __FILE__ macro is used by Catch2 to get the path to current test file.
# Links:
# * https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=vs-2019
# * https://docs.microsoft.com/en-us/cpp/build/reference/fc-full-path-of-source-code-file-in-diagnostics?view=vs-2019
if (MSVC)
target_compile_options(${TEST_NAME} PRIVATE "/FC")
endif()