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

int main() {
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

    return 0;
}
