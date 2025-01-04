#include "../matrix.h"

int transpose(matrix_t *A, matrix_t *result) {
  create_matrix(A->columns, A->rows, result);
  int err = OK;
  if (A->matrix == NULL) {
    err = INCORRECT_MATRIX;
  } else {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] == NULL) {
        err = INCORRECT_MATRIX;
        continue;
      }
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return err;
}