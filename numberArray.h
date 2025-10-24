#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>

class NumberArray {
public:
    // Default size and out-of-bounds return value (set in .cpp)
    static const int    MAX_SIZE;
    static const double DEFAULT_RETURN;

    explicit NumberArray(int size = MAX_SIZE);
    ~NumberArray();

    void   setNumber(int index, double value);
    double getNumber(int index) const;

    double min() const;
    double max() const;
    double average() const;

    void   print(std::ostream& os = std::cout) const;
    int    size() const { return size_; }

private:
    int     size_{0};
    double* data_{nullptr};

    bool validIndex(int index) const { return index >= 0 && index < size_; }
};

#endif // NUMBERARRAY_H
