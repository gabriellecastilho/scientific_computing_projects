# LU Factorization with OpenMP

This project implements **LU decomposition** (factorization) of a square matrix using both **serial** and **parallel** approaches in C. The parallel version uses **OpenMP** for multi-threading. The goal is to compare execution times and demonstrate speedup with parallelization.

**Course**: High-Performance Computing  
**Authors**: [Your Name(s)]  
**Language**: C with OpenMP

---

## 📌 Overview
LU factorization decomposes a matrix **A** into two matrices:
- **L**: Lower triangular matrix
- **U**: Upper triangular matrix  
such that **A = L × U**.

This project:
- Generates a random square matrix.
- Performs LU decomposition **serially** and **in parallel**.
- Measures and prints execution times for both versions.

---

## ✅ Features
- **Serial LU decomposition** for baseline performance.
- **Parallel LU decomposition** using OpenMP.
- Handles input validation for:
  - Matrix size (2 ≤ n ≤ 2000)
  - Number of threads (1 ≤ threads ≤ available cores)
- Reports timing for both implementations.

---

## 📂 Files
- `main.c` – Source code for LU factorization.
- `Makefile` – Build and execution instructions.

---

## 🔧 Requirements
- **GCC** with OpenMP support
- Linux or macOS environment
- Basic C development tools

---

## ▶️ Compilation & Execution
Use the provided **Makefile**:

### Build:
```bash
make