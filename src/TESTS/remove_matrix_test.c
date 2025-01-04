#include "matrix_unit_test.h"

START_TEST(remove_matrix_0) {
  matrix_t result = {};
  create_matrix(1, 1, &result);
  remove_matrix(&result);
  ck_assert_ptr_null(result.matrix);
}

START_TEST(remove_matrix_1) {
  matrix_t result = {};
  create_matrix(2, 2, &result);
  remove_matrix(&result);
  ck_assert_ptr_null(result.matrix);
}

START_TEST(remove_matrix_2) {
  matrix_t result = {};
  create_matrix(3, 3, &result);
  remove_matrix(&result);
  ck_assert_ptr_null(result.matrix);
}

TCase *tcase_remove_matrix(void) {
  TCase *tcase = tcase_create("remove_matrix");

  tcase_add_test(tcase, remove_matrix_0);
  tcase_add_test(tcase, remove_matrix_1);
  tcase_add_test(tcase, remove_matrix_2);
  return tcase;
}
