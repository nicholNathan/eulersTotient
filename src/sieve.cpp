// euler's using sieve
#include "../include/eulersTotient/sieve.h"

#include <vector>
#include <iostream>
#include <cmath>
#include <cstdint>

std::vector<int> phi(int n) {
    std::vector<int> phi(n + 1);
    phi.reserve(n+1);
    for (int i = 0; i <= n; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    return phi;
}

uint64_t calcEulersv3(int n) {
    std::vector<int> ans = phi(n);
    return static_cast<uint64_t>(ans[n]);
}
