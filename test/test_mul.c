#include "../s21_decimal.h"
#include "test.h"

int numb_test_mul = 0;

START_TEST(test_mul_1) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 792281625142643.37593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 1584563250285286.7518708789275
  s21_decimal check = {{0x3333301B, 0x33333333, 0x33333333, 0xD0000}};
  test_mul(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_mul_2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_3) {
  // 5
  s21_decimal decimal1 = {{0x00000005, 0x0, 0x0, 0x0}};
  // 10
  s21_decimal decimal2 = {{0x0000000A, 0x0, 0x0, 0x0}};
  // 50
  s21_decimal check = {{0x00000032, 0x0, 0x0, 0x0}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_4) {
  // 27
  s21_decimal decimal1 = {{0x0000001B, 0x0, 0x0, 0x0}};
  // 15
  s21_decimal decimal2 = {{0x0000000F, 0x0, 0x0, 0x0}};
  // 405
  s21_decimal check = {{0x00000195, 0x0, 0x0, 0x0}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_5) {
  // 27456
  s21_decimal decimal1 = {{0x00006B40, 0x0, 0x0, 0x0}};
  // 154
  s21_decimal decimal2 = {{0x0000009A, 0x0, 0x0, 0x0}};
  // 4228224
  s21_decimal check = {{0x00408480, 0x0, 0x0, 0x0}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_6) {
  // 21
  s21_decimal decimal1 = {{0x00000015, 0x0, 0x0, 0x0}};
  // 1000000
  s21_decimal decimal2 = {{0x000F4240, 0x0, 0x0, 0x0}};
  // 21000000
  s21_decimal check = {{0x01406F40, 0x0, 0x0, 0x0}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_7) {
  // 123456789
  s21_decimal decimal1 = {{0x075BCD15, 0x0, 0x0, 0x0}};
  // 987654321
  s21_decimal decimal2 = {{0x3ADE68B1, 0x0, 0x0, 0x0}};
  // 121932631112635269
  s21_decimal check = {{0xFBFF5385, 0x01B13114, 0x0, 0x0}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_8) {
  // 4294967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x00000001, 0x0, 0x0, 0x0}};
  // 4294967295
  s21_decimal check = {{0xFFFFFFFF, 0x00000000, 0x0, 0x0}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_9) {
  // 4294967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  // 1987789
  s21_decimal decimal2 = {{0x001E54CD, 0x0, 0x0, 0x0}};
  // 8537488744360755
  s21_decimal check = {{0xFFE1AB33, 0x001E54CC, 0x0, 0x0}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_10) {
  // 4294967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  // 9294967295
  s21_decimal decimal2 = {{0x2A05F1FF, 0x00000002, 0x0, 0x0}};
  // 39921580540119617025
  s21_decimal check = {{0xD5FA0E01, 0x2A05F1FC, 0x00000002, 0x0}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_11) {
  // 18446744073709551615
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};
  // 123
  s21_decimal decimal2 = {{0x0000007B, 0x0, 0x0, 0x0}};
  // 2268949521066274848645
  s21_decimal check = {{0xFFFFFF85, 0xFFFFFFFF, 0x0000007A, 0x0}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_12) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7.8228162514264337593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0x1C0000}};
  // 61.978735728724164262422454727
  s21_decimal check = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x1B0000}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_13) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -0.8228162514264337593543950335
  s21_decimal decimal2 = {{0xA7FFFFFF, 0xAD2C6F1B, 0x1A962D2F, 0x801C0000}};
  // -6.5190219687391279469416894926
  s21_decimal check = {{0xC4BB51CE, 0x7E6CB6D2, 0xD2A415FA, 0x801C0000}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_14) {
  // -7.000000000000025
  s21_decimal decimal1 = {{0x816D8019, 0x18DE76, 0x0, 0x800F0000}};
  // -0.00000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x800E0000}};
  // 0.0000000000003500000000000012
  s21_decimal check = {{0x40B6C00C, 0xC6F3B, 0x0, 0x1C0000}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_15) {
  // -7922816251426.4337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // 78228162514264.337593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0xF0000}};
  // -619787357287241642624224547.27
  s21_decimal check = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x80020000}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_16) {
  // -79228162514264.337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // 782281625142643.37593543950335
  s21_decimal decimal2 = {{0x17FFFFFF, 0x602F7FC3, 0xFCC4D1C3, 0xE0000}};
  // -61978735728724164262422454727
  s21_decimal check = {{0xE07921C7, 0x3FD7ABE1, 0xC8439BCC, 0x80000000}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_17) {
  // 5.0
  s21_decimal decimal1 = {{0x32, 0x0, 0x0, 0x10000}};
  // 4.5
  s21_decimal decimal2 = {{0x2D, 0x0, 0x0, 0x10000}};
  // 22.50
  s21_decimal check = {{0x8CA, 0x0, 0x0, 0x20000}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_18) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 0.00000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x50000}};
  // 0.0000000000000000000000000000
  s21_decimal check = {{0x0, 0x0, 0x0, 0x1C0000}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_19) {
  // -7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 0.00000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x00050000}};
  // -0.0000000000000000000000000000
  s21_decimal check = {{0x0, 0x0, 0x0, 0x801C0000}};
  test_mul(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_mul_20) {
  // 7922816251426433759354395032.8
  s21_decimal decimal1 = {{0xFFFFFFF8, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 10.000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1B0000}};
  // overflow
  int code_check = 1;
  test_mul_fail(decimal1, decimal2, code_check);
}
END_TEST
START_TEST(test_mul_21) {
  // 7922816251426433759354395032.8
  s21_decimal decimal1 = {{0xFFFFFFF8, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -10.000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801B0000}};
  // overflow
  int code_check = 2;
  test_mul_fail(decimal1, decimal2, code_check);
}
END_TEST
START_TEST(test_mul_22) {
  // -7922816251426433759354395032.7
  s21_decimal decimal1 = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -10.000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_mul_23) {
  // -0.0000000000000025
  s21_decimal decimal1 = {{0x19, 0x0, 0x0, 0x80100000}};
  // -0.0000000000000005
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80100000}};
  // too small
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};
  int code_check = 2;
  test_mul_fail2(decimal1, decimal2, decimal_check, code_check);
}
END_TEST
START_TEST(test_mul_24) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -75
  s21_decimal decimal2 = {{0x0000004B, 0x0, 0x0, 0x80000000}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};
  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_mul_25) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};
  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_mul_26) {
  // 0.5
  s21_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};
  int code_check = 2;
  test_mul_fail2(decimal1, decimal2, decimal_check, code_check);
}
END_TEST
START_TEST(test_mul_27) {
  // 0.5
  s21_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x801C0000}};
  int code_check = 2;

  test_mul_fail2(decimal1, decimal2, decimal_check, code_check);
}
END_TEST
START_TEST(test_mul_28) {
  // 0.0000000000000005
  s21_decimal decimal1 = {{0x5, 0x0, 0x0, 0x100000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -0.0000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80100000}};
  test_mul(decimal1, decimal2, decimal_check);
}
END_TEST

Suite *suite_mul(void) {
  Suite *s = suite_create("Check");

  TCase *tcase_add = tcase_create("test_mul_tc");

  tcase_add_test(tcase_add, test_mul_1);
  tcase_add_test(tcase_add, test_mul_2);
  tcase_add_test(tcase_add, test_mul_3);
  tcase_add_test(tcase_add, test_mul_4);
  tcase_add_test(tcase_add, test_mul_5);
  tcase_add_test(tcase_add, test_mul_6);
  tcase_add_test(tcase_add, test_mul_7);
  tcase_add_test(tcase_add, test_mul_8);
  tcase_add_test(tcase_add, test_mul_9);
  tcase_add_test(tcase_add, test_mul_10);
  tcase_add_test(tcase_add, test_mul_11);
  tcase_add_test(tcase_add, test_mul_12);
  tcase_add_test(tcase_add, test_mul_13);
  tcase_add_test(tcase_add, test_mul_14);
  tcase_add_test(tcase_add, test_mul_15);
  tcase_add_test(tcase_add, test_mul_16);
  tcase_add_test(tcase_add, test_mul_17);
  tcase_add_test(tcase_add, test_mul_18);
  tcase_add_test(tcase_add, test_mul_19);
  tcase_add_test(tcase_add, test_mul_20);
  tcase_add_test(tcase_add, test_mul_21);
  tcase_add_test(tcase_add, test_mul_22);
  tcase_add_test(tcase_add, test_mul_23);
  tcase_add_test(tcase_add, test_mul_24);
  tcase_add_test(tcase_add, test_mul_25);
  tcase_add_test(tcase_add, test_mul_26);
  tcase_add_test(tcase_add, test_mul_27);
  tcase_add_test(tcase_add, test_mul_28);

  suite_add_tcase(s, tcase_add);
  return s;
}

void test_mul(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  numb_test_mul++;
  printf("-----------TEST_MUL_%d------------\n", numb_test_mul);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_mul(decimal1, decimal2, &result);
  printf("RESULTAT:\n");
  printf("Check:  ");
  print_dec_decimal(check);
  printf("Result: ");
  print_dec_decimal(result);
  print_match_decimal(result, check);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
}
void test_mul_fail(s21_decimal decimal1, s21_decimal decimal2, int check) {
  s21_decimal result;
  numb_test_mul++;
  printf("-----------TEST_MUL_%d------------\n", numb_test_mul);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_mul(decimal1, decimal2, &result);
  printf("RESULTAT:\n");
  printf("Check error code:  %d\n", check);
  printf("Result error code: %d\n", code);
  ck_assert_int_eq(code, check);
}
void test_mul_fail2(s21_decimal decimal1, s21_decimal decimal2,
                    s21_decimal decimal_check, int code_check) {
  s21_decimal result;
  numb_test_mul++;
  printf("-----------TEST_MUL_%d------------\n", numb_test_mul);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_mul(decimal1, decimal2, &result);
  printf("RESULTAT:\n");
  printf("Check:  ");
  print_dec_decimal(decimal_check);
  printf("Result: ");
  print_dec_decimal(result);
  print_match_decimal(result, decimal_check);
  printf("Check error code:  %d\n", code_check);
  printf("Result error code: %d\n", code);
  ck_assert_int_eq(code, code_check);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}