#include "pch.h"
#include "DateRangeRepo.h"
#include <fstream>
#include <ios>
#include "DateRange.h"
#include <sstream>
#include <iomanip>

DateRange DateRangeRepo::readDateRange(void)
{
    std::ifstream fileToRead(FILE_IN_NAME);
    DateRange result;
    if (fileToRead.is_open())
    {
        std::string dateAsString;
        std::getline(fileToRead, dateAsString);
        result.DateFrom = readDateFromString(dateAsString);
        std::getline(fileToRead, dateAsString);
        result.DateTo = readDateFromString(dateAsString);
    }
    else throw std::ios_base::failure("Nie uda³o siê otworzyæ pliku z zakresem dat.\n\r\tNazwa pliku: " + FILE_IN_NAME);
    fileToRead.close();
    return result;
}

Date DateRangeRepo::readDateFromString(const std::string& dateAsString)
{
 
    std::tm dateAsTM = {0,0,0,0,0,0,0,0,0};
    std::istringstream dateAsStream(dateAsString);
    dateAsStream.imbue(std::locale("pl_PL.utf-8"));
    dateAsStream >> std::get_time(&dateAsTM, DATE_FORMAT.c_str());
    if (dateAsStream.fail()) throw std::runtime_error("B³¹d parsowania daty:" + dateAsString + " "+ dateAsStream.str());
    Date result;
    result.Year = dateAsTM.tm_year + 1900;
    result.Month = dateAsTM.tm_mon+1;
    result.Day = dateAsTM.tm_mday;
    return result;
}

void DateRangeRepo::writeMonthsCount(const int monthsCount)
{
    // TODO: Add your implementation code here.
}

