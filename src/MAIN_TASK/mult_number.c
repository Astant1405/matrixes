#include "../matrix.h"

int mult_number(matrix_t *A, double number, matrix_t *result) {
  int err = OK;
  if (A->matrix == NULL) {
    err = INCORRECT_MATRIX;
  } else {
    create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] == NULL) {
        err = INCORRECT_MATRIX;
        continue;
      }
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return err;
}