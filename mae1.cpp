#include <stdio.h>
#include <math.h>
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
   int rows, cols;

   // Nhập số hàng và số cột của ma trận từ bàn phím
   printf("Nhap so hang cua ma tran: ");
   scanf("%d", &rows);
   printf("Nhap so cot cua ma tran: ");
   scanf("%d", &cols);

   int matrix[rows][cols];

   // Nhập ma trận từng phần tử từ bàn phím
   printf("Nhap ma tran:\n");
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf("Nhap phan tu matrix[%d][%d]: ", i, j);
         scanf("%d", &matrix[i][j]);
      }
   }

   // In ma trận ban đầu
   printf("Ma tran ban dau:\n");
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }

   // Chuyển đổi ma trận sang dạng chéo
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         if (i == j) {
            continue; // Bỏ qua các phần tử trên đường chéo
         }
         matrix[i][j] = 0;
      }
   }

   // In ma trận đã chuyển đổi
   printf("Ma tran chuyen doi:\n");
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }
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
                break;
            case 2:
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
            case 3:
            	
			    break;
			case 4:
				
			case 5:
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
    printf ("\n1. Nhap vao ma tran va in ra ma tran");
    printf ("\n2. Tinh tong, hieu, tich ma tran");
    printf ("\n3. Tim reduced-echelon matrix sau do giai he phuong trinh");
	printf ("\n4. Tim ma tran nghich dao");
	printf ("\n5. Cheo hoa ma tran");
    printf ("\n0. Ket thuc\n");
    printf ("Ban chon chuc nang nao: ");
    scanf ("%d", &c);
    return c;
}

