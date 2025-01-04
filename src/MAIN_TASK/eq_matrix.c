#include "../matrix.h"
#define SUCCESS 1
#define FAILURE 0

int eq_matrix(const matrix_t *A, const matrix_t *B) {
  int err = SUCCESS;
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL ||
      A->rows != B->rows || A->columns != B->columns) {
    err = FAILURE;
  } else {
    double eps = 1e-7;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > eps) {
          err = FAILURE;
        }
      }
    }
  }
  return err;
}