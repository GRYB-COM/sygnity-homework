#include "pch.h"
#include <ctime>
#include "..\DateTools\DateRangeDaysCounter.h"
	TEST(DateRangeDaysCounterTets, countNumberOfDaysBetweenTwoDatesTest) {
		DateTimeRoutines::DateRangeDaysCounter counter;
		std::tm tmFrom;
		tmFrom.tm_year = 122;
		tmFrom.tm_mon = 0;
		tmFrom.tm_mday = 1;
		tmFrom.tm_hour = 0;
		tmFrom.tm_min = 0;
		tmFrom.tm_sec = 0;
		tmFrom.tm_wday = 0;
		tmFrom.tm_yday = 0;
		tmFrom.tm_isdst = 0;
		std::tm tmTo;
		tmTo.tm_year = 123;
		tmTo.tm_mon = 1;
		tmTo.tm_mday = 28;
		tmTo.tm_hour = 0;
		tmTo.tm_min = 0;
		tmTo.tm_sec = 0;
		tmTo.tm_wday = 0;
		tmTo.tm_yday = 0;
		tmTo.tm_isdst = 0;
		std::time_t timeFrom = std::mktime(&tmFrom);
		std::time_t timeTo = std::mktime(&tmTo);
		EXPECT_EQ(counter.countNumberOfDaysBetweenTwoDates(timeFrom, timeTo), 423);
		EXPECT_TRUE(true);
	}