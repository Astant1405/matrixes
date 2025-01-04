#include "matrix_unit_test.h"

START_TEST(calc_complements_0) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &answer);
  A.matrix[0][0] = -1.5, A.matrix[0][1] = 2.3;
  A.matrix[1][0] = 4, A.matrix[1][1] = -3.2;
  ck_assert_int_eq(calc_complements(&A, &result), 0);
  answer.matrix[0][0] = -3.2, answer.matrix[0][1] = -4;
  answer.matrix[1][0] = -2.3, answer.matrix[1][1] = -1.5;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(calc_complements_1) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 1.2, A.matrix[0][1] = -3.5, A.matrix[0][2] = 4.1;
  A.matrix[1][0] = -2, A.matrix[1][1] = 5.5, A.matrix[1][2] = -1.3;
  A.matrix[2][0] = 3.3, A.matrix[2][1] = -4.2, A.matrix[2][2] = 2.2;
  ck_assert_int_eq(calc_complements(&A, &result), 0);
  answer.matrix[0][0] = 6.64, answer.matrix[0][1] = 0.11,
  answer.matrix[0][2] = -9.75;
  answer.matrix[1][0] = -9.52, answer.matrix[1][1] = -10.89,
  answer.matrix[1][2] = -6.51;
  answer.matrix[2][0] = -18, answer.matrix[2][1] = -6.64,
  answer.matrix[2][2] = -0.4;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(calc_complements_2) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 1.1, A.matrix[0][1] = 2.4, A.matrix[0][2] = 3.5;
  A.matrix[1][0] = 0, A.matrix[1][1] = -2.2, A.matrix[1][2] = 1.1;
  A.matrix[2][0] = 4.4, A.matrix[2][1] = -3.3, A.matrix[2][2] = 5.5;
  ck_assert_int_eq(calc_complements(&A, &result), 0);
  answer.matrix[0][0] = -8.47, answer.matrix[0][1] = 4.84,
  answer.matrix[0][2] = 9.68;
  answer.matrix[1][0] = -24.75, answer.matrix[1][1] = -9.35,
  answer.matrix[1][2] = 14.19;
  answer.matrix[2][0] = 10.34, answer.matrix[2][1] = -1.21,
  answer.matrix[2][2] = -2.42;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(calc_complements_3) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(4, 4, &A);
  create_matrix(4, 4, &answer);
  A.matrix[0][0] = -1, A.matrix[0][1] = 2, A.matrix[0][2] = -3,
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 5, A.matrix[1][1] = -6, A.matrix[1][2] = 7,
  A.matrix[1][3] = -8;
  A.matrix[2][0] = 9, A.matrix[2][1] = -10, A.matrix[2][2] = 11,
  A.matrix[2][3] = -12;
  A.matrix[3][0] = -13, A.matrix[3][1] = 14, A.matrix[3][2] = -15,
  A.matrix[3][3] = 16;
  ck_assert_int_eq(calc_complements(&A, &result), 0);
  answer.matrix[0][0] = 0, answer.matrix[0][1] = 0, answer.matrix[0][2] = 0,
  answer.matrix[0][3] = 0;
  answer.matrix[1][0] = 0, answer.matrix[1][1] = 0, answer.matrix[1][2] = 0,
  answer.matrix[1][3] = 0;
  answer.matrix[2][0] = 0, answer.matrix[2][1] = 0, answer.matrix[2][2] = 0,
  answer.matrix[2][3] = 0;
  answer.matrix[3][0] = 0, answer.matrix[3][1] = 0, answer.matrix[3][2] = 0,
  answer.matrix[3][3] = 0;
  ck_assert_int_eq(eq_matrix(&result, &answer), 1);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(calc_complements_4) {
  matrix_t A = {};
  matrix_t result = {};
  create_matrix(0, 0, &A);
  ck_assert_int_eq(calc_complements(&A, &result), 1);
  remove_matrix(&A);
}

START_TEST(calc_complements_5) {
  matrix_t A = {};
  matrix_t result = {};
  create_matrix(1, 1, &A);
  ck_assert_int_eq(calc_complements(&A, &result), 2);
  remove_matrix(&A);
}

START_TEST(calc_complements_6) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 6.1, A.matrix[0][1] = 2.4, A.matrix[0][2] = 3.5;
  A.matrix[1][0] = -14, A.matrix[1][1] = -2.2, A.matrix[1][2] = 1.1;
  A.matrix[2][0] = 22, A.matrix[2][1] = -3.3, A.matrix[2][2] = 5.5;
  ck_assert_int_eq(calc_complements(&A, &result), 0);
  answer.matrix[0][0] = -8.47, answer.matrix[0][1] = -4.84,
  answer.matrix[0][2] = 9.68;
  answer.matrix[1][0] = 12.02, answer.matrix[1][1] = -24.3,
  answer.matrix[1][2] = -6.8;
  answer.matrix[2][0] = 34.27, answer.matrix[2][1] = 27.55,
  answer.matrix[2][2] = -11.6;
  ck_assert_int_eq(eq_matrix(&result, &answer), 0);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

START_TEST(calc_complements_7) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t answer = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &answer);
  A.matrix[0][0] = 1.1, A.matrix[0][1] = 74, A.matrix[0][2] = 3.5;
  A.matrix[1][0] = 0, A.matrix[1][1] = 7.2, A.matrix[1][2] = 1.1;
  A.matrix[2][0] = 4.4, A.matrix[2][1] = 11.3, A.matrix[2][2] = 5.5;
  ck_assert_int_eq(calc_complements(&A, &result), 0);
  answer.matrix[0][0] = -8.47, answer.matrix[0][1] = -4.84,
  answer.matrix[0][2] = 9.68;
  answer.matrix[1][0] = 12.02, answer.matrix[1][1] = 17.3,
  answer.matrix[1][2] = -6.8;
  answer.matrix[2][0] = -14.27, answer.matrix[2][1] = 12.55,
  answer.matrix[2][2] = -11.6;
  ck_assert_int_eq(eq_matrix(&result, &answer), 0);
  remove_matrix(&A);
  remove_matrix(&answer);
  remove_matrix(&result);
}

TCase *tcase_calc_complements(void) {
  TCase *tcase = tcase_create("calc_complements");

  tcase_add_test(tcase, calc_complements_0);
  tcase_add_test(tcase, calc_complements_1);
  tcase_add_test(tcase, calc_complements_2);
  tcase_add_test(tcase, calc_complements_3);
  tcase_add_test(tcase, calc_complements_4);
  tcase_add_test(tcase, calc_complements_5);
  tcase_add_test(tcase, calc_complements_6);
  tcase_add_test(tcase, calc_complements_7);
  return tcase;
}
