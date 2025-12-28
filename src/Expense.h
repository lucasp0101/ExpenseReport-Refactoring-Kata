#pragma once

#include <string>
#include <iostream>
#include <map>

namespace mealThresholdMarkers
{
    const std::string MEAL_UNDER_THRESHOLD_MARKER = " ";
    const std::string MEAL_OVER_THRESHOLD_MARKER = "X";
}

enum Type
{
    BREAKFAST, DINNER, CAR_RENTAL, LUNCH
};

struct ExpenseTypeDetails 
{
    Type type;
    std::string name;
    bool isMeal;
    int mealOverLimitThreshold;
};

// ! This could be read from a file to further ease the process of adding new expenses
// ! But it is trivial so I wont do it
// TODO First create the unit tests to for the new feature, then add it.
// TODO --> Add Lunch with an expense limit of 2000.
const std::map<Type, ExpenseTypeDetails> availableExpenseTypes = 
{
    {Type::BREAKFAST, {BREAKFAST, "Breakfast", true, 1000}},
    {Type::DINNER, {DINNER, "Dinner", true, 5000}},
    {Type::CAR_RENTAL, {CAR_RENTAL, "Car Rental", false, 0}},
    {Type::LUNCH, {LUNCH, "Lunch", true, 2000}}
};


class Expense
{
private:
    Type type;
    int amount;
public:
    Expense(Type type, int amount) : type(type), amount(amount)
    {}

    bool isMeal();

    std::string obtainMealOverExpensesMarker();

    std::string obtainExpenseName();

    std::string toString();

    int getAmount()
    {
        return this->amount;
    }

    Type getType()
    {
        return this->type;
    }
};