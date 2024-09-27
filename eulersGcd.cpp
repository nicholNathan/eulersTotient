#include <iostream>
#include <cmath>
#include <cstdint>
#include <chrono>
#include <iomanip>
// Based on TI Education's 'Euler Totient Function' PDF

int gcd(int a, int b) {
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

int calcEulersv1(int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (gcd(n, i)==1) {
            ++count;
        }
    }
    return count;
}
