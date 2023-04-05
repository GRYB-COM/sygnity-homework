#include "pch.h"
#include "DateRangeDaysCounter.h"
#include <chrono>
using namespace DateTimeRoutines;
DateRangeDaysCounter::DateRangeDaysCounter(void)
{

}

int DateRangeDaysCounter::countNumberOfDaysBetweenTwoDates(const std::time_t& dateFrom, const std::time_t& dateTo)const
{

	std::chrono::duration<long long, std::ratio<DAY_RATIO>> diff(dateTo - dateFrom);
	return diff.count();

}
