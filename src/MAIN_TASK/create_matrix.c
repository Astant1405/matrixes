#include "../matrix.h"

int create_matrix(int rows, int columns, matrix_t *result) {
  int err = OK;
  if (result == NULL) {
    err = INCORRECT_MATRIX;
  }

  else if (rows < 1 || columns < 1) {
    result->matrix = NULL;
    err = CALCULATION_ERROR;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(sizeof(double *) * result->rows);
    for (int i = 0; i < result->rows; i++) {
      result->matrix[i] = (double *)malloc(sizeof(double) * result->columns);
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = 0.0;
      }
    }
  }
  return err;
}