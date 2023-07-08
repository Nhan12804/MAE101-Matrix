#include<stdio.h>

int main(){
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