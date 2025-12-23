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
        {},
        {Expense(type)}

    }

    auto f = [](std::string name, int sellIn, int quality) {
        std::vector<Item> items = {Item(name, sellIn, quality)};
        GildedRose app(items);
        app.updateQuality();
        return items[0];
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(
            f,
            names, sellIns, qualities);
}
