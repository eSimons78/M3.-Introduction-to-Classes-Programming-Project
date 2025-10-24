#include "Date.h"
#include <array>
#include <sstream>

Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

bool Date::setDate(int m, int d, int y) {
    Error e = validate(m, d, y);
    if (e != Error::NONE) {
        // Invalid => set to default
        month_ = DEFAULT_MONTH;
        day_   = DEFAULT_DAY;
        year_  = DEFAULT_YEAR;
        lastError_ = e;
        return false;
    }
    month_ = m;
    day_   = d;
    year_  = y;
    lastError_ = Error::NONE;
    return true;
}

bool Date::isLeapYear(int year) {
    if (year <= 0) return false; // Treat non-positive as not-leap for validation
    // Leap-year rule: divisible by 4, except centuries not divisible by 400
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int Date::lastDay(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2:  return isLeapYear(year) ? 29 : 28;
        default: return 31; // Fallback; month validity is checked elsewhere
    }
}

std::string Date::formatSlash() const {
    std::ostringstream os;
    os << month_ << '/' << day_ << '/' << year_;
    return os.str();
}

std::string Date::formatLong() const {
    std::ostringstream os;
    os << monthName(month_) << ' ' << day_ << ", " << year_;
    return os.str();
}

std::string Date::formatDayMonthYear() const {
    std::ostringstream os;
    os << day_ << ' ' << monthName(month_) << ' ' << year_;
    return os.str();
}

Date::Error Date::validate(int m, int d, int y) {
    if (y <= 0) return Error::YEAR_INVALID;
    if (m < 1 || m > 12) return Error::MONTH_INVALID;
    int ld = lastDay(m, y);
    if (d < 1 || d > ld) return Error::DAY_INVALID;
    return Error::NONE;
}

const char* Date::monthName(int m) {
    static const std::array<const char*, 13> names = {
        "", "January","February","March","April","May","June",
        "July","August","September","October","November","December"
    };
    return (m >= 1 && m <= 12) ? names[m] : "January";
}

std::string Date::lastErrorMessage() const {
    switch (lastError_) {
        case Error::NONE:          return "OK";
        case Error::MONTH_INVALID: return "Month invalid";
        case Error::DAY_INVALID:   return "Day invalid";
        case Error::YEAR_INVALID:  return "Year invalid";
    }
    return "Unknown error";
}
