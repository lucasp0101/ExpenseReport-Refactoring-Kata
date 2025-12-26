set(SRC_LIB_NAME ExpenseReportLib)
add_library(${SRC_LIB_NAME})
target_sources(${SRC_LIB_NAME} PRIVATE ExpenseReport.cpp ExpenseReport.h Expense.cpp Expense.h)
target_include_directories(${SRC_LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
