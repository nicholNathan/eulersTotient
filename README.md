## Euler's Totient Function

Implementations of Euler's Totient Function comparing basic GCD to a
prime factorization approach with rough benchmarking.

## Project Layout

```
.
├── app/                    # CLI benchmark executable
├── include/eulersTotient/  # Public headers
├── src/                    # Library implementation
└── CMakeLists.txt
```

## Build

Configure and build with CMake:

```
cmake -S . -B build
cmake --build build
```
Example usage:
```
./build/bin/comp 1 1000 10
```

Usage:

```
./build/bin/comp <start> <end> <num_iterations>
```

## Reference

[Euler's Totient Function - Wikipedia](https://en.wikipedia.org/wiki/Euler%27s_totient_function)

## License

This project is licensed under the MIT License.
