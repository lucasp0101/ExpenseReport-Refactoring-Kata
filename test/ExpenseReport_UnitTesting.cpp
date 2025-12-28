#include <catch2/catch_test_macros.hpp>
#include "Expense.h"
#include "ExpenseReport.h"

TEST_CASE("A list with one lunch expense under the limit is correctly printed", "Basic Lunch test") 
{
    std::string correct_output = "Expenses 01-01-02 00:00:00\nLunch	2000	 \nMeal expenses: 2000\nTotal expenses: 2000\n";
    std::list<Expense> expenses_list;
    expenses_list.push_back(Expense(Type::LUNCH, 2000));
    REQUIRE(printReportWrapper(expenses_list) == correct_output);
};

TEST_CASE("A list with multiple expenses including a lunch expense over the limit is correclty printed", "Multiple expenses + over the limit")
{
    std::string correct_output = "Expenses 01-01-02 00:00:00\nLunch	2001	X\nDinner	1	 \nMeal expenses: 2002\nTotal expenses: 2002\n";
    std::list<Expense> expenses_list;
    expenses_list.push_back(Expense(Type::LUNCH, 2001));
    expenses_list.push_back(Expense(Type::DINNER, 1));
    REQUIRE(printReportWrapper(expenses_list) == correct_output);
}

TEST_CASE("A list with a lunch expense under the limit and a non-meal expense. The expense distribution is correctly computed", "Lunch is considered meal")
{
    std::string correct_output = "Expenses 01-01-02 00:00:00\nLunch	1	 \nCar Rental	1	 \nMeal expenses: 1\nTotal expenses: 2\n";
    std::list<Expense> expenses_list;
    expenses_list.push_back(Expense(Type::LUNCH, 1));
    expenses_list.push_back(Expense(Type::CAR_RENTAL, 1));
    REQUIRE(printReportWrapper(expenses_list) == correct_output);
}


