#pragma once

#include <list>
#include <iostream>

#include "Expense.h"

using namespace std;

extern void printReport(list<Expense> expenses);
extern string printReportWrapper(list<Expense> expenses);
