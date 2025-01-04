#include "../matrix.h"

int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;
  if (A->matrix == NULL || B->matrix == NULL) {
    err = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    err = CALCULATION_ERROR;
  } else {
    create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] == NULL) {
        err = INCORRECT_MATRIX;
        continue;
      }
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return err;
}