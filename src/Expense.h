#pragma once

#include <string>
#include <iostream>

enum Type
{
    BREAKFAST, DINNER, CAR_RENTAL
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