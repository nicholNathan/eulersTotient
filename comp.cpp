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
    iterations.reserve(num_runs);
    for (int i = 0; i < num_runs; ++i) {
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
    std::cout << "  Total Duration: " << std::setprecision(5) << avgDuration << " ms" << '\n';
    avgDuration /= num_runs;
    std::cout << "  Avg Duration: " << std::setprecision(5) << avgDuration << " ms" << '\n';
    return avgDuration;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <start> <end> <num_runs>" << '\n';
        return 0;
    }

    uint64_t start = std::stoull(argv[1]);
    uint64_t end = std::stoull(argv[2]);
    int num_runs = std::stoi(argv[3]);
    std::cout << "eulersGcd (v1 - int):" << '\n';
    double time_v1 = bench(EULERSGCD_H::calcEulersv1, start, end, num_runs);
    std::cout << "\neulersGcdV2 (uint64_t):" << '\n';
    double time_v2 = bench(EULERSGCDV2_H::calcEulersv2, start, end, num_runs);
    std::cout << "\nPrime Factorization:" << '\n';
    double time_v3 = bench(PRIMEFACT_H::calcEulersv3, start, end, num_runs);
    return 0;
}



/* 
    TODO:
    - need to have this print out somewhere, otherwise it's kind of useless
      - can print out all factors (very slow), or can just print out final result
 */
