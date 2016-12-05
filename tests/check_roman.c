#include <stdlib.h>
#include <check.h>

#include "../src/roman.h"

typedef struct known_values {
    int  number;
    char *str;
} KNOWN_ROMANS;

static KNOWN_ROMANS roman_table[] = {
   {1, "I"},
   {2, "II"},
   {3, "III"},
   {4, "IV"},
   {5, "V"},
   {6, "VI"},
   {7, "VII"},
   {8, "VIII"},
   {9, "IX"},
   {10, "X"},
   {50, "L"},
   {100, "C"},
   {500, "D"},
   {1000, "M"},
   {31, "XXXI"},
   {148, "CXLVIII"},
   {294, "CCXCIV"},
   {312, "CCCXII"},
   {421, "CDXXI"},
   {528, "DXXVIII"},
   {621, "DCXXI"},
   {782, "DCCLXXXII"},
   {870, "DCCCLXX"},
   {941, "CMXLI"},
   {1043, "MXLIII"},
   {1110, "MCX"},
   {1226, "MCCXXVI"},
   {1301, "MCCCI"},
   {1485, "MCDLXXXV"},
   {1509, "MDIX"},
   {1607, "MDCVII"},
   {1754, "MDCCLIV"},
   {1832, "MDCCCXXXII"},
   {1993, "MCMXCIII"},
   {2074, "MMLXXIV"},
   {2152, "MMCLII"},
   {2212, "MMCCXII"},
   {2343, "MMCCCXLIII"},
   {2499, "MMCDXCIX"},
   {2574, "MMDLXXIV"},
   {2646, "MMDCXLVI"},
   {2723, "MMDCCXXIII"},
   {2892, "MMDCCCXCII"},
   {2975, "MMCMLXXV"},
   {3051, "MMMLI"},
   {3185, "MMMCLXXXV"},
   {3250, "MMMCCL"},
   {3313, "MMMCCCXIII"},
   {3408, "MMMCDVIII"},
   {3501, "MMMDI"},
   {3610, "MMMDCX"},
   {3743, "MMMDCCXLIII"},
   {3844, "MMMDCCCXLIV"},
   {3888, "MMMDCCCLXXXVIII"},
   {3940, "MMMCMXL"},
   {3999, "MMMCMXCIX"}
};

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

START_TEST(test_roman_to_int)
   int i;

   for(i=0;i<NELEMS(roman_table);i++)
   {
      ck_assert_int_eq(romanToInt(roman_table[i].str), roman_table[i].number);
   }
END_TEST

START_TEST(test_int_to_roman)
   int i;
   char buf[100];

   for(i=0;i<NELEMS(roman_table);i++)
   {
      intToRoman(roman_table[i].number, buf);
      ck_assert_str_eq(buf, roman_table[i].str);
   }
END_TEST

static Suite *roman_suite(void)
{
   Suite *s;
   TCase *tc_rtoi;
   TCase *tc_itor;

   s = suite_create("Roman");
   
   tc_rtoi = tcase_create("RomanToInt");

   tcase_add_test(tc_rtoi, test_roman_to_int);
   suite_add_tcase(s, tc_rtoi);

   tc_itor = tcase_create("IntToRoman");

   tcase_add_test(tc_itor, test_int_to_roman);
   suite_add_tcase(s, tc_itor);

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
