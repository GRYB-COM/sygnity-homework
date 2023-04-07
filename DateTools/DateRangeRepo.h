#pragma once
#include <string>
struct DateRange;
struct Date;
class DateRangeRepo
{
public:
	
	bool writeMonthsCount(const double monthsCount);
	DateRange readDateRange(void);
	Date readDateFromString(const std::string& dateAsString);
private:
	const std::wstring FILE_IN_NAME = L"input.txt";
	const std::wstring FILE_OUT_NAME = L"output.txt";
	const std::string DATE_FORMAT = "%Y-%m-%d";
	std::wstring readExePath(void);


};

