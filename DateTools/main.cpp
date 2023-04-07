#include "pch.h"
#include <iostream>
#include <iomanip>
#include "DateRange.h"
#include "DateRangeRepo.h"
#include "DateRangeMonthsCounter.h"
#include <exception>
int main()
{
	try {
		DateRangeRepo dateRangeRepo;
		DateRange dateRange = dateRangeRepo.readDateRange();
		DateRangeMonthsCounter monthsCounter;
		double monthsCount = monthsCounter.countNumberOfMonthsBetweenTwoDatesAsDouble(dateRange);
		dateRangeRepo.writeMonthsCount(monthsCount);
		std::cout << "Operacja wykonała się prawidłowo"<<std::endl;
		std::cout << "Obliczona liczba miesięcy: ";
		std::cout << std::fixed << std::setprecision(2)<<monthsCount<<std::endl;
		std::cout << "Naciśnij enter" << std::endl;
		std::cin.get();
		exit(0);
	}
	catch (std::exception& exc)
	{
		std::cout << "Operacja zakończyła się błędem o następującej treści:" << std::endl;
		std::cout << exc.what() << std::endl;
		std::cout << "Naciśnij enter" << std::endl;
		std::cin.get();
		exit(-1);
	}
}
