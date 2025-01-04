#include "matrix_unit_test.h"

START_TEST(mult_matrix_0) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  create_matrix(2, 2, &answer);
  A.matrix[0][0] = 2.7, A.matrix[0][1] = -3.5;
  A.matrix[1][0] = 1.1, A.matrix[1][1] = 4.8;
  B.matrix[0][0] = -1.2, B.matrix[0][1] = 2.3;
  B.matrix[1][0] = 3.5, B.matrix[1][1] = -0.7;
  ck_assert_int_eq(mult_matrix(&A, &B, &result), 0);
  answer.matrix[0][0] = -15.49, answer.matrix[0][1] = 8.66;
  answer.matrix[1][0] = 15.48, answer.matrix[1][1] = -0.83;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(mult_matrix_1) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(2, 3, &A);
  create_matrix(3, 2, &B);
  create_matrix(2, 2, &answer);
  A.matrix[0][0] = -2.5, A.matrix[0][1] = 3.6, A.matrix[0][2] = -1.1;
  A.matrix[1][0] = 4.4, A.matrix[1][1] = -3.3, A.matrix[1][2] = 2.2;
  B.matrix[0][0] = 1.5, B.matrix[0][1] = -2.5;
  B.matrix[1][0] = -3.7, B.matrix[1][1] = 4.1;
  B.matrix[2][0] = 0.8, B.matrix[2][1] = -1.2;
  ck_assert_int_eq(mult_matrix(&A, &B, &result), 0);
  answer.matrix[0][0] = -17.950000, answer.matrix[0][1] = 22.330000;
  answer.matrix[1][0] = 20.570000, answer.matrix[1][1] = -27.170000;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(mult_matrix_2) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 4, &A);
  create_matrix(4, 3, &B);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 1.2, A.matrix[0][1] = -3.4, A.matrix[0][2] = 2.1,
  A.matrix[0][3] = -0.5;
  A.matrix[1][0] = 4.5, A.matrix[1][1] = 0.6;
  A.matrix[1][2] = -1.3, A.matrix[1][3] = 2.2;
  A.matrix[2][0] = -2.1, A.matrix[2][1] = 3.3;
  A.matrix[2][2] = 1.5, A.matrix[2][3] = -4;
  B.matrix[0][0] = 0.5, B.matrix[0][1] = -1.2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = -2.3;
  B.matrix[1][1] = 4.1;
  B.matrix[1][2] = -0.7;
  B.matrix[2][0] = 1.5, B.matrix[2][1] = -0.8;
  B.matrix[2][2] = 2.2;
  B.matrix[3][0] = 3.3;
  B.matrix[3][1] = -1.1;
  B.matrix[3][2] = 0;
  ck_assert_int_eq(mult_matrix(&A, &B, &result), 0);
  answer.matrix[0][0] = 9.92, answer.matrix[0][1] = -16.51,
  answer.matrix[0][2] = 10.6;
  answer.matrix[1][0] = 6.18, answer.matrix[1][1] = -4.32,
  answer.matrix[1][2] = 10.22;
  answer.matrix[2][0] = -19.59, answer.matrix[2][1] = 19.25,
  answer.matrix[2][2] = -5.31;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
  remove_matrix(&answer);
}

START_TEST(mult_matrix_3) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  create_matrix(2, 2, &answer);
  A.matrix[0][0] = 0, A.matrix[0][1] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  B.matrix[0][0] = 0, B.matrix[0][1] = 0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 0;
  ck_assert_int_eq(mult_matrix(&A, &B, &result), 0);
  answer.matrix[0][0] = 0, answer.matrix[0][1] = 0;
  answer.matrix[1][0] = 0;
  answer.matrix[1][1] = 0;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(mult_matrix_4) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  create_matrix(0, 0, &A);
  create_matrix(0, 0, &B);
  ck_assert_int_eq(mult_matrix(&A, &B, &result), 1);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(mult_matrix_5) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  create_matrix(-1, 0, &A);
  create_matrix(0, -5, &B);
  ck_assert_int_eq(mult_matrix(&A, &B, &result), 1);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(mult_matrix_6) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  create_matrix(2, 2, &answer);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 0, A.matrix[1][1] = 0;
  B.matrix[0][0] = 1, B.matrix[0][1] = 2;
  B.matrix[1][0] = 1, B.matrix[1][1] = 0;
  ck_assert_int_eq(mult_matrix(&A, &B, &result), 0);
  answer.matrix[0][0] = 2, answer.matrix[0][1] = 4;
  answer.matrix[1][0] = 7, answer.matrix[1][1] = 0;
  ck_assert_int_eq(eq_matrix(&result, &answer), 0);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(mult_matrix_7) {
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
  ck_assert_int_eq(mult_matrix(&A, &B, &result), 0);
  answer.matrix[0][0] = 9.75, answer.matrix[0][1] = 4.43;
  answer.matrix[1][0] = -3.95, answer.matrix[1][1] = 39.48;
  ck_assert_int_eq(eq_matrix(&result, &answer), 0);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&answer);
  remove_matrix(&result);
}

TCase *tcase_mult_matrix(void) {
  TCase *tcase = tcase_create("mult_matrix");

  tcase_add_test(tcase, mult_matrix_0);
  tcase_add_test(tcase, mult_matrix_1);
  tcase_add_test(tcase, mult_matrix_2);
  tcase_add_test(tcase, mult_matrix_3);
  tcase_add_test(tcase, mult_matrix_4);
  tcase_add_test(tcase, mult_matrix_5);
  tcase_add_test(tcase, mult_matrix_6);
  tcase_add_test(tcase, mult_matrix_7);
  return tcase;
}
