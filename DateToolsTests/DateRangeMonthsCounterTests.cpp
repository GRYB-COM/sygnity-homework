#include "pch.h"
#include "gtest/gtest.h"
#include "../DateTools/DateRangeMonthsCounter.h"
#include "../DateTools/DateRange.h"
#include "../DateTools/DateRangeRepo.h"
#include <cmath>
TEST(DateRangeMonthsCounterTests, countNumberOfMonthsBetweenTwoDates) {
	DateRangeMonthsCounter counter;
	DateRange range = { {1,2,3,0},{4,5,6,102629746} };
	EXPECT_EQ(counter.countNumberOfMonthsBetweenTwoDates(range).Months, 39);
 
}

TEST(DateRangeMonthsCounterTests, countNumberOfMonthsBetweenTwoDates1) {
	DateRangeMonthsCounter counter;
	DateRangeRepo repo;
	DateRange range = { repo.readDateFromString("2022-08-16"),repo.readDateFromString("2023-04-07")};
	EXPECT_EQ(counter.countNumberOfMonthsBetweenTwoDates(range).Months, 7);
	EXPECT_EQ(counter.countNumberOfMonthsBetweenTwoDates(range).Days, 21);

}

TEST(DateRangeMonthsCounterTests, countNumberOfMonthsBetweenTwoDates3) {
	DateRangeMonthsCounter counter;
	DateRangeRepo repo;
	DateRange range = repo.readDateRange();
	EXPECT_EQ(counter.countNumberOfMonthsBetweenTwoDates(range).Months, 11);
	EXPECT_EQ(counter.countNumberOfMonthsBetweenTwoDates(range).Days, 30);

}
TEST(DateRangeMonthsCounterTests, countNumberOfMonthsBetweenTwoDatesAsDouble) {
	DateRangeMonthsCounter counter;
	DateRangeRepo repo;
	DateRange range = { repo.readDateFromString("2020-12-01"),repo.readDateFromString("2020-12-03") };
	double  monthsCount = counter.countNumberOfMonthsBetweenTwoDatesAsDouble(range);
	monthsCount = std::round(monthsCount * 100) / 100;
	EXPECT_EQ(monthsCount, 0.06);

}