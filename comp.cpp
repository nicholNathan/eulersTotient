// benchmark.cpp
#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <iomanip>
#include "eulersGcd.h"
#include "eulersGcdV2.h"
#include "primefact.h"

template<typename F>
double bench(F func, uint64_t start, uint64_t end, int num_runs) {
    std::vector<double> iterations;

    for (int run = 0; run < num_runs; ++run) {
        auto startTime = std::chrono::high_resolution_clock::now();
        for (uint64_t n = start; n <= end; ++n) {
            func(n);
        }
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        iterations.push_back(duration.count() / 1000.0);
    }

    double avgDuration = 0;
    for (double time : iterations) {
        avgDuration += time;
    }
    std::cout << "  Total Duration: " << std::setprecision(5) << avgDuration << " ms" << std::endl;
    avgDuration /= num_runs;
    std::cout << "  Avg Duration: " << std::setprecision(5) << avgDuration << " ms" << std::endl;
    return avgDuration;
}

int main() {
    const uint64_t start = 1;
    const uint64_t end = 1000;
    const int num_runs = 5;

    std::cout << "eulersGcd (v1 - int):" << std::endl;
    double time_v1 = bench(EULERSGCD_H::calcEulersv1, start, end, num_runs);
    std::cout << "\neulersGcdV2 (uint64_t):" << std::endl;
    double time_v2 = bench(EULERSGCDV2_H::calcEulersv2, start, end, num_runs);
    std::cout << "\nPrime Factorization:" << std::endl;
    double time_v3 = bench(PRIMEFACT_H::calcEulersv3, start, end, num_runs);

    return 0;
}