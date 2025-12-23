#define APPROVALS_CATCH2_V3
#include <ApprovalTests.hpp>
#include "ExpenseReport.h"

using namespace std;

// This puts "received" and "approved" files in approval_tests/ sub-directory,
// keeping the test source directory tidy:
auto directoryDisposer =
    ApprovalTests::Approvals::useApprovalsSubdirectory("approval_tests");

    
TEST_CASE("ExpenseReportApprovalTests", "VerifyCombinations")
{
    vector<vector<Expense>> expense_combinations =
    {
    };

    auto f = [](vector<Expense> expenses) {
        return printReport(expenses);
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(
            f,
            expense_combinations);
}
