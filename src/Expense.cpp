#include <stdexcept>
#include <iostream>
#include <string>
#include "Expense.h"

bool Expense::isMeal()
{
    return availableExpenseTypes.at(this->type).isMeal;
}

std::string Expense::obtainMealOverExpensesMarker()
{
    if (availableExpenseTypes.at(this->type).isMeal && 
        this->amount > availableExpenseTypes.at(this->type).mealOverLimitThreshold)
    {
        return mealThresholdMarkers::MEAL_OVER_THRESHOLD_MARKER;
    }

    return mealThresholdMarkers::MEAL_UNDER_THRESHOLD_MARKER;
}

std::string Expense::obtainExpenseName()
{
    return availableExpenseTypes.at(this->type).name;
}

std::string Expense::toString()
{
    std::string mealOverExpensesMarker = this->obtainMealOverExpensesMarker();

    std::string expenseName = this->obtainExpenseName();
    
    return expenseName + '\t' + std::to_string(this->amount) + '\t' + mealOverExpensesMarker + '\n';
}