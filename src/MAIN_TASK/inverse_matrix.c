#include "../matrix.h"

int inverse_matrix(matrix_t *A, matrix_t *result) {
  int err = 0;
  double det;
  if (A->matrix == NULL) {
    err = INCORRECT_MATRIX;
  } else if (A->rows != A->columns || A->rows < 2) {
    err = CALCULATION_ERROR;
  } else if (determinant(A, &det) != 0) {
    err = CALCULATION_ERROR;
  }

  else if (fabs(det) < 1e-7) {
    err = CALCULATION_ERROR;
  }

  else {
    create_matrix(A->rows, A->columns, result);
    matrix_t complements;
    calc_complements(A, &complements);
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] == NULL) {
        err = INCORRECT_MATRIX;
        continue;
      }
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = complements.matrix[j][i] / det;
      }
    }
    remove_matrix(&complements);
  }
  return err;
}