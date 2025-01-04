#include "../matrix.h"

int determinant(matrix_t *A, double *result) {
  int err = OK;
  if (A->matrix == NULL) {
    err = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    err = CALCULATION_ERROR;
  } else if (A->rows == 1) {
    *result = A->matrix[0][0];
    err = OK;
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    err = OK;
  } else {
    double det = 0.0;
    for (int j = 0; j < A->columns; j++) {
      matrix_t minor;
      create_matrix(A->rows - 1, A->columns - 1, &minor);
      for (int x = 1; x < A->rows; x++) {
        for (int y = 0; y < A->columns; y++) {
          if (y < j) {
            minor.matrix[x - 1][y] = A->matrix[x][y];
          } else if (y > j) {
            minor.matrix[x - 1][y - 1] = A->matrix[x][y];
          }
        }
      }
      double minor_det;
      determinant(&minor, &minor_det);
      det += pow(-1, j) * A->matrix[0][j] * minor_det;
      remove_matrix(&minor);
    }

    *result = det;
  }
  return err;
}