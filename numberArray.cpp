#include "NumberArray.h"
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>

// Define static constants
const int    NumberArray::MAX_SIZE       = 10;
const double NumberArray::DEFAULT_RETURN = 10000.0;

NumberArray::NumberArray(int size) {
    if (size <= 0) size = MAX_SIZE;
    size_ = size;
    data_ = new double[size_];
    std::fill_n(data_, size_, 0.0);
}

NumberArray::~NumberArray() {
    delete[] data_;
    std::cout << "\nThe destructor is running\n";
}

void NumberArray::setNumber(int index, double value) {
    if (!validIndex(index)) {
        std::cout << "\nThe index is out of the bounds of the array, number not stored\n";
        return;
    }
    data_[index] = value;
}

double NumberArray::getNumber(int index) const {
    if (!validIndex(index)) {
        std::cout << "\nThe Index is out of the bounds of the array, returning default\n";
        return DEFAULT_RETURN;
    }
    return data_[index];
}

double NumberArray::min() const {
    if (size_ == 0) return 0.0;
    return *std::min_element(data_, data_ + size_);
}

double NumberArray::max() const {
    if (size_ == 0) return 0.0;
    return *std::max_element(data_, data_ + size_);
}

double NumberArray::average() const {
    if (size_ == 0) return 0.0;
    double sum = std::accumulate(data_, data_ + size_, 0.0);
    return sum / static_cast<double>(size_);
}

void NumberArray::print(std::ostream& os) const {
    std::ios::fmtflags f = os.flags();
    std::streamsize     p = os.precision();

    os << std::fixed << std::setprecision(1);
    for (int i = 0; i < size_; ++i) {
        os << data_[i];
        if (i + 1 < size_) os << ' ';
    }
    os << '\n';

    os.flags(f);
    os.precision(p);
}
