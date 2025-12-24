#define APPROVALS_CATCH2_V3
#include <ApprovalTests.hpp>
#include "ExpenseReport.h"

// This puts "received" and "approved" files in approval_tests/ sub-directory,
// keeping the test source directory tidy:
auto directoryDisposer =
    ApprovalTests::Approvals::useApprovalsSubdirectory("approval_tests");


std::ostream& operator<<(std::ostream& os, const list<Expense>& expenses)
{
    os << "[";
    for (Expense expense : expenses)
    {
        os << "(type: " << expense.type << " amount: " << expense.amount << ")";
    }
    os << "]";
    
    return os;
}

TEST_CASE("ExpenseReportApprovalTests", "VerifyCombinations")
{
    std::vector<std::list<Expense>> expense_combinations =
    {
        {Expense(Type::BREAKFAST, 12)},
        {Expense(Type::CAR_RENTAL, 12)},
        {Expense(Type::DINNER, 12)},
        {Expense(Type::BREAKFAST, 1), Expense(Type::CAR_RENTAL, 1)},
        {Expense(Type::CAR_RENTAL, 1), Expense(Type::DINNER, 1)},
        {Expense(Type::BREAKFAST, 1), Expense(Type::DINNER, 1)},
        {Expense(Type::BREAKFAST, 1), Expense(Type::CAR_RENTAL, 1), Expense(Type::DINNER, 1)},
        {Expense(Type::BREAKFAST, 1), Expense(Type::DINNER, 5001)},
        {Expense(Type::BREAKFAST, 1001), Expense(Type::DINNER, 1)},
    };

    auto f = [](std::list<Expense> expenses) {
        return printReportWrapper(expenses);
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(
            f,
            expense_combinations);
}
