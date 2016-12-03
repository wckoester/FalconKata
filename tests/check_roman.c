#include <stdlib.h>
#include <check.h>

#include "../src/roman.h"

START_TEST(always_fail)
   ck_assert_int_eq(3,4);
END_TEST

static Suite *roman_suite(void)
{
   Suite *s;
   TCase *tc_core;

   s = suite_create("Roman");
   
   tc_core = tcase_create("Core");

   tcase_add_test(tc_core, always_fail);

   suite_add_tcase(s, tc_core);

   return s;
}

int main(void)
{
   int number_failed;
   Suite *s;
   SRunner *sr;

   s = roman_suite();
   sr = srunner_create(s);

   srunner_run_all(sr, CK_NORMAL);
   number_failed = srunner_ntests_failed(sr);
   srunner_free(sr);
   return(number_failed ==0) ? EXIT_SUCCESS : EXIT_FAILURE;   
}
