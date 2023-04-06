#pragma once
#include <string>
namespace std {
	class time_t;
}
class DateRange;
class DateRangeDaysRepo
{
public:
	
	void writeDaysCount(const int daysCount);
	DateRange readDateRange(void);
private:
	const std::string FILE_IN_NAME = "input.txt";
	const std::string FILE_OUT_NAME = "output.txt";
	const std::string DATE_FORMAT = "% Y - % b - % d";
	time_t readDateFromString(const std::string& dateAsString);
};

