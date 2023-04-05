#pragma once
#include <string>
#include <ctime>
namespace DateTimeRoutines {
	class DateRangeDaysCounter
	{
	public:
		DateRangeDaysCounter(void);
		int countNumberOfDaysBetweenTwoDates(const std::time_t& dateFrom, const std::time_t& dateTo)const;
	private:
		static const int DAY_RATIO = 86400;
	};
}
