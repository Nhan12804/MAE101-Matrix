#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap kich thuoc he phuong trinh: ");
    scanf("%d", &n);

    float a[n][n+1], x[n];
    printf("Nhap cac phan tu cua ma tran he so:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n+1; j++) {
            printf("Nhap phan tu thu (%d, %d): ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }

    // Tien hanh giai he phuong trinh bang phuong phap Gauss-Jordan
    for(int i=0; i<n; i++) {
        if(a[i][i] == 0.0) {
            printf("He phuong trinh vo nghiem.\n");
            return 0;
        }

        for(int j=0; j<n; j++) {
            if(i != j) {
                float ratio = a[j][i]/a[i][i];

                for(int k=0; k<n+1; k++) {
                    a[j][k] = a[j][k] - ratio*a[i][k];
                }
            }
        }
    }

    // Tinh nghiem cua he phuong trinh
    for(int i=0; i<n; i++) {
        x[i] = a[i][n]/a[i][i];
    }

    // In ma tran he so va nghiem cua he phuong trinh
    printf("Ma tran he so sau khi bien doi:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n+1; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }

    printf("Cac nghiem cua he phuong trinh la:\n");
    for(int i=0; i<n; i++) {
        printf("x%d = %.2f\n", i+1, x[i]);
    }

    return 0;
}
