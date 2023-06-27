#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_matrix(double *A, int n) {
    int i, j;
    printf("Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f ", A[i*n+j]);
        }
        printf("\n");
    }
}

void householder(double *A, int n, double *Q, double *R) {
    int i, j, k;
    double norm, alpha;
    double *u = (double*) malloc(n * sizeof(double));
    double *v = (double*) malloc(n * sizeof(double));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            Q[i*n+j] = 0;
            R[i*n+j] = A[i*n+j];
        }
        Q[i*n+i] = 1;
    }

    for (k = 0; k < n-1; k++) {
        norm = 0;
        for (i = k+1; i < n; i++) {
            norm += R[i*n+k] * R[i*n+k];
        }
        norm = sqrt(norm);
        if (R[(k+1)*n+k] < 0) {
            norm = -norm;
        }
        alpha = sqrt(2*norm*(norm - R[(k+1)*n+k]));
        for (i = 0; i < k+1; i++) {
            u[i] = 0;
        }
        for (i = k+1; i < n; i++) {
            u[i] = R[i*n+k];
        }
        u[k+1] = u[k+1] - norm;
        norm = 0;
        for (i = k+1; i < n; i++) {
            norm += u[i] * u[i];
        }
        norm = sqrt(norm);
        for (i = k+1; i < n; i++) {
            u[i] = u[i] / norm;
        }
        for (i = 0; i < n; i++) {
            v[i] = 0;
            for (j = k+1; j < n; j++) {
                v[i] += Q[i*n+j] * u[j];
            }
        }
        for (i = 0; i < n; i++) {
            for (j = k+1; j < n; j++) {
                Q[i*n+j] -= 2*u[i]*v[j];
            }
        }
        for (i = k+1; i < n; i++) {
            for (j = k+1; j < n; j++) {
                R[i*n+j] -= 2*u[i]*u[j]*R[(k+1)*n+k];
            }
        }
        R[(k+1)*n+k] = -alpha;
        for (i = k+2; i < n; i++) {
            R[i*n+k] = 0;
        }
    }

    free(u);
    free(v);
}

int main() {
    int n, i, j;

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    double *A = (double*) malloc(n * n * sizeof(double));
    double *Q = (double*) malloc(n * n * sizeof(double));
    double *R = (double*) malloc(n * n * sizeof(double));

    printf("Enter the values of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &A[i*n+j]);
        }
    }

    householder(A, n, Q, R);

    print_matrix(Q, n);
    printf("\n");
    print_matrix(R, n);

    free(A);
    free(Q);
    free(R);

    return 0;
}