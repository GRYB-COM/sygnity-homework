#include "pch.h"
#include "gtest/gtest.h"
#include "../DateTools/DateRangeRepo.h"
#include "../DateTools/DateRange.h"
TEST(DateRangeRepoTests, readDateFromString) {
  
	DateRangeRepo repo;
	Date dateR = { 2023,01,01 };
	Date dateL = repo.readDateFromString("2023-01-01");
	EXPECT_EQ(dateL.Year, dateR.Year);
	EXPECT_EQ(dateL.Month, dateR.Month);
	EXPECT_EQ(dateL.Day, dateR.Day);

}

TEST(DateRangeRepoTests, readDateRange) {

	DateRangeRepo repo;
	Date dateFrom = { 2023,01,01 };
	Date dateTo = { 2023,12,31 };
	DateRange dateRange = repo.readDateRange();
	EXPECT_EQ(dateRange.DateFrom.Year, dateFrom.Year);
	EXPECT_EQ(dateRange.DateFrom.Month, dateFrom.Month);
	EXPECT_EQ(dateRange.DateFrom.Day, dateFrom.Day);

	EXPECT_EQ(dateRange.DateTo.Year, dateTo.Year);
	EXPECT_EQ(dateRange.DateTo.Month, dateTo.Month);
	EXPECT_EQ(dateRange.DateTo.Day, dateTo.Day);

}
TEST(DateRangeRepoTests, writeMonthsCount) {

	DateRangeRepo repo;
	EXPECT_TRUE(repo.writeMonthsCount(0.064517));

}