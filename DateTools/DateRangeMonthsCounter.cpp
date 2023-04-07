#include "pch.h"
#include "DateRangeMonthsCounter.h"
#include "DateRange.h"
#include <chrono>
MonthsCount DateRangeMonthsCounter::countNumberOfMonthsBetweenTwoDates(const DateRange& dateRange) const
{
    std::time_t secondsDuration = dateRange.DateTo.Seconds - dateRange.DateFrom.Seconds;
    std::chrono::duration<long long, std::ratio<1>> differrenceInSeconds(secondsDuration);
    auto differrenceInYears = std::chrono::duration_cast<std::chrono::duration<long long, std::ratio<YEAR_RATIO>>>(differrenceInSeconds);
    auto yearDifferenceInSeconds = std::chrono::duration_cast<std::chrono::duration<long long, std::ratio<1>>>(differrenceInYears);
    auto leaveMonthDifferrenceInSeconds = differrenceInSeconds - yearDifferenceInSeconds;
    auto differrenceInMonths = std::chrono::duration_cast<std::chrono::duration<long long, std::ratio<MONTH_RATIO>>>(leaveMonthDifferrenceInSeconds);
    auto monthsDiferenceInSeconds = std::chrono::duration_cast<std::chrono::duration<long long, std::ratio<1>>>(differrenceInMonths);
    auto leaveDaysDifferenceInSeconds = leaveMonthDifferrenceInSeconds - monthsDiferenceInSeconds;
    auto leaveDaysDifferrence = std::chrono::ceil<std::chrono::duration<long long, std::ratio<DAY_RATIO>>>(leaveDaysDifferenceInSeconds);
    MonthsCount result = { 12*differrenceInYears.count() + differrenceInMonths.count(),leaveDaysDifferrence.count()};
    return result;
}

double DateRangeMonthsCounter::countNumberOfMonthsBetweenTwoDatesAsDouble(const DateRange& dateRange) const
{
    MonthsCount monthsCount = countNumberOfMonthsBetweenTwoDates(dateRange);
    double monthsCountAsDouble = monthsCount.Months;
    int daysInMonth = countOneMonthDays(dateRange.DateTo);
    monthsCountAsDouble += ((double)monthsCount.Days) / daysInMonth;
    return monthsCountAsDouble;
}

int DateRangeMonthsCounter::countOneMonthDays(const Date& date) const
{
    int month = date.Month;
    int daysInMonth = 0;
    if (month < 7) daysInMonth = month % 2 == 1 ? 31 : 30;
    else daysInMonth = month % 2 == 0 ? 31 : 30;
    return daysInMonth;
}
