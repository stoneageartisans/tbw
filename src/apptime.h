#ifndef APPTIME_H
#define APPTIME_H

#define SECONDS_IN_MINUTE 60
#define MINUTES_IN_HOUR   60
#define HOURS_IN_DAY      24

// Units of Time
#define UNIT_SECONDS     1
#define UNIT_MINUTES     2
#define UNIT_HOURS       3
#define TOTAL_TIME_UNITS 3

class AppTime
{
public:
    AppTime();
    AppTime(int SECOND, int MINUTE, int HOUR);
    virtual ~AppTime();
    void advanceTime(int UNIT_OF_TIME, int AMOUNT);
    bool getIsNewDay();
    int getSecond();
    int getMinute();
    int getHour();
    void setIsNewDay(bool VALUE);
    
private:
    void initialize(int SECOND, int MINUTE, int HOUR);
    void update();
    bool isNewDay;
    int second;
    int minute;
    int hour;
};

#endif /* APPTIME_H */
