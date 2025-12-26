#include <chrono>
#include "ExpenseReport.h"
#include <sstream>

using namespace std;

// * To break the dependency to time.h's ctime
string to_return = "01-01-02 00:00:00\n";
char *ctime(const time_t *__timer)
{   
    return &to_return[0];
}

string expenseListToString(list<Expense> expenses)
{
    int total = 0;
    int mealExpenses = 0;

    string str_to_return = "";

    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    
    str_to_return += "Expenses "; 
    str_to_return += ctime(&now);

    for (Expense &expense : expenses) {
        total += expense.getAmount();
        if (expense.isMeal())
        {
            mealExpenses += expense.getAmount();
        }
        str_to_return += expense.toString();
    }

    str_to_return += "Meal expenses: " + to_string(mealExpenses) + '\n';
    str_to_return += "Total expenses: " + to_string(total) + '\n';
    
    return str_to_return;
}

// * In general, I would include the expenses list in a class 
// * in itself, and encapsulate all the responsabilities of this class
// * there.
// ! This method has too many responsabilities: 
// ! calculate the final ammout for all expenses, time-stamp it
// ! and print it to stdout

// ! I'm not sure a list is the best data structure to use here
void printReport(list<Expense> expenses) 
{
    cout << expenseListToString(expenses);
}

// * Capture the output that would go to cout and return it as a string
string printReportWrapper(list<Expense> expenses)
{
    std::stringstream stream;
    auto * old = std::cout.rdbuf(stream.rdbuf());
    
    printReport(expenses);

    std::cout.rdbuf(old);

    return stream.str();
}

// ! Magic string in code
// ! Magic numbers in the code
// ! Too long of an if method
// ! Switch statement could be split into different classes that inherit from Expense
// ! The content of this for loop could be extracted to a function
// ! Why would you use iterators for this simple for loop