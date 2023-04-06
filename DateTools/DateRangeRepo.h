#pragma once
#include <string>
struct DateRange;
struct Date;
class DateRangeRepo
{
public:
	
	void writeMonthsCount(const int monthsCount);
	DateRange readDateRange(void);
	Date readDateFromString(const std::string& dateAsString);
private:
	const std::string FILE_IN_NAME = "input.txt";
	const std::string FILE_OUT_NAME = "output.txt";
	const std::string DATE_FORMAT = "%Y-%m-%d";

};

