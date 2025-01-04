#include "matrix_unit_test.h"

START_TEST(eq_matrix_0) {
  matrix_t A = {};
  matrix_t B = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5, A.matrix[1][2] = 6;
  A.matrix[2][0] = 7, A.matrix[2][1] = 8, A.matrix[2][2] = 9;
  B.matrix[0][0] = 1, B.matrix[0][1] = 2, B.matrix[0][2] = 3;
  B.matrix[1][0] = 4, B.matrix[1][1] = 5, B.matrix[1][2] = 6;
  B.matrix[2][0] = 7, B.matrix[2][1] = 8, B.matrix[2][2] = 9;
  ck_assert_int_eq(eq_matrix(&A, &B), 1);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(eq_matrix_1) {
  matrix_t A = {};
  matrix_t B = {};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);
  A.matrix[0][0] = 0, A.matrix[0][1] = 0, A.matrix[0][2] = 0;
  A.matrix[1][0] = 0, A.matrix[1][1] = 0, A.matrix[1][2] = 0;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 0;
  B.matrix[0][0] = 0, B.matrix[0][1] = 0, B.matrix[0][2] = 0;
  B.matrix[1][0] = 0, B.matrix[1][1] = 0, B.matrix[1][2] = 0;
  B.matrix[2][0] = 0, B.matrix[2][1] = 0, B.matrix[2][2] = 0;
  ck_assert_int_eq(eq_matrix(&A, &B), 1);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(eq_matrix_2) {
  matrix_t A = {};
  matrix_t B = {};
  create_matrix(1, 1, &A);
  create_matrix(1, 1, &B);
  A.matrix[0][0] = -1.76;
  B.matrix[0][0] = -1.76;
  ck_assert_int_eq(eq_matrix(&A, &B), 1);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(eq_matrix_3) {
  matrix_t A = {};
  matrix_t B = {};
  create_matrix(2, 3, &A);
  create_matrix(3, 2, &B);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5, A.matrix[1][2] = 6;
  B.matrix[0][0] = 1, B.matrix[0][1] = 2;
  B.matrix[1][0] = 3, B.matrix[1][1] = 4;
  B.matrix[2][0] = 5, B.matrix[2][1] = 6;
  ck_assert_int_eq(eq_matrix(&A, &B), 0);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(eq_matrix_4) {
  matrix_t A = {};
  matrix_t B = {};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2;
  A.matrix[1][0] = 4, A.matrix[1][1] = 5;
  B.matrix[0][0] = 1, B.matrix[0][1] = 2;
  B.matrix[1][0] = 3, B.matrix[1][1] = 5;
  ck_assert_int_eq(eq_matrix(&A, &B), 0);
  remove_matrix(&A);
  remove_matrix(&B);
}

TCase *tcase_eq_matrix(void) {
  TCase *tcase = tcase_create("eq_matrix");

  tcase_add_test(tcase, eq_matrix_0);
  tcase_add_test(tcase, eq_matrix_1);
  tcase_add_test(tcase, eq_matrix_2);
  tcase_add_test(tcase, eq_matrix_3);
  tcase_add_test(tcase, eq_matrix_4);
  return tcase;
}
