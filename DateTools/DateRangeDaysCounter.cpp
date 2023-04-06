#include "pch.h"
#include "DateRangeDaysCounter.h"
#include <chrono>
using namespace DateTimeRoutines;
DateRangeDaysCounter::DateRangeDaysCounter(void)
{

}

int DateRangeDaysCounter::countNumberOfDaysBetweenTwoDates(const std::time_t& dateFrom, const std::time_t& dateTo)const
{
	std::chrono::system_clock::time_point dateFromTP;
	std::chrono::duration<long, std::ratio<1>> differrenceInSeconds(dateTo - dateFrom);
	auto differenceInDays = std::chrono::duration_cast<std::chrono::duration<long, std::ratio<DAY_RATIO>>>(differrenceInSeconds);


	return differenceInDays.count();

}
