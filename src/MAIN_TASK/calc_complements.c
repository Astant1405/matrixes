#include "../matrix.h"

int calc_complements(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (A->matrix == NULL) {
    err = INCORRECT_MATRIX;
  } else if (A->columns != A->rows || A->rows < 2) {
    err = CALCULATION_ERROR;
  } else {
    create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < result->rows; i++) {
      if (A->matrix[i] == NULL) {
        err = INCORRECT_MATRIX;
        continue;
      }
      for (int j = 0; j < result->columns; j++) {
        matrix_t minor;
        create_matrix(A->rows - 1, A->columns - 1, &minor);
        int minor_row = 0;
        for (int x = 0; x < A->rows; x++) {
          if (x == i) continue;
          int minor_col = 0;
          for (int y = 0; y < A->columns; y++) {
            if (y == j) continue;
            minor.matrix[minor_row][minor_col] = A->matrix[x][y];
            minor_col++;
          }
          minor_row++;
        }
        double minor_det;
        determinant(&minor, &minor_det);
        result->matrix[i][j] = pow(-1, i + j) * minor_det;
        remove_matrix(&minor);
      }
    }
  }
  return err;
}