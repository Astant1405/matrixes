#include "../matrix.h"

int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;
  if (A->matrix == NULL || B->matrix == NULL) {
    err = INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    err = CALCULATION_ERROR;
  } else {
    create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] == NULL) {
        err = INCORRECT_MATRIX;
        continue;
      }
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return err;
}