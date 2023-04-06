#include "pch.h"
#include "gtest/gtest.h"
#include "../DateTools/DateRangeMonthsCounter.h"
#include "../DateTools/DateRange.h"
TEST(DateRangeMonthsCounterTests, countNumberOfMonthsBetweenTwoDates) {
	DateRangeMonthsCounter counter;
	DateRange range = { {0,0,0},{0,0,0} };
	EXPECT_EQ(counter.countNumberOfMonthsBetweenTwoDates(range), 0);
 
}