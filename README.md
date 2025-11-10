# Scientific Computing Projects

Collection of scientific computing work from my Master's studies in Data Engineering at Uppsala University, demonstrating parallel computing, numerical methods, and algorithmic implementation.

## Projects

### 1. Parallel LU Factorization (C + OpenMP)
**Location:** [`parallel_lu_factorization/`](./parallel_lu_factorization/)

Implements LU decomposition with and without OpenMP parallelization for performance comparison. Focuses on:
- Multi-threaded matrix operations using OpenMP
- Memory optimization with contiguous storage and restrict qualifiers
- Numerical accuracy validation with relative residual testing
- Performance benchmarking across different matrix sizes and thread counts

**Technologies:** C, OpenMP, numerical methods

**To build and run:**
```bash
cd parallel-lu-factorization
make
./lu [matrix side] [threads]
```

---

### 2. Markov Chain Tourism Recommendation System (Python)
**Location:** [`markov_tourism_recommendation/`](./markov_tourism_recommendation/)

Probabilistic recommendation system using Markov chains to model and predict sequential tourism patterns. Demonstrates:
- Statistical modeling with transition probability matrices
- Data processing and validation pipelines
- Comprehensive testing framework (recommendation quality and accuracy metrics)
- Clean code architecture with separation of concerns

**Technologies:** Python, NumPy, probability theory, statistical modeling

**Full project report:** [project_report.pdf](./project_report.pdf) - Detailed methodology, testing, and results analysis

---

## About

These projects were developed as part of coursework and independent study during my MSc in Data Engineering, with emphasis on:
- High-performance computing and parallel processing
- Numerical algorithms and optimization
- Scientific Python programming
- Code quality, testing, and documentation
