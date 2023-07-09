#include <stdio.h>
#include <math.h>
#include<conio.h>

void nhapmatran(int a[][100], int m, int n);
void inmatran(int a[][100], int m, int n);
void congmatran(int a[][100], int b[][100], int c[][100], int m, int n);
void hieumatran(int a[][100], int b[][100], int c[][100], int m, int n);
void tichmatran(int a[][100], int b[][100], int c[][100], int m, int n, int p);
int menu ();

//Ham nhapmatran dung de nhap vao ma tran theo tung vi tri khac nhau
void nhapmatran(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

//Ham inmatran dung de in ra ma tran 
void inmatran(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

//Ham congmatran dung de tinh phep cong ma tran
void congmatran(int a[][100], int b[][100], int c[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

//Ham hieumatran dung de tinh phep tru ma tran
void hieumatran(int a[][100], int b[][100], int c[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

//Ham tichmatran dung de tinh phep nhan ma tran
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

void matrancheo(){
    int n;

    printf("Nhap so chieu cua ma tran: ");
    scanf("%d", &n);

    int A[n][n];

    // Nhập giá trị cho ma trận A
    printf("Nhap gia tri cho ma tran A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Chéo hoá ma trận A
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                A[i][j] = 0;
            }
        }
    }

    // In ra ma trận A đã chéo hoá
    printf("Ma tran A da cheo hoa:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void matrannghichdao(){
    int i,j,k,m,n,na;
    double det,x,tam;
    double a[10][10],b[10][10];

    printf("\n");
    printf("\n Nhap cap ma tran :"); scanf("%d",&n);
    na=2*n;//so cot ma tran chuyen tiep.
    //Nhap ma tran A.-----------------------------------------------------------
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            {
            printf("\n a[%d][%d]=",i+1,j+1);
            scanf("%lf",&a[i][j]);
            }

    //Tao ma tran lien ket.-----------------------------------------------------
    for(i=0;i<n;i++)
        for(j=n;j<na;j++)
            {
            if(i==(j-n)) a[i][j]=1;
            else a[i][j]=0;
            }

    //In ma tran chuyen tiep.----------------------------------------------------
    printf("\n Ma tran mo rong (A/I)\n");
    for(i=0;i<n;i++)
        {
        for(j=0;j<na;j++) printf("%5.1lf ",a[i][j]);
        printf("\n");
        }

    //Ham giai phuong trinh.------------------------------------------------------
    //Dung phep BDSC dua Aij ve ma tran cheo.
    for(j=0;j<n;j++)
        {
        for(i=n-1;i>=j;i--)
            {
            if(a[i][j]==0) continue;
            if((i>j)&&(a[i][j]!=0))
                {
                k=i-1;
                while((k>=j)&&(a[k][j]==0)) k--;
                if(k<j)
                    {
                    //Doi cho hang thu i va j.------------------------
                    for(m=0;m<na;m++)
                        {
                        tam=a[i][m];
                        a[i][m]=a[j][m];
                        a[j][m]=tam;
                        }
                    }
                if((k>=j)&&(k>=0))
                    {
                    x=-a[i][j]/a[k][j];
                    //Nhan dong thu (i-1) cho x roi cong vao dong thu i.
                    for(m=0;m<na;m++)
                        a[i][m]+=a[k][m]*x;
                    }
                }
            }
        }
    for(j=n-1;j>=0;j--)
        {
        for(i=0;i<=j;i++)
        if(a[i][j]==0) continue;
        if((i<j)&&(a[i][j]!=0))
            {
            k=i+1;
            while((k<=j)&&(a[k][j]==0)) k++;
            if((k<=j)&&(k<na))
                {
                x=-a[i][j]/a[k][j];
                //Nhan dong thu (i+1) voi x roi cong vao dong thu i.-------
                for(m=0;m<na;m++)
                    a[i][m]+=a[k][m]*x;
                }
            }
        }
    //Tinh dinh thuc.--------------------------------------------------------------------
    det=1;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i==j) det*=a[i][j];
    printf("\n Det=%5.2lf",det);
    //Tinh ma tran nghich dao.-----------------------------------------------------------
    if(det!=0)
        {
        for(i=0;i<n;i++)
            for(j=n;j<na;j++)
                {
                a[i][j]=a[i][j]/a[i][i];
                }

        //In ma tran chuyen tiep.----------------------------------------------------
        printf("\n Ma tran nghich dao mo rong\n");
        for(i=0;i<n;i++)
            {
            for(j=0;j<na;j++) printf("%5.1lf ",a[i][j]);
                printf("\n");
            }
        for(i=0;i<n;i++)
            for(j=n;j<na;j++)
                {
                b[i][j-n]=a[i][j];
                }
        //In ra ma tran nghich dao.---------------------------------------------------
        printf("\n Ma tran nghich dao cua A:\n");
        for(i=0;i<n;i++)
            {
            for(j=0;j<n;j++)
                printf("%5.1lf",b[i][j]);
            printf("\n");
            }
        }
    else printf("\n Khong co ma tran nghich dao.");
    getch();
}
#include <stdio.h>

void swap_rows(float matrix[][100], int cols, int row1, int row2) {
    for (int j = 0; j < cols; j++) {
        float temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

void reduce_to_echelon(float matrix[][100], int rows, int cols) {
    int lead = 0;

    for (int r = 0; r < rows; r++) {
        if (lead >= cols) {
            return;
        }

        int i = r;
        while (matrix[i][lead] == 0) {
            i++;
            if (i == rows) {
                i = r;
                lead++;
                if (lead == cols) {
                    return;
                }
            }
        }

        swap_rows(matrix, cols, i, r);

        float lv = matrix[r][lead];
        for (int j = 0; j < cols; j++) {
            matrix[r][j] /= lv;
        }

        for (int k = 0; k < rows; k++) {
            if (k != r) {
                float factor = matrix[k][lead];
                for (int j = 0; j < cols; j++) {
                    matrix[k][j] -= factor * matrix[r][j];
                }
            }
        }

        lead++;
    }
}

void print_matrix(float matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_solutions(float matrix[][100], int rows, int cols) {
    printf("Solution:\n");
    for (int i = 0; i < rows; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][cols - 1]);
    }
}

void call() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    float matrix[rows][100];

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("Original matrix:\n");
    print_matrix(matrix, rows, cols);

    reduce_to_echelon(matrix, rows, cols);

    printf("Matrix in echelon form:\n");
    print_matrix(matrix, rows, cols);

    print_solutions(matrix, rows, cols);
}

int main() {
	int luachon;
    do {
        nhaplai:
        luachon = menu();
        switch(luachon) {
            case 1:
                int a[100][100], b[100][100], c[100][100];
                int m, n, p;
				//Nhap vao so hang va cot cua ma tran A va B (so cot cua ma tran A = so hang ma tran B)
                printf("Nhap so hang cua ma tran A: ");
                scanf("%d", &m);
                printf("Nhap so cot cua ma tran A ung voi so hang cua ma tran B: ");
                scanf("%d", &n);
                printf("Nhap so cot cua ma tran B: ");
                scanf("%d", &p);
            	//Nhap vao cac phan tu cua ma tran gia tri phan tu khong qua 100
                printf("\nNhap ma tran A:\n");
                nhapmatran(a, m, n);
				printf("\nNhap ma tran B:\n");
				nhapmatran(b, n, p);
				
				//In ra ma tran da nhap
				printf("\nMa tran A:\n");
                inmatran(a, m, n);
                printf("\nMa tran B:\n");
                inmatran(b, n, p);

                //in ra ket qua phep tinh ma tran
                congmatran(a, b, c, m, n);
                printf("\nKet qua ma tran A + B:\n");
                inmatran(c, m, n);
			
                hieumatran(a, b, c, m, n);
                printf("\nKet qua ma tran A - B:\n");
                inmatran(c, m, n);
			
                tichmatran(a, b, c, m, n, p);
			    printf("\nKet qua ma tran A * B:\n");
                inmatran(c, m, p);
                break;
            case 2:
            call();
                break;
            case 3:
                matrannghichdao();
                break;
			case 4:
                matrancheo();
                break;
            case 0:
                printf ("Ket thuc chuong trinh, tam biet !");
                break;
            default:
                printf ("Vui long chon dung chuc nang, vui long nhap lai: ");
                goto nhaplai; 
        }
    } while (luachon != 0);
    return 0;
}

int menu() {
    int c;
    printf ("\n==============MENU===========\n");
    printf ("\n1. Tinh tong, hieu, tich ma tran");
    printf ("\n2. Tim reduced-echelon matrix sau do giai he phuong trinh");
	printf ("\n3. Tim ma tran nghich dao");
	printf ("\n4. Cheo hoa ma tran");
    printf ("\n0. Ket thuc\n");
    printf ("Ban chon chuc nang nao: ");
    scanf ("%d", &c);
    return c;
}

