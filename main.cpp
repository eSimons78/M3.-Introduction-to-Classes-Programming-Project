#include <iostream>
#include "Date.h"

static void printIfError(const Date& d) {
    if (d.lastError() != Date::Error::NONE) {
        std::cout << d.lastErrorMessage() << "\n";
    }
}

int main() {
    // Test default constructor
    Date d0;
    std::cout << "Test default constructor: " << d0.formatSlash() << "\n\n";

    // Test constructor with valid date
    Date d1(2, 28, 2009);
    printIfError(d1);
    std::cout << "Test constructor with valid date: " << d1.formatSlash() << "\n\n";

    // Test constructor with invalid month
    Date d2(45, 2, 2009);
    std::cout << "Test constructor with invalid month (45, 2, 2009): ";
    printIfError(d2);
    std::cout << d2.formatSlash() << "\n\n";

    // Test constructor with invalid day
    Date d3(2, 29, 2009);
    std::cout << "Test constructor with invalid day (2, 29, 2009): ";
    printIfError(d3);
    std::cout << d3.formatSlash() << "\n\n";

    // Test setDate with bad month
    Date d4;
    std::cout << "Test setDate with bad month (13): ";
    d4.setDate(13, 1, 2009);
    printIfError(d4);
    std::cout << d4.formatSlash() << "\n\n";

    // Test setDate with bad day
    Date d5;
    std::cout << "Test setDate with bad day (4, 31, 2009): ";
    d5.setDate(4, 31, 2009);
    printIfError(d5);
    std::cout << d5.formatSlash() << "\n\n";

    // Test for leap year with bad date (should fail and default)
    Date d6;
    std::cout << "Test for leap year with bad date (2/29/2009): ";
    d6.setDate(2, 29, 2009);
    printIfError(d6);
    std::cout << d6.formatSlash() << "\n\n";

    // Test for leap year with good date
    Date d7;
    std::cout << "Test for leap year with good date (2/29/2008): ";
    d7.setDate(2, 29, 2008);
    printIfError(d7);
    std::cout << d7.formatSlash() << "\n\n";

    // Test the print formats
    std::cout << "Test the print formats:\n";
    std::cout << d7.formatLong() << "\n";
    std::cout << d7.formatDayMonthYear() << "\n";


    return 0;
}

