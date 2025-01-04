#include "matrix_unit_test.h"

START_TEST(determinant_0) {
  matrix_t A = {};
  double result;
  create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5, A.matrix[1][2] = 6;
  A.matrix[2][0] = 7, A.matrix[2][1] = 8, A.matrix[2][2] = 9;
  ck_assert_int_eq(determinant(&A, &result), 0);
  ck_assert_double_eq(result, 0);
  remove_matrix(&A);
}

START_TEST(determinant_1) {
  matrix_t A = {};
  double result;
  create_matrix(3, 3, &A);
  A.matrix[0][0] = 0, A.matrix[0][1] = 0, A.matrix[0][2] = 0;
  A.matrix[1][0] = 0, A.matrix[1][1] = 0, A.matrix[1][2] = 0;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 0;
  ck_assert_int_eq(determinant(&A, &result), 0);
  ck_assert_double_eq(result, 0);
  remove_matrix(&A);
}

START_TEST(determinant_2) {
  matrix_t A = {};
  double result;
  create_matrix(2, 2, &A);
  A.matrix[0][0] = 54, A.matrix[0][1] = 12;
  A.matrix[1][0] = -34, A.matrix[1][1] = -4.8;
  ck_assert_int_eq(determinant(&A, &result), 0);
  ck_assert_double_eq(result, 148.8);
  remove_matrix(&A);
}

START_TEST(determinant_3) {
  matrix_t A = {};
  double result;
  create_matrix(1, 1, &A);
  A.matrix[0][0] = 55;
  ck_assert_int_eq(determinant(&A, &result), 0);
  ck_assert_double_eq(result, 55);
  remove_matrix(&A);
}

START_TEST(determinant_4) {
  matrix_t A = {};
  double result;
  create_matrix(4, 4, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3,
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 8, A.matrix[1][1] = 9, A.matrix[1][2] = 6,
  A.matrix[1][3] = 5;
  A.matrix[2][0] = 7, A.matrix[2][1] = 10, A.matrix[2][2] = 11,
  A.matrix[2][3] = 14;
  A.matrix[3][0] = 12, A.matrix[3][1] = 13, A.matrix[3][2] = 13,
  A.matrix[3][3] = 15;
  ck_assert_int_eq(determinant(&A, &result), 0);
  ck_assert_double_eq(result, 34);
  remove_matrix(&A);
}

START_TEST(determinant_5) {
  matrix_t A = {};
  double result;
  create_matrix(0, 0, &A);
  ck_assert_int_eq(determinant(&A, &result), 1);
  remove_matrix(&A);
}

START_TEST(determinant_6) {
  matrix_t A = {};
  double result;
  create_matrix(3, 3, &A);
  A.matrix[0][0] = 7, A.matrix[0][1] = 5, A.matrix[0][2] = 12;
  A.matrix[1][0] = 15, A.matrix[1][1] = 88, A.matrix[1][2] = 22;
  A.matrix[2][0] = 48, A.matrix[2][1] = 20, A.matrix[2][2] = 14;
  ck_assert_int_eq(determinant(&A, &result), 0);
  ck_assert_double_eq(result, -37314);
  remove_matrix(&A);
}

START_TEST(determinant_7) {
  matrix_t A = {};
  double result;
  create_matrix(3, 3, &A);
  A.matrix[0][0] = 7.77, A.matrix[0][1] = 5.55, A.matrix[0][2] = 12.11;
  A.matrix[1][0] = 15.55, A.matrix[1][1] = 88.88, A.matrix[1][2] = 22.22;
  A.matrix[2][0] = 48.44, A.matrix[2][1] = 20, A.matrix[2][2] = 14.44;
  ck_assert_int_eq(determinant(&A, &result), 0);
  ck_assert_double_eq(result, -37124.842108);
  remove_matrix(&A);
}

TCase *tcase_determinant(void) {
  TCase *tcase = tcase_create("determinant");

  tcase_add_test(tcase, determinant_0);
  tcase_add_test(tcase, determinant_1);
  tcase_add_test(tcase, determinant_2);
  tcase_add_test(tcase, determinant_3);
  tcase_add_test(tcase, determinant_4);
  tcase_add_test(tcase, determinant_5);
  tcase_add_test(tcase, determinant_6);
  tcase_add_test(tcase, determinant_7);
  return tcase;
}
