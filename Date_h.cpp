#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
public:
    // Error codes to help tests print "Month invalid", "Day invalid", etc.
    enum class Error { NONE, MONTH_INVALID, DAY_INVALID, YEAR_INVALID };

    // Default date per spec: 1/1/1900
    static constexpr int DEFAULT_MONTH = 1;
    static constexpr int DEFAULT_DAY   = 1;
    static constexpr int DEFAULT_YEAR  = 1900;

    // Constructor with default parameters; validates via setDate
    Date(int m = DEFAULT_MONTH, int d = DEFAULT_DAY, int y = DEFAULT_YEAR);

    // Mutator with validation. Returns true if set; otherwise sets to default and returns false.
    bool setDate(int m, int d, int y);

    // Accessors (inline/simple)
    int  getMonth() const { return month_; }
    int  getDay()   const { return day_; }
    int  getYear()  const { return year_; }

    // Leap year checks (two overloads)
    bool        isLeapYear() const { return isLeapYear(year_); }
    static bool isLeapYear(int year);

    // Last day of month (two overloads)
    int         lastDay() const { return lastDay(month_, year_); }
    static int  lastDay(int month, int year);

    // Print formats
    std::string formatSlash()        const; // "12/25/2021"
    std::string formatLong()         const; // "December 25, 2021"
    std::string formatDayMonthYear() const; // "25 December 2021"

    // Error info from the last set/construct
    Error              lastError() const { return lastError_; }
    std::string        lastErrorMessage() const;

private:
    int   month_, day_, year_;
    Error lastError_ { Error::NONE };

    static Error validate(int m, int d, int y);
    static const char* monthName(int m);
};

#endif // DATE_H
