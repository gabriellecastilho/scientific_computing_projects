# Scientific Computing Projects

A portfolio of academic projects demonstrating skills in high-performance computing, parallel algorithms, machine learning, and probabilistic modeling for scientific applications.

**Author:** Gabrielle Fidelis de Castilho  
**Institution:** Uppsala University  
**Program:** MSc in Data Engineering  

## Overview

This repository showcases implementations from low-level parallel programming in C/OpenMP to high-level probabilistic modeling in Python.
The projects emphasize practical applications in scientific computing and artificial intelligence.

## Projects

### 1. Holiday Recommendation System Using Markov Chains

**Language:** Python  
**Technologies:** NumPy, Pandas, Scikit-learn  
**Domain:** Machine Learning, Probabilistic Modeling, Recommender Systems

A Markov chain-based recommendation system for Indonesian tourism destinations combining probabilistic modeling with collaborative and content-based filtering. This project demonstrates skills in:

* Probabilistic modeling and stochastic processes
* Hybrid recommendation algorithms
* Data preprocessing and feature engineering
* Cold start problem handling
* Real-world dataset analysis

**Key Features:**
- Markov chain category transition prediction
- Age-based collaborative filtering
- Budget-aware recommendations
- Multi-city support across 5 Indonesian cities
- 437 tourist attractions, 300 users, 10,000 ratings

**Academic Context:** Course project for Artificial Intelligence (1DL340) at Uppsala University

📂 [View Project](./markov_tourism_recommendation/) | 📄 [Documentation](./markov_tourism_recommendation/README.md)

---

### 2. Parallel LU Factorization with OpenMP

**Language:** C  
**Technologies:** OpenMP, GCC  
**Domain:** Numerical Linear Algebra, High-Performance Computing

A high-performance implementation of LU matrix decomposition comparing serial and parallel execution using OpenMP. This project demonstrates skills in:

* Parallel algorithm design and optimization
* OpenMP parallelization directives and thread management
* Performance benchmarking and scalability analysis
* Memory-efficient numerical computing
* Low-level systems programming

**Key Features:**
- Dual serial/parallel implementations for direct performance comparison
- Scalable to 2000×2000 matrices across multiple CPU cores
- Wall-clock timing for accurate performance measurement

📂 [View Project](./parallel_lu_factorization/) | 📄 [Documentation](./parallel_lu_factorization/README.md)

---
## Technical Skills Demonstrated

### Programming Languages
- **C**: Low-level systems programming, memory management, performance optimization
- **Python**: Data analysis, machine learning, scientific computing

### Parallel Computing
- OpenMP shared-memory parallelization
- Thread synchronization and race condition prevention
- Performance analysis and scalability testing

### Algorithms & Data Structures
- Numerical linear algebra (LU decomposition)
- Stochastic processes (Markov chains, transition matrices)
- Recommendation algorithms (collaborative filtering, content-based filtering)

### Scientific Libraries & Tools
- **C**: OpenMP, GCC optimization flags, POSIX systems programming
- **Python**: NumPy, Pandas, Scikit-learn
- **Version Control**: Git, GitHub

### Software Engineering
- Modular code design and documentation
- Error handling and input validation
- Build automation (Makefiles)
- Unit testing and accuracy validation

## Repository Structure

```
scientific_computing_projects/
├── markov_tourism_recommendation/
│   ├── main.py
│   ├── documentation.py
│   ├── test_recommendations.py
│   ├── test_accuracy.py
│   ├── data_preprocessing.ipynb
│   └── README.md
├── parallel_lu_factorization/
│   ├── main.c
│   ├── makefile
│   └── README.md
└── README.md (this file)
```

## Getting Started

Each project contains its own detailed README with:
- Installation and compilation instructions
- Usage examples and parameter descriptions

Navigate to individual project directories to explore implementations.

## Use Cases & Applications

### Parallel LU Factorization
- Solving large systems of linear equations in scientific simulations
- Matrix inversion for control systems
- Determinant computation for stability analysis
- Preprocessing for iterative solvers

### Markov Chain Recommendations
- Tourism and travel planning systems
- E-commerce product recommendations
- Content recommendation engines
- User behavior modeling and prediction

## Contact & Collaboration

**Gabrielle Fidelis de Castilho**  
MSc Data Engineering | System Integration Engineer  
-

*This repository demonstrates bridging theoretical computer science with practical implementation, from low-level parallel programming to high-level machine learning applications.*
