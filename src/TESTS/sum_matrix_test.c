#include "matrix_unit_test.h"

START_TEST(sum_matrix_0) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5, A.matrix[1][2] = 6;
  A.matrix[2][0] = 7, A.matrix[2][1] = 8, A.matrix[2][2] = 9;
  B.matrix[0][0] = 1, B.matrix[0][1] = 2, B.matrix[0][2] = 3;
  B.matrix[1][0] = 4, B.matrix[1][1] = 5, B.matrix[1][2] = 6;
  B.matrix[2][0] = 7, B.matrix[2][1] = 8, B.matrix[2][2] = 9;
  ck_assert_int_eq(sum_matrix(&A, &B, &result), 0);
  answer.matrix[0][0] = 2, answer.matrix[0][1] = 4, answer.matrix[0][2] = 6;
  answer.matrix[1][0] = 8, answer.matrix[1][1] = 10, answer.matrix[1][2] = 12;
  answer.matrix[2][0] = 14, answer.matrix[2][1] = 16, answer.matrix[2][2] = 18;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(sum_matrix_1) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 0, A.matrix[0][1] = 0, A.matrix[0][2] = 0;
  A.matrix[1][0] = 0, A.matrix[1][1] = 0, A.matrix[1][2] = 0;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 0;
  B.matrix[0][0] = 0, B.matrix[0][1] = 0, B.matrix[0][2] = 0;
  B.matrix[1][0] = 0, B.matrix[1][1] = 0, B.matrix[1][2] = 0;
  B.matrix[2][0] = 0, B.matrix[2][1] = 0, B.matrix[2][2] = 0;
  ck_assert_int_eq(sum_matrix(&A, &B, &result), 0);
  answer.matrix[0][0] = 0, answer.matrix[0][1] = 0, answer.matrix[0][2] = 0;
  answer.matrix[1][0] = 0, answer.matrix[1][1] = 0, answer.matrix[1][2] = 0;
  answer.matrix[2][0] = 0, answer.matrix[2][1] = 0, answer.matrix[2][2] = 0;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(sum_matrix_2) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  create_matrix(3, 2, &A);
  create_matrix(2, 3, &B);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5;
  A.matrix[2][0] = 7, A.matrix[2][1] = 8;
  B.matrix[0][0] = 1, B.matrix[0][1] = 2, B.matrix[0][2] = 4;
  B.matrix[1][0] = 5, B.matrix[1][1] = 7, B.matrix[1][2] = 8;
  ck_assert_int_eq(sum_matrix(&A, &B, &result), 2);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}

START_TEST(sum_matrix_3) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(1, 1, &A);
  create_matrix(1, 1, &B);
  create_matrix(1, 1, &answer);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 1;
  ck_assert_int_eq(sum_matrix(&A, &B, &result), 0);
  answer.matrix[0][0] = 2;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(sum_matrix_4) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(1, 3, &A);
  create_matrix(1, 3, &B);
  create_matrix(1, 3, &answer);
  A.matrix[0][0] = -180, A.matrix[0][1] = 1, A.matrix[0][2] = 99;
  B.matrix[0][0] = 180, B.matrix[0][1] = 1, B.matrix[0][2] = 99;
  ck_assert_int_eq(sum_matrix(&A, &B, &result), 0);
  answer.matrix[0][0] = 0, answer.matrix[0][1] = 2, answer.matrix[0][2] = 198;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(sum_matrix_5) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result;
  create_matrix(0, 0, &A);
  create_matrix(0, 0, &B);
  ck_assert_int_eq(sum_matrix(&A, &B, &result), 1);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(sum_matrix_6) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  create_matrix(2, 2, &answer);
  A.matrix[0][0] = 8.75, A.matrix[0][1] = -15.47;
  A.matrix[1][0] = -5.95, A.matrix[1][1] = 34.48;
  B.matrix[0][0] = 1, B.matrix[0][1] = 2;
  B.matrix[1][0] = 0.95, B.matrix[1][1] = 5.52;
  ck_assert_int_eq(sum_matrix(&A, &B, &result), 0);
  answer.matrix[0][0] = 9.75, answer.matrix[0][1] = -13.47;
  answer.matrix[1][0] = -5, answer.matrix[1][1] = 40;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(sum_matrix_7) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  create_matrix(2, 2, &answer);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5;
  B.matrix[0][0] = 1, B.matrix[0][1] = 2;
  B.matrix[1][0] = 4, B.matrix[1][1] = 5;
  ck_assert_int_eq(sum_matrix(&A, &B, &result), 0);
  answer.matrix[0][0] = 2, answer.matrix[0][1] = 4;
  answer.matrix[1][0] = 7, answer.matrix[1][1] = 0;
  ck_assert_int_eq(eq_matrix(&result, &answer), 0);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(sum_matrix_8) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  create_matrix(2, 2, &answer);
  A.matrix[0][0] = 8.75, A.matrix[0][1] = 2.43;
  A.matrix[1][0] = -5.95, A.matrix[1][1] = 34.48;
  B.matrix[0][0] = 1, B.matrix[0][1] = 2;
  B.matrix[1][0] = 2, B.matrix[1][1] = 5;
  ck_assert_int_eq(sum_matrix(&A, &B, &result), 0);
  answer.matrix[0][0] = 9.75, answer.matrix[0][1] = 4.43;
  answer.matrix[1][0] = -3.95, answer.matrix[1][1] = 39.48;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&answer);
  remove_matrix(&result);
}

TCase *tcase_sum_matrix(void) {
  TCase *tcase = tcase_create("sum_matrix");

  tcase_add_test(tcase, sum_matrix_0);
  tcase_add_test(tcase, sum_matrix_1);
  tcase_add_test(tcase, sum_matrix_2);
  tcase_add_test(tcase, sum_matrix_3);
  tcase_add_test(tcase, sum_matrix_4);
  tcase_add_test(tcase, sum_matrix_5);
  tcase_add_test(tcase, sum_matrix_6);
  tcase_add_test(tcase, sum_matrix_7);
  tcase_add_test(tcase, sum_matrix_8);
  return tcase;
}
