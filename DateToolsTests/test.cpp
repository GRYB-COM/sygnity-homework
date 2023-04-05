#include "pch.h"
#include "..\DateTools\DateRangeDaysCounter.h"
	TEST(DateRangeDaysCounterTets, countNumberOfDaysBetweenTwoDatesTest) {
		DateTimeRoutines::DateRangeDaysCounter counter;
		EXPECT_EQ(counter.countNumberOfDaysBetweenTwoDates("", ""), -1);
		EXPECT_TRUE(true);
	}