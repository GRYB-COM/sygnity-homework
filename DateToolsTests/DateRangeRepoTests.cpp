#include "pch.h"
#include "gtest/gtest.h"
#include "../DateTools/DateRangeRepo.h"
#include "../DateTools/DateRange.h"
TEST(DateRangeRepoTests, readDateFromString) {
  
	DateRangeRepo repo;
	Date dateR = { 2023,01,01 };
	Date dateL = repo.readDateFromString("2023-01-01");
	EXPECT_EQ(dateL.Year, dateR.Year);
	EXPECT_EQ(dateL.Month, dateR.Month);
	EXPECT_EQ(dateL.Day, dateR.Day);

}