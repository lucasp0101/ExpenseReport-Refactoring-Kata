#ifndef EXPENSEREPORT_H
#define EXPENSEREPORT_H

#include <list>

using namespace std;

enum Type
{
    BREAKFAST, DINNER, CAR_RENTAL
};

class Expense
{
public:
    Type type;
    int amount;
    // ! No constructor for the class
    Expense(Type type, int amount) : type(type), amount(amount)
    {}
};

extern void printReport(list<Expense> expenses);
extern string printReportWrapper(list<Expense> expenses);
#endif
