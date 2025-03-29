#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double res = 1.0;
    
    if (n == 0) {
        return 1.0;
    }
    if (value == 0.0 && n > 0) {
        return 0.0;
    }
    
    while (n > 0) {
        if (n & 1) {
            res *= value;
        }
        value *= value;
        n >>= 1;
    }
    
    return res;
        
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    }
    
    uint64_t res = 1;
    for (uint64_t i = 0; i <= n; i++) {
        if (res > UINT64_MAX / i) {
            return 0;
        }
        res *= i;
    }
    
    return res;
}

double calcItem(double x, uint16_t n) {
    uint64_t factorial = fact(n);
    if (factorial == 0) {
        return 0.0;
    }
    
    return pown(x, n) / static_cast<double>(factorial);
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItemExp(x, n);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double summ = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        summ += calcItemSin(x, n);
    }
    return summ;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItemCos(x, n);
    }
    return sum;
}

