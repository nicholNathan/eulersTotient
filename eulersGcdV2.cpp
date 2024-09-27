#include <iostream>
#include <cmath>
#include <cstdint>

// Based on TI Education's 'Euler Totient Function' PDF

uint64_t gcd(uint64_t a, uint64_t b) {
    while (a*b > 0) {
        if (a > b) {
            a = a%b;
        } else {
            b = b%a;
        }
    }
    if (a == 0) {
        a = b;
    }
    return a;
}

int calcEulersv2(int n) {
    uint64_t count = 0;
    for (uint64_t i = 0; i < n; ++i) {
        if (gcd(n, i)==1) {
            ++count;
        }
    }
    return count;
}
