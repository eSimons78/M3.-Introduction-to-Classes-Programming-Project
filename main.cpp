#include <iostream>
#include <random>
#include <iomanip>
#include "NumberArray.h"

int main() {
    std::cout << "----- Test constructors -----\n\n";

    NumberArray defArr; // default size (MAX_SIZE)
    std::cout << "From default constructor: Array of size " << defArr.size() << "\n";
    defArr.print();
    std::cout << "\n";

    NumberArray arr(15);
    std::cout << "From constructor with parameters: Array of size " << arr.size() << "\n";
    arr.print();
    std::cout << "\n";

    std::cout << "----- Test mutator -----\n\n";
    std::cout << "Array filled with numbers:\n";

    // Fill with reproducible random numbers in [0,100)
    std::mt19937 rng(12345u);
    std::uniform_real_distribution<double> dist(0.0, 100.0);
    for (int i = 0; i < arr.size(); ++i) {
        // store raw double; print uses 1-decimal precision
        arr.setNumber(i, dist(rng));
    }
    arr.print();
    std::cout << "\n";

    std::cout << "Trying to set a number with an out of bounds index (20):\n";
    arr.setNumber(20, 123.4); // oob for size 15
    std::cout << "\n";

    std::cout << "----- Test accessors _____\n\n";
    std::cout << "Access item at index 5: ";
    std::cout << std::fixed << std::setprecision(1) << arr.getNumber(5) << "\n\n";

    std::cout << "Access item at index 20 (out of bounds): ";
    std::cout << std::fixed << std::setprecision(1) << arr.getNumber(20) << "\n\n";

    std::cout << "The minimum value in the array is: " << std::fixed << std::setprecision(1) << arr.min() << "\n";
    std::cout << "The maximum value in the array is: " << std::fixed << std::setprecision(1) << arr.max() << "\n";
    std::cout << "The average of the values in the array is: " << std::fixed << std::setprecision(1) << arr.average() << "\n";

    // Destructors will message automatically at end of scope
    return 0;
}
