#include <chrono>
#include <iostream>
#include <iterator>
#include "ExpenseReport.h"
#include <sstream>

using namespace std;

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

    // ! Why would you use iterators for this simple for loop
    for (list<Expense>::iterator expense = expenses.begin(); expense != expenses.end(); ++expense) {
        // ! The content of this for loop could be extracted to a function
        if (expense->type == BREAKFAST || expense->type == DINNER) {
            mealExpenses += expense->amount;
        }

        // ! Switch statement could be split into different classes that inherit from Expense
        string expenseName = "";
        switch (expense->type) {
        // ! Magic strings in code
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

        // ! Magic numbers and strings in the code
        // ! Too long of an if method
        string mealOverExpensesMarker = (expense->type == DINNER && expense->amount > 5000) || (expense->type == BREAKFAST && expense->amount > 1000) ? "X" : " ";

        cout << expenseName << '\t' << expense->amount << '\t' << mealOverExpensesMarker << '\n';

        total += expense->amount;
    }

    // ! Magic string in code
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