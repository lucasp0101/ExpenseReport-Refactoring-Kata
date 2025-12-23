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
    std::list<std::list<Expense>> expense_combinations =
    {
        {Expense(Type::BREAKFAST, 12)}
    };

    auto f = [](std::list<Expense> expenses) {
        return printReportWrapper(expenses);
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(
            f,
            expense_combinations);
}
