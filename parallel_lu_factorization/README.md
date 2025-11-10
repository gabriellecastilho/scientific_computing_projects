# Parallel LU Factorization Using OpenMP

A high-performance implementation of LU matrix decomposition with OpenMP parallelization for comparing serial and parallel execution efficiency in scientific computing applications.

**Academic Project**: Uppsala University - High-Performance Parallel Computing - VT2023

**Author**: Gabrielle Fidelis de Castilho

## Overview

This project implements LU (Lower-Upper) factorization, a fundamental matrix decomposition technique used in solving systems of linear equations, computing determinants, and matrix inversion. The implementation provides both serial and parallel versions using OpenMP, allowing for direct performance comparison and scalability analysis across different matrix sizes and thread counts.

LU decomposition factorizes a matrix **A** into the product of a lower triangular matrix **L** and an upper triangular matrix **U**, such that **A = LU**.

## Key Features

* **Dual Implementation**: Both serial and OpenMP-parallelized versions for performance benchmarking
* **Scalable Parallelization**: Configurable thread count up to available CPU cores
* **Large Matrix Support**: Handles matrices up to 2000×2000 elements
* **Performance Measurement**: Wall-clock timing for accurate execution time comparison
* **Reproducible Results**: Fixed random seed (42) for consistent matrix generation

## Installation

### Prerequisites
```bash
GCC compiler with OpenMP support (gcc 4.2+)
Linux/Unix environment
```

### Compilation
Build using the provided Makefile:
```bash
make
```

This compiles the program with the following optimizations:

**Compiler Flags:**
* `-fopenmp`: Enable OpenMP support
* `-O3`: Highest optimization level for maximum performance
* `-Wall -Wextra -Wpedantic`: Comprehensive warning detection
* `-fsanitize=address,leak`: Memory safety checking (development mode)
* `-lm`: Link math library

**Clean Build:**
```bash
make clean    # Remove object files and executable
make          # Rebuild from scratch
```

## Usage

### Running the Program

```bash
./lu [matrix side] [threads]
```

**Parameters:**
* `matrix side`: Integer between 2 and 2000 (matrix dimensions)
* `threads`: Integer between 1 and number of available CPU cores

**Quick Test:**

```bash
make execute    # Runs with default parameters: 500x500 matrix, 4 threads
```

### Example Session

```bash
$ ./lu 500 8
Serial LU time:   0.075 seconds
Parallel LU time: 0.062 seconds
```

## Project Structure

```
parallel_lu_factorization/
├── main.c                    # Complete implementation
├── makefile                  # Build configuration
└── README.md                 # This file
```
