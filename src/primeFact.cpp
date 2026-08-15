#include "../include/eulersTotient/primeFact.h"

#include <vector>
#include <iostream>
#include <cmath>
#include <cstdint>

uint64_t eulerTotient(uint64_t n) {
    uint64_t result = n;
    for (uint64_t p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            // p is a prime factor of n
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    // if a factor remains, it's a prime > sqrt(original n)
    if (n > 1) {
        result -= result / n;
    }
    return result;
}