#include "../s21_decimal.h"
#include "test.h"

int numb_test_is_equal = 0;
int numb_test_is_greater = 0;
int numb_test_is_greater_or_equal = 0;
int numb_test_is_less = 0;
int numb_test_is_less_or_equal = 0;
int numb_test_is_not_equal = 0;

START_TEST(test_is_equal_1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  test_is_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_equal_2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 0;
  test_is_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_equal_3) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;
  test_is_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_equal_4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 0;
  test_is_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_equal_5) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 1;
  test_is_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_equal_6) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  int check = 1;
  test_is_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_equal_7) {
  // 5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x00030000}};
  // 5
  s21_decimal decimal2 = {{0x00000005, 0x0, 0x0, 0x0}};
  int check = 1;
  test_is_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_equal_8) {
  // 5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x00030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 1;
  test_is_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_equal_9) {
  // 500.000
  s21_decimal decimal1 = {{0x0007A120, 0x0, 0x0, 0x00030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 0;
  test_is_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_equal_10) {
  // -5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x80030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 0;
  test_is_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_equal_11) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = 1;
  test_is_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_equal_12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;
  test_is_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 1;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_3) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 1;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_5) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 0;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_6) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  int check = 0;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_7) {
  // 5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x00030000}};
  // 5
  s21_decimal decimal2 = {{0x00000005, 0x0, 0x0, 0x0}};
  int check = 0;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_8) {
  // 5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x00030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 0;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_9) {
  // 500.000
  s21_decimal decimal1 = {{0x0007A120, 0x0, 0x0, 0x00030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 1;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_10) {
  // -5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x80030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 0;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_11) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = 0;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_13) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -1.2297829382003034409
  s21_decimal decimal2 = {{0x8EA70929, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 0;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_14) {
  // -10
  s21_decimal decimal1 = {{0x0000000A, 0x0, 0x0, 0x80000000}};
  // -5
  s21_decimal decimal2 = {{0x00000005, 0x0, 0x0, 0x80000000}};
  int check = 0;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_15) {
  // -10.867568
  s21_decimal decimal1 = {{0x00A5D370, 0x0, 0x0, 0x80060000}};
  // -5332.4546656
  s21_decimal decimal2 = {{0x6A640260, 0x0000000C, 0x0, 0x80070000}};
  int check = 1;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_16) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  int check = 0;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_17) {
  // 10
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int check = 1;
  test_is_greater(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 1;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_3) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 1;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_5) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 1;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_6) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  int check = 1;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_7) {
  // 5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x00030000}};
  // 5
  s21_decimal decimal2 = {{0x00000005, 0x0, 0x0, 0x0}};
  int check = 1;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_8) {
  // 5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x00030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 1;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_9) {
  // 500.000
  s21_decimal decimal1 = {{0x0007A120, 0x0, 0x0, 0x00030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 1;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_10) {
  // -5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x80030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 0;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_11) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = 1;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_13) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -1.2297829382003034409
  s21_decimal decimal2 = {{0x8EA70929, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 0;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_14) {
  // -10
  s21_decimal decimal1 = {{0x0000000A, 0x0, 0x0, 0x80000000}};
  // -5
  s21_decimal decimal2 = {{0x00000005, 0x0, 0x0, 0x80000000}};
  int check = 0;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_15) {
  // -10.867568
  s21_decimal decimal1 = {{0x00A5D370, 0x0, 0x0, 0x80060000}};
  // -5332.4546656
  s21_decimal decimal2 = {{0x6A640260, 0x0000000C, 0x0, 0x80070000}};
  int check = 1;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_16) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  int check = 0;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_greater_or_equal_17) {
  // 10
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int check = 1;
  test_is_greater_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_1) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = 0;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 0;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_3) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 0;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_5) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 0;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_6) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  int check = 0;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_7) {
  // 5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x00030000}};
  // 5
  s21_decimal decimal2 = {{0x00000005, 0x0, 0x0, 0x0}};
  int check = 0;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_8) {
  // 5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x00030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 0;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_9) {
  // 500.000
  s21_decimal decimal1 = {{0x0007A120, 0x0, 0x0, 0x00030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 0;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_10) {
  // -5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x80030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 1;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_11) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = 0;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_13) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -1.2297829382003034409
  s21_decimal decimal2 = {{0x8EA70929, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 1;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_14) {
  // -10
  s21_decimal decimal1 = {{0x0000000A, 0x0, 0x0, 0x80000000}};
  // -5
  s21_decimal decimal2 = {{0x00000005, 0x0, 0x0, 0x80000000}};
  int check = 1;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_15) {
  // -10.867568
  s21_decimal decimal1 = {{0x00A5D370, 0x0, 0x0, 0x80060000}};
  // -5332.4546656
  s21_decimal decimal2 = {{0x6A640260, 0x0000000C, 0x0, 0x80070000}};
  int check = 0;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_16) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  int check = 1;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_17) {
  // 10
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int check = 0;
  test_is_less(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 0;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_3) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 0;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_5) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 1;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_6) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  int check = 1;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_7) {
  // 5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x00030000}};
  // 5
  s21_decimal decimal2 = {{0x00000005, 0x0, 0x0, 0x0}};
  int check = 1;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_8) {
  // 5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x00030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 1;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_9) {
  // 500.000
  s21_decimal decimal1 = {{0x0007A120, 0x0, 0x0, 0x00030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 0;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_10) {
  // -5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x80030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 1;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_11) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = 1;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_13) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -1.2297829382003034409
  s21_decimal decimal2 = {{0x8EA70929, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 1;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_14) {
  // -10
  s21_decimal decimal1 = {{0x0000000A, 0x0, 0x0, 0x80000000}};
  // -5
  s21_decimal decimal2 = {{0x00000005, 0x0, 0x0, 0x80000000}};
  int check = 1;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_15) {
  // -10.867568
  s21_decimal decimal1 = {{0x00A5D370, 0x0, 0x0, 0x80060000}};
  // -5332.4546656
  s21_decimal decimal2 = {{0x6A640260, 0x0000000C, 0x0, 0x80070000}};
  int check = 0;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_16) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  int check = 1;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_less_or_equal_17) {
  // 10
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int check = 0;
  test_is_less_or_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 1;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_3) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 1;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_5) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 0;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_6) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x00130000}};
  int check = 0;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_7) {
  // 5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x00030000}};
  // 5
  s21_decimal decimal2 = {{0x00000005, 0x0, 0x0, 0x0}};
  int check = 0;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_8) {
  // 5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x00030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 0;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_9) {
  // 500.000
  s21_decimal decimal1 = {{0x0007A120, 0x0, 0x0, 0x00030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 1;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_10) {
  // -5.000
  s21_decimal decimal1 = {{0x00001388, 0x0, 0x0, 0x80030000}};
  // 5.00000
  s21_decimal decimal2 = {{0x0007A120, 0x0, 0x0, 0x00050000}};
  int check = 1;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_11) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = 0;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_13) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -1.2297829382003034409
  s21_decimal decimal2 = {{0x8EA70929, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 1;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_14) {
  // -10
  s21_decimal decimal1 = {{0x0000000A, 0x0, 0x0, 0x80000000}};
  // -5
  s21_decimal decimal2 = {{0x00000005, 0x0, 0x0, 0x80000000}};
  int check = 1;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_is_not_equal_15) {
  // -10.867568
  s21_decimal decimal1 = {{0x00A5D370, 0x0, 0x0, 0x80060000}};
  // -5332.4546656
  s21_decimal decimal2 = {{0x6A640260, 0x0000000C, 0x0, 0x80070000}};
  int check = 1;
  test_is_not_equal(decimal1, decimal2, check);
}
END_TEST

Suite *suite_comp(void) {
  Suite *s = suite_create("test_comparison");

  TCase *tcase_comp = tcase_create("test_comp_tc");

  tcase_add_test(tcase_comp, test_is_equal_1);
  tcase_add_test(tcase_comp, test_is_equal_2);
  tcase_add_test(tcase_comp, test_is_equal_3);
  tcase_add_test(tcase_comp, test_is_equal_4);
  tcase_add_test(tcase_comp, test_is_equal_5);
  tcase_add_test(tcase_comp, test_is_equal_6);
  tcase_add_test(tcase_comp, test_is_equal_7);
  tcase_add_test(tcase_comp, test_is_equal_8);
  tcase_add_test(tcase_comp, test_is_equal_9);
  tcase_add_test(tcase_comp, test_is_equal_10);
  tcase_add_test(tcase_comp, test_is_equal_11);
  tcase_add_test(tcase_comp, test_is_equal_12);
  tcase_add_test(tcase_comp, test_is_greater_1);
  tcase_add_test(tcase_comp, test_is_greater_2);
  tcase_add_test(tcase_comp, test_is_greater_3);
  tcase_add_test(tcase_comp, test_is_greater_4);
  tcase_add_test(tcase_comp, test_is_greater_5);
  tcase_add_test(tcase_comp, test_is_greater_6);
  tcase_add_test(tcase_comp, test_is_greater_7);
  tcase_add_test(tcase_comp, test_is_greater_8);
  tcase_add_test(tcase_comp, test_is_greater_9);
  tcase_add_test(tcase_comp, test_is_greater_10);
  tcase_add_test(tcase_comp, test_is_greater_11);
  tcase_add_test(tcase_comp, test_is_greater_12);
  tcase_add_test(tcase_comp, test_is_greater_13);
  tcase_add_test(tcase_comp, test_is_greater_14);
  tcase_add_test(tcase_comp, test_is_greater_15);
  tcase_add_test(tcase_comp, test_is_greater_16);
  tcase_add_test(tcase_comp, test_is_greater_17);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_1);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_2);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_3);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_4);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_5);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_6);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_7);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_8);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_9);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_10);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_11);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_12);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_13);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_14);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_15);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_16);
  tcase_add_test(tcase_comp, test_is_greater_or_equal_17);
  tcase_add_test(tcase_comp, test_is_less_1);
  tcase_add_test(tcase_comp, test_is_less_2);
  tcase_add_test(tcase_comp, test_is_less_3);
  tcase_add_test(tcase_comp, test_is_less_4);
  tcase_add_test(tcase_comp, test_is_less_5);
  tcase_add_test(tcase_comp, test_is_less_6);
  tcase_add_test(tcase_comp, test_is_less_7);
  tcase_add_test(tcase_comp, test_is_less_8);
  tcase_add_test(tcase_comp, test_is_less_9);
  tcase_add_test(tcase_comp, test_is_less_10);
  tcase_add_test(tcase_comp, test_is_less_11);
  tcase_add_test(tcase_comp, test_is_less_12);
  tcase_add_test(tcase_comp, test_is_less_13);
  tcase_add_test(tcase_comp, test_is_less_14);
  tcase_add_test(tcase_comp, test_is_less_15);
  tcase_add_test(tcase_comp, test_is_less_16);
  tcase_add_test(tcase_comp, test_is_less_17);
  tcase_add_test(tcase_comp, test_is_less_or_equal_1);
  tcase_add_test(tcase_comp, test_is_less_or_equal_2);
  tcase_add_test(tcase_comp, test_is_less_or_equal_3);
  tcase_add_test(tcase_comp, test_is_less_or_equal_4);
  tcase_add_test(tcase_comp, test_is_less_or_equal_5);
  tcase_add_test(tcase_comp, test_is_less_or_equal_6);
  tcase_add_test(tcase_comp, test_is_less_or_equal_7);
  tcase_add_test(tcase_comp, test_is_less_or_equal_8);
  tcase_add_test(tcase_comp, test_is_less_or_equal_9);
  tcase_add_test(tcase_comp, test_is_less_or_equal_10);
  tcase_add_test(tcase_comp, test_is_less_or_equal_11);
  tcase_add_test(tcase_comp, test_is_less_or_equal_12);
  tcase_add_test(tcase_comp, test_is_less_or_equal_13);
  tcase_add_test(tcase_comp, test_is_less_or_equal_14);
  tcase_add_test(tcase_comp, test_is_less_or_equal_15);
  tcase_add_test(tcase_comp, test_is_less_or_equal_16);
  tcase_add_test(tcase_comp, test_is_less_or_equal_17);
  tcase_add_test(tcase_comp, test_is_not_equal_1);
  tcase_add_test(tcase_comp, test_is_not_equal_2);
  tcase_add_test(tcase_comp, test_is_not_equal_3);
  tcase_add_test(tcase_comp, test_is_not_equal_4);
  tcase_add_test(tcase_comp, test_is_not_equal_5);
  tcase_add_test(tcase_comp, test_is_not_equal_6);
  tcase_add_test(tcase_comp, test_is_not_equal_7);
  tcase_add_test(tcase_comp, test_is_not_equal_8);
  tcase_add_test(tcase_comp, test_is_not_equal_9);
  tcase_add_test(tcase_comp, test_is_not_equal_10);
  tcase_add_test(tcase_comp, test_is_not_equal_11);
  tcase_add_test(tcase_comp, test_is_not_equal_12);
  tcase_add_test(tcase_comp, test_is_not_equal_13);
  tcase_add_test(tcase_comp, test_is_not_equal_14);
  tcase_add_test(tcase_comp, test_is_not_equal_15);

  suite_add_tcase(s, tcase_comp);
  return s;
}

void test_is_equal(s21_decimal decimal1, s21_decimal decimal2, int check) {
  numb_test_is_equal++;
  printf("-----------TEST_IS_EQUAL_%d------------\n", numb_test_is_equal);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_is_equal(decimal1, decimal2);
  if (code == check)
    printf("%sTEST_SUCCESS%s\n", GREEN, RESET);
  else
    printf("%sTEST_FAILED%s\n", RED, RESET);
  print_match_decimal(decimal1, decimal2);
  printf("Check  %d\n", check);
  printf("Result %d\n", code);
  ck_assert_int_eq(code, check);
}
void test_is_greater(s21_decimal decimal1, s21_decimal decimal2, int check) {
  numb_test_is_greater++;
  printf("-----------TEST_IS_GREATER_%d------------\n", numb_test_is_greater);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_is_greater(decimal1, decimal2);
  if (code == check)
    printf("%sTEST_SUCCESS%s\n", GREEN, RESET);
  else
    printf("%sTEST_FAILED%s\n", RED, RESET);
  print_match_decimal(decimal1, decimal2);
  printf("Check  %d\n", check);
  printf("Result %d\n", code);
  ck_assert_int_eq(code, check);
}
void test_is_greater_or_equal(s21_decimal decimal1, s21_decimal decimal2,
                              int check) {
  numb_test_is_greater_or_equal++;
  printf("-----------TEST_IS_GREATER_OR_EQUAL_%d------------\n",
         numb_test_is_greater_or_equal);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_is_greater_or_equal(decimal1, decimal2);
  if (code == check)
    printf("%sTEST_SUCCESS%s\n", GREEN, RESET);
  else
    printf("%sTEST_FAILED%s\n", RED, RESET);
  print_match_decimal(decimal1, decimal2);
  printf("Check  %d\n", check);
  printf("Result %d\n", code);
  ck_assert_int_eq(code, check);
}
void test_is_less(s21_decimal decimal1, s21_decimal decimal2, int check) {
  numb_test_is_less++;
  printf("-----------TEST_IS_LESS_%d------------\n", numb_test_is_less);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_is_less(decimal1, decimal2);
  if (code == check)
    printf("%sTEST_SUCCESS%s\n", GREEN, RESET);
  else
    printf("%sTEST_FAILED%s\n", RED, RESET);
  print_match_decimal(decimal1, decimal2);
  printf("Check  %d\n", check);
  printf("Result %d\n", code);
  ck_assert_int_eq(code, check);
}
void test_is_less_or_equal(s21_decimal decimal1, s21_decimal decimal2,
                           int check) {
  numb_test_is_less_or_equal++;
  printf("-----------TEST_IS_LESS_OR_EQUAL_%d------------\n",
         numb_test_is_less_or_equal);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_is_less_or_equal(decimal1, decimal2);
  if (code == check)
    printf("%sTEST_SUCCESS%s\n", GREEN, RESET);
  else
    printf("%sTEST_FAILED%s\n", RED, RESET);
  print_match_decimal(decimal1, decimal2);
  printf("Check  %d\n", check);
  printf("Result %d\n", code);
  ck_assert_int_eq(code, check);
}
void test_is_not_equal(s21_decimal decimal1, s21_decimal decimal2, int check) {
  numb_test_is_not_equal++;
  printf("-----------TEST_IS_IS_NOT_EQUAL_%d------------\n",
         numb_test_is_not_equal);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_is_not_equal(decimal1, decimal2);
  if (code == check)
    printf("%sTEST_SUCCESS%s\n", GREEN, RESET);
  else
    printf("%sTEST_FAILED%s\n", RED, RESET);
  print_match_decimal(decimal1, decimal2);
  printf("Check  %d\n", check);
  printf("Result %d\n", code);
  ck_assert_int_eq(code, check);
}