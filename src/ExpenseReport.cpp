#include <chrono>
#include "ExpenseReport.h"
#include <sstream>
#include <format>

// * To break the dependency to time.h's ctime
// * Necessary for the approval tests
std::string to_return = "01-01-02 00:00:00\n";
char *ctime(const time_t *__timer)
{   
    return &to_return[0];
}

// ! This could be abstracted to a class "ExpenseList" in charge of managing arrays of expenses
// ! but because I don't have more requirements related to these operations other than a toString method
// ! I'll just let it be.
std::string expenseListToString(std::list<Expense> expenses)
{
    int total = 0;
    int mealExpenses = 0;

    auto now_tmp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    auto now = ctime(&now_tmp);

    std::string expense_str = "";
    
    for (Expense &expense : expenses) {
        total += expense.getAmount();
        if (expense.isMeal())
        {
            mealExpenses += expense.getAmount();
        }
        expense_str += expense.toString();
    }
    
    return std::format(STR_TEMPLATE_FOR_EXPENSE_LIST, now, expense_str, mealExpenses, total);
}

void printReport(std::list<Expense> expenses) 
{
    std::cout << expenseListToString(expenses);
}

// * Capture the output that would go to cout and return it as a string
// * Necessary to run the approval tests
std::string printReportWrapper(std::list<Expense> expenses)
{
    std::stringstream stream;
    auto * old = std::cout.rdbuf(stream.rdbuf());
    
    printReport(expenses);

    std::cout.rdbuf(old);

    return stream.str();
}