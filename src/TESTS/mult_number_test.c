#include "matrix_unit_test.h"

START_TEST(mult_number_0) {
  matrix_t A = {};
  int num = 0;
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5, A.matrix[1][2] = 6;
  A.matrix[2][0] = 7, A.matrix[2][1] = 8, A.matrix[2][2] = 9;
  ck_assert_int_eq(mult_number(&A, num, &result), 0);
  answer.matrix[0][0] = 0, answer.matrix[0][1] = 0, answer.matrix[0][2] = 0;
  answer.matrix[1][0] = 0, answer.matrix[1][1] = 0, answer.matrix[1][2] = 0;
  answer.matrix[2][0] = 0, answer.matrix[2][1] = 0, answer.matrix[2][2] = 0;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(mult_number_1) {
  matrix_t A = {};
  int num = 1;
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5, A.matrix[1][2] = 6;
  A.matrix[2][0] = 7, A.matrix[2][1] = 8, A.matrix[2][2] = 9;
  ck_assert_int_eq(mult_number(&A, num, &result), 0);
  answer.matrix[0][0] = 1, answer.matrix[0][1] = 2, answer.matrix[0][2] = 3;
  answer.matrix[1][0] = 4, answer.matrix[1][1] = 5, answer.matrix[1][2] = 6;
  answer.matrix[2][0] = 7, answer.matrix[2][1] = 8, answer.matrix[2][2] = 9;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(mult_number_2) {
  matrix_t A = {};
  int num = -5;
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5, A.matrix[1][2] = 6;
  A.matrix[2][0] = 7, A.matrix[2][1] = 8, A.matrix[2][2] = 9;
  ck_assert_int_eq(mult_number(&A, num, &result), 0);
  answer.matrix[0][0] = -5, answer.matrix[0][1] = -10,
  answer.matrix[0][2] = -15;
  answer.matrix[1][0] = -20, answer.matrix[1][1] = -25,
  answer.matrix[1][2] = -30;
  answer.matrix[2][0] = -35, answer.matrix[2][1] = -40,
  answer.matrix[2][2] = -45;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(mult_number_3) {
  matrix_t A = {};
  int num = 10;
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(1, 1, &A);
  create_matrix(1, 1, &answer);
  A.matrix[0][0] = 1;
  ck_assert_int_eq(mult_number(&A, num, &result), 0);
  answer.matrix[0][0] = 10;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(mult_number_4) {
  matrix_t A = {};
  int num = 14;
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(0, 0, &A);
  create_matrix(0, 0, &answer);
  ck_assert_int_eq(mult_number(&A, num, &result), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(mult_number_5) {
  matrix_t A = {};
  int num = 8;
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &answer);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5;
  ck_assert_int_eq(mult_number(&A, num, &result), 0);
  answer.matrix[0][0] = -8, answer.matrix[0][1] = -15;
  answer.matrix[1][0] = -20, answer.matrix[1][1] = -25;
  ck_assert_int_eq(eq_matrix(&result, &answer), 0);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(mult_number_6) {
  matrix_t A = {};
  int num = -5;
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(1, 3, &A);
  create_matrix(1, 3, &answer);
  A.matrix[0][0] = -45, A.matrix[0][1] = 2.55, A.matrix[0][2] = -3.22;
  ck_assert_int_eq(mult_number(&A, num, &result), 0);
  answer.matrix[0][0] = 225, answer.matrix[0][1] = -12.75,
  answer.matrix[0][2] = 16.1;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

TCase *tcase_mult_number(void) {
  TCase *tcase = tcase_create("mult_number");

  tcase_add_test(tcase, mult_number_0);
  tcase_add_test(tcase, mult_number_1);
  tcase_add_test(tcase, mult_number_2);
  tcase_add_test(tcase, mult_number_3);
  tcase_add_test(tcase, mult_number_4);
  tcase_add_test(tcase, mult_number_5);
  tcase_add_test(tcase, mult_number_6);
  return tcase;
}
