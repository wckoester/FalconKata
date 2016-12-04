#include <stdlib.h>
#include <check.h>

#include "../src/roman.h"

START_TEST(always_fail)
   ck_assert_int_eq(4,4);
END_TEST

START_TEST(always_pass)
   ck_assert_int_eq(3,3);
END_TEST

static Suite *roman_suite(void)
{
   Suite *s;
   TCase *tc_core;
   TCase *tc_limits;

   s = suite_create("Roman");
   
   tc_core = tcase_create("Core");

   tcase_add_test(tc_core, always_fail);
   suite_add_tcase(s, tc_core);

   tc_limits = tcase_create("Limits");

   tcase_add_test(tc_limits, always_pass);
   suite_add_tcase(s, tc_limits);

   return s;
}

int main(void)
{
   int number_failed;
   Suite *s;
   SRunner *sr;

   s = roman_suite();
   sr = srunner_create(s);

   srunner_run_all(sr, CK_VERBOSE);
   number_failed = srunner_ntests_failed(sr);
   srunner_free(sr);
   return(number_failed ==0) ? EXIT_SUCCESS : EXIT_FAILURE;   
}
