// euler's using prime factorization (runs in O(sqrt(n)))
// FROM GEEKS 4 GEEKS

#include <vector>
#include <iostream>
#include <cmath>
#include <cstdint>

std::vector<int> phi(int n) {
    std::vector<int> phi(n + 1);
    phi.reserve(n+1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

int calcEulersv3(int n) {
    uint64_t res = 0;
    std::vector<int> ans = phi(n);
    for (int i = 0; i < ans.size(); ++i) {
        res += i;
    }
    return res;
}
