#include "pch.h"
#include "DateRangeRepo.h"
#include <fstream>
#include <ios>
#include "DateRange.h"
#include <sstream>
#include <iomanip>
#include <windows.h>
DateRange DateRangeRepo::readDateRange(void)
{
    std::ifstream fileToRead(readExePath()+ L"\\"+ FILE_IN_NAME);
    DateRange result;
    if (fileToRead.is_open())
    {
        std::string dateAsString;
        std::getline(fileToRead, dateAsString);
        result.DateFrom = readDateFromString(dateAsString);
        std::getline(fileToRead, dateAsString);
        result.DateTo = readDateFromString(dateAsString);
    }
    else
    {
        std::string message = "Nie uda³o siê otworzyæ pliku z zakresem dat.\n\r\tNazwa pliku: ";
        //message += std::string( FILE_IN_NAME.c_str());
        throw std::ios_base::failure(message);
    }
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
    result.Seconds = std::mktime(&dateAsTM);
    return result;
}
std::wstring DateRangeRepo :: readExePath(void) {
    TCHAR buffer[MAX_PATH] = { 0 };
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
    return std::wstring(buffer).substr(0, pos);
}


void DateRangeRepo::writeMonthsCount(const int monthsCount)
{
    // TODO: Add your implementation code here.
}

