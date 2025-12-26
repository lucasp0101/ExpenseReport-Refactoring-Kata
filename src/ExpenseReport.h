#pragma once

#include <list>
#include <iostream>
#include <string_view>

#include "Expense.h"

#define STR_TEMPLATE_FOR_EXPENSE_LIST "Expenses {}{}Meal expenses: {}\nTotal expenses: {}\n"

extern void printReport(std::list<Expense> expenses);
extern std::string printReportWrapper(std::list<Expense> expenses);
