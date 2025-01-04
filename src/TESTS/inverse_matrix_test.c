#include "matrix_unit_test.h"

START_TEST(inverse_matrix_0) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &answer);
  A.matrix[0][0] = -1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 4, A.matrix[1][1] = -3;
  ck_assert_int_eq(inverse_matrix(&A, &result), 0);
  answer.matrix[0][0] = 0.6, answer.matrix[0][1] = 0.4;
  answer.matrix[1][0] = 0.8, answer.matrix[1][1] = 0.2;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(inverse_matrix_1) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 1, A.matrix[0][1] = 1, A.matrix[0][2] = 2;
  A.matrix[1][0] = 2, A.matrix[1][1] = 5, A.matrix[1][2] = 0;
  A.matrix[2][0] = 1, A.matrix[2][1] = 2, A.matrix[2][2] = 2;
  ck_assert_int_eq(inverse_matrix(&A, &result), 0);
  answer.matrix[0][0] = 2.5, answer.matrix[0][1] = 0.5,
  answer.matrix[0][2] = -2.5;
  answer.matrix[1][0] = -1, answer.matrix[1][1] = 0, answer.matrix[1][2] = 1;
  answer.matrix[2][0] = -0.25, answer.matrix[2][1] = -0.25,
  answer.matrix[2][2] = 0.75;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(inverse_matrix_2) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 1, A.matrix[0][1] = 12, A.matrix[0][2] = 1;
  A.matrix[1][0] = 0, A.matrix[1][1] = 1, A.matrix[1][2] = 1;
  A.matrix[2][0] = 1, A.matrix[2][1] = 13, A.matrix[2][2] = 1;
  ck_assert_int_eq(inverse_matrix(&A, &result), 0);
  answer.matrix[0][0] = 12, answer.matrix[0][1] = -1, answer.matrix[0][2] = -11;
  answer.matrix[1][0] = -1, answer.matrix[1][1] = 0, answer.matrix[1][2] = 1;
  answer.matrix[2][0] = 1, answer.matrix[2][1] = 1, answer.matrix[2][2] = -1;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(inverse_matrix_3) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(4, 4, &A);
  create_matrix(4, 4, &answer);
  A.matrix[0][0] = 3, A.matrix[0][1] = 3, A.matrix[0][2] = 4,
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 3, A.matrix[1][1] = 0, A.matrix[1][2] = 0,
  A.matrix[1][3] = 4;
  A.matrix[2][0] = 2, A.matrix[2][1] = 0, A.matrix[2][2] = 0,
  A.matrix[2][3] = 6;
  A.matrix[3][0] = 2, A.matrix[3][1] = 2, A.matrix[3][2] = 6,
  A.matrix[3][3] = 6;
  ck_assert_int_eq(inverse_matrix(&A, &result), 0);
  answer.matrix[0][0] = 0, answer.matrix[0][1] = 0.6,
  answer.matrix[0][2] = -0.4, answer.matrix[0][3] = 0;
  answer.matrix[1][0] = 0.6, answer.matrix[1][1] = -0.6,
  answer.matrix[1][2] = 0.4, answer.matrix[1][3] = -0.4;
  answer.matrix[2][0] = -0.2, answer.matrix[2][1] = 0.2,
  answer.matrix[2][2] = -0.3, answer.matrix[2][3] = 0.3;
  answer.matrix[3][0] = 0, answer.matrix[3][1] = -0.2,
  answer.matrix[3][2] = 0.3, answer.matrix[3][3] = 0;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(inverse_matrix_4) {
  matrix_t A = {};
  matrix_t result = {};
  create_matrix(0, 0, &A);
  ck_assert_int_eq(inverse_matrix(&A, &result), 1);
  remove_matrix(&A);
}

START_TEST(inverse_matrix_5) {
  matrix_t A = {};
  matrix_t result = {};
  create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  ck_assert_int_eq(inverse_matrix(&A, &result), 2);
  remove_matrix(&A);
}

START_TEST(inverse_matrix_6) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &answer);
  A.matrix[0][0] = 3, A.matrix[0][1] = 3.5;
  A.matrix[1][0] = 1, A.matrix[1][1] = 1.5;
  ck_assert_int_eq(inverse_matrix(&A, &result), 0);
  answer.matrix[0][0] = 1.5, answer.matrix[0][1] = -3.5;
  answer.matrix[1][0] = 0, answer.matrix[1][1] = 3;
  ck_assert_int_eq(eq_matrix(&result, &answer), 0);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(inverse_matrix_7) {
  matrix_t A = {};
  matrix_t result = {};
  create_matrix(3, 3, &A);
  A.matrix[0][0] = 0, A.matrix[0][1] = 0, A.matrix[0][2] = 0;
  A.matrix[1][0] = 0, A.matrix[1][1] = 0, A.matrix[1][2] = 0;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 0;
  ck_assert_int_eq(inverse_matrix(&A, &result), 2);
  remove_matrix(&A);
  remove_matrix(&result);
}

TCase *tcase_inverse_matrix(void) {
  TCase *tcase = tcase_create("inverse_matrix");

  tcase_add_test(tcase, inverse_matrix_0);
  tcase_add_test(tcase, inverse_matrix_1);
  tcase_add_test(tcase, inverse_matrix_2);
  tcase_add_test(tcase, inverse_matrix_3);
  tcase_add_test(tcase, inverse_matrix_4);
  tcase_add_test(tcase, inverse_matrix_5);
  tcase_add_test(tcase, inverse_matrix_6);
  tcase_add_test(tcase, inverse_matrix_7);
  return tcase;
}
