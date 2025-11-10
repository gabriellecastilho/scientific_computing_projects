#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <omp.h>

// Getting wall-clock time in seconds
double get_wall_seconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (double)tv.tv_usec / 1000000;
}

    
// Performing serial LU factorization
void LU_serial(double **A, double **L, double **U, int n) {
    int i, j, k;
    
    // Creating serial L matrix as identity and U matrix as a copy of A
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                L[i][j] = 1.0;
            else
                L[i][j] = 0.0;
            U[i][j] = A[i][j];
        }
    }
    
    // Decomposing matrix into lower half and upper half in serial
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            
            // Checking division by 0
            if (U[i][i] == 0) {
                fprintf(stderr, "Error: Zero encountered at row %d\n", i);
                return;
            }
            
            // Step to decomposing matrix
            L[j][i] = U[j][i] / U[i][i];
            for (k = i; k < n; k++) {
                U[j][k] -= L[j][i] * U[i][k];
            }
        }
    }
}

//  Performing parallel LU factorization
void LU_parallel(double **A, double **L, double **U, int n) {
    int i, j, k;
    int error_flag = 0; // Adding this variable because omp doesn't allow return in the loop 

    // Creating parallel L matrix as identity and U matrix as a copy of A
    #pragma omp parallel for private(j)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                L[i][j] = 1.0;
            else
                L[i][j] = 0.0;
            U[i][j] = A[i][j];
        }
    }

    // Decomposing matrix into lower half and upper half in parallel
    for (i = 0; i < n; i++) {
        
        //Checking division by 0
        #pragma omp parallel for private(k) shared(error_flag)
        for (j = i + 1; j < n; j++) {
            if (U[i][i] == 0) {
                #pragma omp atomic write
                error_flag = 1;

            } else {
                
                // Step to decomposing matrix
                L[j][i] = U[j][i] / U[i][i];
                for (k = i; k < n; k++) {
                    U[j][k] -= L[j][i] * U[i][k];
                }
            }
        }

        // Checking if error flag was activated
        if (error_flag) {
            fprintf(stderr, "Error: Zero encountered at row %d\n", i);
            return;
        }
    }
}


int main(int argc, char *argv[]) {
    // Checking if parameters are correct
    if (argc != 3) {
        fprintf(stderr, "Parameters required: %s [matrix side] [threads]\n", argv[0]);
        return 1;
    }

    // Checking if matrix size is between 2 and 2000
    int n = atoi(argv[1]);
    if (n <= 1 || n > 2000) {
            fprintf(stderr, "Error: Matrix size must be between 2 and 2000\n");
            return 1;
        }

    //Checking if threads number is between 0 and max number of cores
    int threads = atoi(argv[2]);
    int number_of_cores = sysconf(_SC_NPROCESSORS_ONLN);
    if (threads <= 0 || threads > number_of_cores) {
        fprintf(stderr, "Error: Number of threads must be between 0 and %d\n", number_of_cores);
        return 1;
    }

    if (threads > 0) omp_set_num_threads(threads);

    // Allocating memory for matrices
    double **A = malloc(n * sizeof(double *));
    double **L = malloc(n * sizeof(double *));
    double **U = malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        A[i] = malloc(n * sizeof(double));
        L[i] = malloc(n * sizeof(double));
        U[i] = malloc(n * sizeof(double));
    }
    
    //Checking if memory was allocated
    if (!A || !L || !U) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 1;
    }

    // Generating random matrix
    srand(42);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = ((double)rand() / RAND_MAX) * 100.0;

    // Running serial LU factorization
    double start_serial = get_wall_seconds();
    LU_serial(A, L, U, n);
    double end_serial = get_wall_seconds();

    // Running parallel LU factorization
    double start_parallel = get_wall_seconds();
    LU_parallel(A, L, U, n);
    double end_parallel = get_wall_seconds();

    // Printing time results
    printf("Serial LU time:   %.3f seconds\n", end_serial - start_serial);
    printf("Parallel LU time: %.3f seconds\n", end_parallel - start_parallel);

    // Freeing allocated memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(L[i]);
        free(U[i]);
    }
    free(A);
    free(L);
    free(U);

    return 0;
}