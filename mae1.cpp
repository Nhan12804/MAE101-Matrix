#include <stdio.h>
#include <math.h>
void nhapmatran(int a[][100], int m, int n);
void inmatran(int a[][100], int m, int n);
void congmatran(int a[][100], int b[][100], int c[][100], int m, int n);
void hieumatran(int a[][100], int b[][100], int c[][100], int m, int n);
void tichmatran(int a[][100], int b[][100], int c[][100], int m, int n, int p);

void nhapmatran(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void inmatran(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void congmatran(int a[][100], int b[][100], int c[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void hieumatran(int a[][100], int b[][100], int c[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void tichmatran(int a[][100], int b[][100], int c[][100], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int a[100][100], b[100][100], c[100][100];
    int m, n, p;

    printf("Nhap so hang cua ma tran A: ");
    scanf("%d", &m);
    printf("Nhap so cot cua ma tran A ung voi so hang cua ma tran B: ");
    scanf("%d", &n);
    printf("Nhap so cot cua ma tran B: ");
    scanf("%d", &p);

    printf("\nNhap ma tran A:\n");
    nhapmatran(a, m, n);

    printf("\nNhap ma tran B:\n");
    nhapmatran(b, n, p);

    printf("\na tran A:\n");
    nhapmatran(a, m, n);

    printf("\nMa tran B:\n");
    inmatran(b, n, p);

    congmatran(a, b, c, m, n);
    printf("\nKet qua ma tran A + B:\n");
    inmatran(c, m, n);

    hieumatran(a, b, c, m, n);
    printf("\nKet qua ma tran A - B:\n");
    inmatran(c, m, n);

    tichmatran(a, b, c, m, n, p);
    printf("\nKet qua ma tran A * B:\n");
    inmatran(c, m, p);
}
