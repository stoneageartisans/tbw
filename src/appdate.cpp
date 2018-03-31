#include "appdate.h"

AppDate::AppDate()
{
    initialize(1, 1);
}

AppDate::AppDate(int YEAR, int DAY_OF_YEAR)
{
    initialize(YEAR, DAY_OF_YEAR);
}

AppDate::~AppDate()
{
    // TODO
}

void AppDate::advanceDate(int UNIT_OF_DATE, int AMOUNT)
{
    int numberOfDays = 0;
    
    switch(UNIT_OF_DATE)
    {
        case UNIT_DAYS:
            numberOfDays = AMOUNT;
            break;
        case UNIT_WEEKS:
            numberOfDays = AMOUNT * DAYS_IN_WEEK;
            break;
        case UNIT_MONTHS:
            numberOfDays = AMOUNT * DAYS_IN_MONTH;
            break;
        case UNIT_SEASONS:
            numberOfDays = AMOUNT * DAYS_IN_SEASON;
            break;
        case UNIT_YEARS:
            numberOfDays = AMOUNT * DAYS_IN_YEAR;
            break;
        default:
            break;
    }
    
    dayOfYear = dayOfYear + numberOfDays;
    
    update();
}

int AppDate::getDayOfMonth()
{
    return dayOfMonth;
}

int AppDate::getDayOfWeek()
{
    return dayOfWeek;
}

int AppDate::getDayOfYear()
{
    return dayOfYear;
}

int AppDate::getMonthOfYear()
{
    return monthOfYear;
}

int AppDate::getSeason()
{
    return season;
}

int AppDate::getWeekOfMonth()
{
    return weekOfMonth;
}

int AppDate::getWeekOfYear()
{
    return weekOfYear;
}

int AppDate::getYear()
{
    return year;
}

void AppDate::initialize(int YEAR, int DAY_OF_YEAR)
{
    year = YEAR;
    
    if(DAY_OF_YEAR > DAYS_IN_YEAR)
    {
        dayOfYear = DAYS_IN_YEAR;
    }
    else
    {
        dayOfYear = DAY_OF_YEAR;
    }    
    
    update();
}

void AppDate::update()
{
    // Day of Year (1 to 364)
    while(dayOfYear > DAYS_IN_YEAR)
    {
        year ++;
        dayOfYear = dayOfYear - DAYS_IN_YEAR;
    }
    
    // Day of Month (1 to 28)
    dayOfMonth = ((dayOfYear + DAYS_IN_MONTH - 1) % DAYS_IN_MONTH) + 1;
    
    // Day of Week (1 to 7)
    if((dayOfMonth == 1) || (dayOfMonth == 8) || (dayOfMonth == 15) || (dayOfMonth == 22))
    {
        dayOfWeek = 1;
    }
    else if((dayOfMonth == 2) || (dayOfMonth == 9) || (dayOfMonth == 16) || (dayOfMonth == 23))
    {
        dayOfWeek = 2;
    }
    else if((dayOfMonth == 3) || (dayOfMonth == 10) || (dayOfMonth == 17) || (dayOfMonth == 24))
    {
        dayOfWeek = 3;
    }
    else if((dayOfMonth == 4) || (dayOfMonth == 11) || (dayOfMonth == 18) || (dayOfMonth == 25))
    {
        dayOfWeek = 4;
    }
    else if((dayOfMonth == 5) || (dayOfMonth == 12) || (dayOfMonth == 19) || (dayOfMonth == 26))
    {
        dayOfWeek = 5;
    }
    else if((dayOfMonth == 6) || (dayOfMonth == 13) || (dayOfMonth == 20) || (dayOfMonth == 27))
    {
        dayOfWeek = 6;
    }
    else if((dayOfMonth == 7) || (dayOfMonth == 14) || (dayOfMonth == 21) || (dayOfMonth == 28))
    {
        dayOfWeek = 7;
    }
    else
    {
        dayOfWeek = 0;
    }    
    
    // Week of Year (1 to 52)
    weekOfYear = ((dayOfYear - 1) / DAYS_IN_WEEK) + 1;
    
    // Week of Month (1 to 4)
    if((dayOfMonth > 0) && (dayOfMonth < 8))
    {
        weekOfMonth = 1;
    }
    else if((dayOfMonth > 7) && (dayOfMonth < 15))
    {
         weekOfMonth = 2;
    }
    else if((dayOfMonth > 14) && (dayOfMonth < 22))
    {
         weekOfMonth = 3;
    }
    else if((dayOfMonth > 21) && (dayOfMonth < 29))
    {
         weekOfMonth = 4;
    }
    else
    {
        weekOfMonth = 0;
    }
    
    // Month of Year (1 to 13)
    if((dayOfYear > 0) && (dayOfYear < 29))
    {
        monthOfYear = 1;
    }
    else if((dayOfYear > 28) && (dayOfYear < 57))
    {
        monthOfYear = 2;
    }
    else if((dayOfYear > 56) && (dayOfYear < 85))
    {
        monthOfYear = 3;
    }
    else if((dayOfYear > 84) && (dayOfYear < 113))
    {
        monthOfYear = 4;
    }
    else if((dayOfYear > 112) && (dayOfYear < 141))
    {
        monthOfYear = 5;
    }
    else if((dayOfYear > 140) && (dayOfYear < 169))
    {
        monthOfYear = 6;
    }
    else if((dayOfYear > 168) && (dayOfYear < 197))
    {
        monthOfYear = 7;
    }
    else if((dayOfYear > 196) && (dayOfYear < 225))
    {
        monthOfYear = 8;
    }
    else if((dayOfYear > 224) && (dayOfYear < 253))
    {
        monthOfYear = 9;
    }
    else if((dayOfYear > 252) && (dayOfYear < 281))
    {
        monthOfYear = 10;
    }
    else if((dayOfYear > 280) && (dayOfYear < 309))
    {
        monthOfYear = 11;
    }
    else if((dayOfYear > 308) && (dayOfYear < 337))
    {
        monthOfYear = 12;
    }
    else if((dayOfYear > 336) && (dayOfYear < 365))
    {
        monthOfYear = 13;
    }
    else
    {
        monthOfYear = 0;
    }
    
    // Season of Year (1 to 4)
    if((dayOfYear > 0) && (dayOfYear < 92))
    {
        season = 1;
    }
    else if((dayOfYear > 91) && (dayOfYear < 183))
    {
        season = 2;
    }
    else if((dayOfYear > 182) && (dayOfYear < 274))
    {
        season = 3;
    }
    else if((dayOfYear > 273) && (dayOfYear < 365))
    {
        season = 4;
    }
    else
    {
        season = 0;
    }
}

void AppDate::setDayOfYear(int DAY_OF_YEAR)
{
    dayOfYear = DAY_OF_YEAR;
    update();
}
