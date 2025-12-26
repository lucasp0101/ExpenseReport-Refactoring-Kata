#include <stdexcept>
#include <iostream>
#include <string>
#include "Expense.h"


bool Expense::isMeal()
{
    // ! This makes it difficult to add new types
    // ! Only here to decompose the original function into its different logic containers
    switch (this->type)
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

std::string Expense::obtainMealOverExpensesMarker()
{
    switch (this->type)
    {
    case DINNER:
        if (this->amount > 5000)
        {
            return "X";
        }
        return " ";
    case BREAKFAST:
        if (this->amount > 1000)
        {
            return "X";
        }
        return " ";
    case CAR_RENTAL:
        return " ";
    default:
        throw std::invalid_argument("Type of expense reference is not valid: " + std::to_string(this->type));
    }
}

std::string Expense::obtainExpenseName()
{
    std::string expenseName = "";

    switch (this->type)
    {
    case DINNER:
        return "Dinner";
    case BREAKFAST:
        return "Breakfast";
    case CAR_RENTAL:
        return "Car Rental";
    default:
        throw std::invalid_argument("Type of expense reference is not valid: " + std::to_string(this->type));
    }
}

std::string Expense::toString()
{
    std::string mealOverExpensesMarker = this->obtainMealOverExpensesMarker();

    std::string expenseName = this->obtainExpenseName();
    
    return expenseName + '\t' + std::to_string(this->amount) + '\t' + mealOverExpensesMarker + '\n';
}