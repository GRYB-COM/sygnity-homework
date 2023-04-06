#pragma once
#include <string>
#include <ctime>
class DateRange;
class DateRangeDaysRepo
{
public:
	
	void writeDaysCount(const int daysCount);
	DateRange readDateRange(void);
	time_t readDateFromString(const std::string& dateAsString);
private:
	const std::string FILE_IN_NAME = "input.txt";
	const std::string FILE_OUT_NAME = "output.txt";
	const std::string DATE_FORMAT = "%Y-%m-%d";

};

