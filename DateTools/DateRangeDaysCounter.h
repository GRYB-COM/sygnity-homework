#pragma once
#include <string>
namespace DateTimeRoutines {
	class DateRangeDaysCounter
	{
	public:
		DateRangeDaysCounter(void);
		int countNumberOfDaysBetweenTwoDates(const std::string& dateFrom, const std::string& dateTo);
	private:
	};
}
