#include "matrix_unit_test.h"

START_TEST(create_matrix_0) {
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &result);
  create_matrix(3, 3, &answer);
  answer.matrix[0][0] = 0.0, answer.matrix[0][1] = 0.0,
  answer.matrix[0][2] = 0.0;
  answer.matrix[1][0] = 0.0, answer.matrix[1][1] = 0.0,
  answer.matrix[1][2] = 0.0;
  answer.matrix[2][0] = 0.0, answer.matrix[2][1] = 0.0,
  answer.matrix[2][2] = 0.0;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&result);
  remove_matrix(&answer);
}

START_TEST(create_matrix_1) {
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(2, 2, &result);
  create_matrix(2, 2, &answer);
  answer.matrix[0][0] = 0.0, answer.matrix[0][1] = 0.0;
  answer.matrix[1][0] = 0.0, answer.matrix[1][1] = 0.0;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&result);
  remove_matrix(&answer);
}

START_TEST(create_matrix_2) {
  matrix_t result = {};
  ck_assert_int_eq(create_matrix(0, 0, &result), 2);
  remove_matrix(&result);
}

START_TEST(create_matrix_3) {
  matrix_t result = {};
  ck_assert_int_eq(create_matrix(-1, -3, &result), 2);
  remove_matrix(&result);
}

TCase *tcase_create_matrix(void) {
  TCase *tcase = tcase_create("create_matrix");

  tcase_add_test(tcase, create_matrix_0);
  tcase_add_test(tcase, create_matrix_1);
  tcase_add_test(tcase, create_matrix_2);
  tcase_add_test(tcase, create_matrix_3);
  return tcase;
}
