#include <iostream>
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

int main() {
    int n;

    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (gcd(n, i) == 1) {
            count = count+1;
        }
    }
    std::cout << "phi("<<n<<"): " << count << std::endl;
}
