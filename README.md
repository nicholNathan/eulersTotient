## Euler's Totient Function
<p>Implementations of Euler's Totient Function using basic form and prime factorization form with rough performance testing.</p>
<br><p>Compilation:</p>

Project layout:

```
.
├── app/                    # CLI benchmark executable
├── include/eulersTotient/  # Public headers
├── src/                    # Library implementation
└── CMakeLists.txt
```

With CMake:

```
cmake -S . -B build
cmake --build build
./build/bin/comp 1 1000 10
```

Or directly with `g++`:

```
g++ app/comp.cpp src/eulersGcd.cpp src/eulersGcdV2.cpp src/primeFact.cpp -Iinclude -o comp -O2 -fno-exceptions -std=c++11
```

<br>
<p>Example Usage:</p>

```
./build/bin/comp 1 1000 10
<start> <end> <num_iterations>
```

<br/>Reference: [Euler's Totient Function Wikipedia](https://en.wikipedia.org/wiki/Euler%27s_totient_function)
