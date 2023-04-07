#pragma once
#include <ctime>
struct Date {
	int Year;
	int Month;
	int Day;
	time_t Seconds;
};
struct DateRange{
	Date DateFrom;
	Date DateTo;
};
