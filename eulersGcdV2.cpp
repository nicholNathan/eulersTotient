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

int main() {
    uint64_t n;

    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    uint64_t count = 0;
    for (int i = 1; i <= n; ++i) {
        if (gcd(n, i) == 1) {
            count = count+1;
        }
    }
    std::cout << "Euler's Totient: " << count << std::endl;
}
