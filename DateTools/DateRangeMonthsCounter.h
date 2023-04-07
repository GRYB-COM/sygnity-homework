#pragma once
struct DateRange;
struct Date;
struct MonthsCount {
	int Months;
	int Days;
};
class DateRangeMonthsCounter
{
public:
	 MonthsCount countNumberOfMonthsBetweenTwoDates(const DateRange&)const;
	 double countNumberOfMonthsBetweenTwoDatesAsDouble(const DateRange&)const;
private:
	int countOneMonthDays(const Date&)const;
	 static const int YEAR_RATIO = 31556952;
	 static const int MONTH_RATIO = 2629746;
	 static const int DAY_RATIO = 86400;
};

