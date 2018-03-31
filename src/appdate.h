#ifndef APPDATE_H
#define APPDATE_H

#define DAYS_IN_WEEK     7
#define DAYS_IN_MONTH    28
#define DAYS_IN_SEASON   91
#define DAYS_IN_YEAR     364
#define WEEKS_IN_MONTH   4
#define WEEKS_IN_SEASON  13
#define WEEKS_IN_YEAR    52
#define MONTHS_IN_YEAR   13
#define SEASONS_IN_YEAR  4

// Units of Date
#define UNIT_DAYS        1
#define UNIT_WEEKS       2
#define UNIT_MONTHS      3
#define UNIT_SEASONS     4
#define UNIT_YEARS       5
#define TOTAL_DATE_UNITS 5

class AppDate
{
public:
    AppDate();
    AppDate(int YEAR, int DAY_OF_YEAR);
    virtual ~AppDate();
    void advanceDate(int UNIT_OF_DATE, int AMOUNT);
    int getDayOfYear();
    int getDayOfMonth();
    int getDayOfWeek();
    int getWeekOfYear();
    int getWeekOfMonth();
    int getMonthOfYear();
    int getSeason();
    int getYear();
    void setDayOfYear(int DAY_OF_YEAR);
    
private:
    void initialize(int YEAR, int DAY_OF_YEAR);
    void update();
    int dayOfYear;
    int dayOfMonth;
    int dayOfWeek;
    int weekOfYear;
    int weekOfMonth;
    int monthOfYear;
    int season;
    int year;
};

#endif /* APPDATE_H */
