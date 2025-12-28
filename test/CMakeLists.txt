set(APPROVAL_TEST_NAME ExpenseReport_ApprovalTests)
set(UNIT_TEST_NAME ExpenseReport_UnitTesting)

add_executable(${APPROVAL_TEST_NAME})
add_executable(${UNIT_TEST_NAME})

target_sources(${APPROVAL_TEST_NAME} PRIVATE ExpenseReport_ApprovalTests.cpp)
target_sources(${UNIT_TEST_NAME} PRIVATE ExpenseReport_UnitTesting.cpp)

target_include_directories(${APPROVAL_TEST_NAME} PUBLIC ./third_party)
target_include_directories(${UNIT_TEST_NAME} PUBLIC ./third_party)

target_link_libraries(${APPROVAL_TEST_NAME} ExpenseReportLib Catch2::Catch2 Catch2::Catch2WithMain)
target_link_libraries(${UNIT_TEST_NAME} ExpenseReportLib Catch2::Catch2 Catch2::Catch2WithMain)

add_test(
    NAME ${APPROVAL_TEST_NAME}
    COMMAND ${APPROVAL_TEST_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_test(
    NAME ${UNIT_TEST_NAME}
    COMMAND ${UNIT_TEST_NAME}
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