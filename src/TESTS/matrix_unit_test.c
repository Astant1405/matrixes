#include "matrix_unit_test.h"

// Объявление тестовых кейсов
Suite *make_s21matrix_suite(void);
TCase *tcase_create_matrix(void);
TCase *tcase_remove_matrix(void);
TCase *tcase_eq_matrix(void);
TCase *tcase_sum_matrix(void);
TCase *tcase_sub_matrix(void);
TCase *tcase_mult_number(void);
TCase *tcase_mult_matrix(void);
TCase *tcase_transpose(void);
TCase *tcase_calc_complements(void);
TCase *tcase_determinant(void);
TCase *tcase_inverse_matrix(void);

int main(void) {
  setlocale(LC_ALL, "UTF-8");
  int number_failed = 0;
  Suite *suite = make_s21matrix_suite();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

Suite *make_s21matrix_suite() {
  Suite *suite = suite_create("TESTING - matrix.h");

  suite_add_tcase(suite, tcase_create_matrix());
  suite_add_tcase(suite, tcase_remove_matrix());
  suite_add_tcase(suite, tcase_eq_matrix());
  suite_add_tcase(suite, tcase_sum_matrix());
  suite_add_tcase(suite, tcase_sub_matrix());
  suite_add_tcase(suite, tcase_mult_number());
  suite_add_tcase(suite, tcase_mult_matrix());
  suite_add_tcase(suite, tcase_transpose());
  suite_add_tcase(suite, tcase_calc_complements());
  suite_add_tcase(suite, tcase_determinant());
  suite_add_tcase(suite, tcase_inverse_matrix());

  return suite;
}
