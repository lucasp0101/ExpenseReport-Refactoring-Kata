#include <chrono>
#include <iostream>
#include <iterator>
#include "ExpenseReport.h"
#include <sstream>
#include <stdexcept>

using namespace std;

bool expenseIsMeal(Expense &expense)
{
    // ! This makes it difficult to add new types
    // ! Only here to decompose the original function into its different logic containers
    switch (expense.type)
    {
    case BREAKFAST:
        return true;

    case DINNER:
        return true;

    case CAR_RENTAL:
        return false;

    default:
        return false;
    }
}

string obtainMealOverExpensesMarker(Expense &expense)
{
    switch (expense.type)
    {
    case DINNER:
        if (expense.amount > 5000)
        {
            return "X";
        }
        return " ";
    case BREAKFAST:
        if (expense.amount > 1000)
        {
            return "X";
        }
        return " ";
    case CAR_RENTAL:
        return " ";
    default:
        throw invalid_argument("Type of expense reference is not valid: " + to_string(expense.type));
    }
}

string obtainExpenseName(Expense &expense)
{
    string expenseName = "";

    switch (expense.type)
    {
    case DINNER:
        expenseName = "Dinner";
        break;
    case BREAKFAST:
        expenseName = "Breakfast";
        break;
    case CAR_RENTAL:
        expenseName = "Car Rental";
        break;
    }
    // ! No default case

    return expenseName;
}

// * To break the dependency to time.h's ctime
string to_return = "01-01-02 00:00:00\n";
char *ctime(const time_t *__timer)
{   
    return &to_return[0];
}

int processExpense(Expense &expense, int &mealExpenses)
{
    string mealOverExpensesMarker = obtainMealOverExpensesMarker(expense);

    if (expenseIsMeal(expense))
    {
        mealExpenses += expense.amount;
    }

    string expenseName = obtainExpenseName(expense);
    
    cout << expenseName << '\t' << expense.amount << '\t' << mealOverExpensesMarker << '\n';

    return expense.amount;
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
    int total = 0;
    int mealExpenses = 0;

    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout << "Expenses " << ctime(&now);

    for (Expense &expense : expenses) {
        total += processExpense(expense, mealExpenses);
    }

    cout << "Meal expenses: " << mealExpenses << '\n';
    cout << "Total expenses: " << total << '\n';
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