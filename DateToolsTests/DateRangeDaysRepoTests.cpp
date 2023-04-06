#include "pch.h"
#include "gtest/gtest.h"
#include "../DateTools/DateRangeDaysRepo.h"
TEST(DateRangeDaysRepoTests, readDateFromString) {
  
	std::tm tmFrom;
	tmFrom.tm_year = 123;
	tmFrom.tm_mon = 0;
	tmFrom.tm_mday = 1;
	tmFrom.tm_hour = 0;
	tmFrom.tm_min = 0;
	tmFrom.tm_sec = 0;
	tmFrom.tm_wday = 0;
	tmFrom.tm_yday = 0;
	tmFrom.tm_isdst = 0;
	std::time_t timeFrom = std::mktime(&tmFrom);
	DateRangeDaysRepo repo;
	
	EXPECT_EQ(repo.readDateFromString("2023-01-01"),timeFrom);
  
}