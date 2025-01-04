#include "matrix_unit_test.h"

START_TEST(transpose_0) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5, A.matrix[1][2] = 6;
  A.matrix[2][0] = 7, A.matrix[2][1] = 8, A.matrix[2][2] = 9;
  ck_assert_int_eq(transpose(&A, &result), 0);
  answer.matrix[0][0] = 1, answer.matrix[0][1] = 4, answer.matrix[0][2] = 7;
  answer.matrix[1][0] = 2, answer.matrix[1][1] = 5, answer.matrix[1][2] = 8;
  answer.matrix[2][0] = 3, answer.matrix[2][1] = 6, answer.matrix[2][2] = 9;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(transpose_1) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 0, A.matrix[0][1] = 0, A.matrix[0][2] = 0;
  A.matrix[1][0] = 0, A.matrix[1][1] = 0, A.matrix[1][2] = 0;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 0;
  ck_assert_int_eq(transpose(&A, &result), 0);
  answer.matrix[0][0] = 0, answer.matrix[0][1] = 0, answer.matrix[0][2] = 0;
  answer.matrix[1][0] = 0, answer.matrix[1][1] = 0, answer.matrix[1][2] = 0;
  answer.matrix[2][0] = 0, answer.matrix[2][1] = 0, answer.matrix[2][2] = 0;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(transpose_2) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(1, 3, &A);
  create_matrix(3, 1, &answer);
  A.matrix[0][0] = -5, A.matrix[0][1] = 12, A.matrix[0][2] = 53;
  ck_assert_int_eq(transpose(&A, &result), 0);
  answer.matrix[0][0] = -5;
  answer.matrix[1][0] = 12;
  answer.matrix[2][0] = 53;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(transpose_3) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(1, 2, &A);
  create_matrix(2, 1, &answer);
  A.matrix[0][0] = 1, A.matrix[0][1] = 0;
  ck_assert_int_eq(transpose(&A, &result), 0);
  answer.matrix[0][0] = 1;
  answer.matrix[1][0] = 0;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(transpose_4) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(2, 4, &A);
  create_matrix(4, 2, &answer);
  A.matrix[0][0] = 1.22, A.matrix[0][1] = -2.54, A.matrix[0][2] = 3.77,
  A.matrix[0][3] = 4.33;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5, A.matrix[1][2] = 6,
  A.matrix[1][3] = 4.55;
  ck_assert_int_eq(transpose(&A, &result), 0);
  answer.matrix[0][0] = 1.22, answer.matrix[0][1] = 4;
  answer.matrix[1][0] = -2.54, answer.matrix[1][1] = 5;
  answer.matrix[2][0] = 3.77, answer.matrix[2][1] = 6;
  answer.matrix[3][0] = 4.33, answer.matrix[3][1] = 4.55;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(transpose_5) {
  matrix_t A = {};
  matrix_t result = {};
  create_matrix(0, 0, &A);
  ck_assert_int_eq(transpose(&A, &result), 1);
  remove_matrix(&A);
  remove_matrix(&result);
}

START_TEST(transpose_6) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 0, A.matrix[0][1] = 0, A.matrix[0][2] = 0;
  A.matrix[1][0] = 0, A.matrix[1][1] = 0, A.matrix[1][2] = 0;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 0;
  ck_assert_int_eq(transpose(&A, &result), 0);
  answer.matrix[0][0] = 1, answer.matrix[0][1] = 0, answer.matrix[0][2] = 0;
  answer.matrix[1][0] = 0, answer.matrix[1][1] = 0, answer.matrix[1][2] = 0;
  answer.matrix[2][0] = 0, answer.matrix[2][1] = 0, answer.matrix[2][2] = 0;
  ck_assert_int_eq(eq_matrix(&result, &answer), 0);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(transpose_7) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(1, 3, &A);
  create_matrix(3, 1, &answer);
  A.matrix[0][0] = 0, A.matrix[0][1] = 0, A.matrix[0][2] = 0;
  ck_assert_int_eq(transpose(&A, &result), 0);
  answer.matrix[0][0] = 0;
  answer.matrix[1][0] = 0;
  answer.matrix[2][0] = 0;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

TCase *tcase_transpose(void) {
  TCase *tcase = tcase_create("transpose");

  tcase_add_test(tcase, transpose_0);
  tcase_add_test(tcase, transpose_1);
  tcase_add_test(tcase, transpose_2);
  tcase_add_test(tcase, transpose_3);
  tcase_add_test(tcase, transpose_4);
  tcase_add_test(tcase, transpose_5);
  tcase_add_test(tcase, transpose_6);
  tcase_add_test(tcase, transpose_7);
  return tcase;
}
