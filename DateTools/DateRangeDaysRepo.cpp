#include "pch.h"
#include "DateRangeDaysRepo.h"
#include <fstream>
#include <ios>
#include "DateRange.h"
#include <sstream>
#include <iomanip>

DateRange DateRangeDaysRepo::readDateRange(void)
{
    std::ifstream fileToRead(FILE_IN_NAME);
    DateRange result;
    if (fileToRead.is_open())
    {
        std::string dateAsString;
        std::getline(fileToRead, dateAsString);
        result.first = readDateFromString(dateAsString);
        std::getline(fileToRead, dateAsString);
        result.second = readDateFromString(dateAsString);
    }
    else throw std::ios_base::failure("Nie uda�o si� otworzy� pliku z zakresem dat.\n\r\tNazwa pliku: " + FILE_IN_NAME);
    fileToRead.close();
    return result;
}

time_t DateRangeDaysRepo::readDateFromString(const std::string& dateAsString)
{
 
    std::tm dateAsTM = {0,0,0,0,0,0,0,0,0};
    std::istringstream dateAsStream(dateAsString);
    dateAsStream.imbue(std::locale("pl_PL.utf-8"));
    dateAsStream >> std::get_time(&dateAsTM, DATE_FORMAT.c_str());
    if (dateAsStream.fail()) throw std::runtime_error("B��d parsowania daty:" + dateAsString + " "+ dateAsStream.str());
    return std::mktime(&dateAsTM);
}

void DateRangeDaysRepo::writeDaysCount(const int daysCount)
{
    // TODO: Add your implementation code here.
}

