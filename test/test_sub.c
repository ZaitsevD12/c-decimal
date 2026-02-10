#include "../s21_decimal.h"
#include "test.h"

int numb_test_sub = 0;

START_TEST(test_sub_1) {
  // 15
  s21_decimal decimal1 = {{0x0000000F, 0x0, 0x0, 0x0}};
  // 7
  s21_decimal decimal2 = {{0x00000007, 0x0, 0x0, 0x0}};
  // 8
  s21_decimal check = {{0x00000008, 0x0, 0x0, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_sub_2) {
  // 12345
  s21_decimal decimal1 = {{0x00003039, 0x0, 0x0, 0x0}};
  // 2345
  s21_decimal decimal2 = {{0x00000929, 0x0, 0x0, 0x0}};
  // 10000
  s21_decimal check = {{0x00002710, 0x0, 0x0, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_3) {
  // 1
  s21_decimal decimal1 = {{0x00000001, 0x0, 0x0, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x00000001, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_4) {
  // 1
  s21_decimal decimal1 = {{0x00000001, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x00000000, 0x0, 0x0, 0x0}};
  // 1
  s21_decimal check = {{0x00000001, 0x0, 0x0, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_5) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x00000001, 0x0, 0x0}};
  // 678432
  s21_decimal decimal2 = {{0x000A5A20, 0x0, 0x0, 0x0}};
  // 4294288864
  s21_decimal check = {{0xFFF5A5E0, 0x0, 0x0, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_6) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x00000001, 0x0, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x00000001, 0x0, 0x0, 0x0}};
  // 4294967295
  s21_decimal check = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_7) {
  // 18446744073709551616
  s21_decimal decimal1 = {{0x0, 0x0, 0x01, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x01, 0x0, 0x0, 0x0}};
  // 18446744073709551615
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_8) {
  // 98446744073709551616
  s21_decimal decimal1 = {{0x4F400000, 0x56391824, 0x00000005, 0x0}};
  // 98446740407370905510
  s21_decimal decimal2 = {{0xAC6FF7A6, 0x563914CE, 0x05, 0x0}};
  // 3666338646106
  s21_decimal check = {{0xA2D0085A, 0x00000355, 0x0, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_9) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 24856567824430907546909321344
  s21_decimal decimal2 = {{0x76D0A880, 0xCA0017EC, 0x5050DEF9, 0x0}};
  // 14757513432701261249862653824
  s21_decimal check = {{0x892F5780, 0x35FFE813, 0x2FAF2106, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_10) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 24856567824430907546909321344
  s21_decimal decimal2 = {{0x76D0A880, 0xCA0017EC, 0x5050DEF9, 0x0}};
  // 54371594689833430046634628991
  s21_decimal check = {{0x892F577F, 0x35FFE813, 0xAFAF2106, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x01, 0x0, 0x0, 0x0}};
  // 2268949521066274848645
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = 1;
  test_sub_fail(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = 1;
  test_sub_fail(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_14) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int check = 1;
  test_sub_fail(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_16) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_18) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_20) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = 2;
  test_sub_fail(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_21) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // +0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x00000000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_22) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_23) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 7922816251426433759354395033.0
  s21_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_24) {
  // 10
  s21_decimal decimal1 = {{0x0000000A, 0x0, 0x0, 0x0}};
  // 2.8765
  s21_decimal decimal2 = {{0x0000705D, 0x0, 0x0, 0x00040000}};
  // 7.1235
  s21_decimal check = {{0x00011643, 0x0, 0x0, 0x00040000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_25) {
  // 10.7654664
  s21_decimal decimal1 = {{0x066AAE08, 0x0, 0x0, 0x00070000}};
  // 2.8765
  s21_decimal decimal2 = {{0x0000705D, 0x0, 0x0, 0x00040000}};
  // 7.8889664
  s21_decimal check = {{0x04B3C2C0, 0x0, 0x0, 0x00070000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_26) {
  // 10.7654664
  s21_decimal decimal1 = {{0x066AAE08, 0x0, 0x0, 0x00070000}};
  // 234.8765
  s21_decimal decimal2 = {{0x0023D6DD, 0x0, 0x0, 0x00040000}};
  // -224.1110336
  s21_decimal check = {{0x8594A140, 0x0, 0x0, 0x80070000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_27) {
  // -10.7654664
  s21_decimal decimal1 = {{0x066AAE08, 0x0, 0x0, 0x80070000}};
  // 234.8765
  s21_decimal decimal2 = {{0x0023D6DD, 0x0, 0x0, 0x00040000}};
  // -245.6419664
  s21_decimal check = {{0x9269FD50, 0x0, 0x0, 0x80070000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_28) {
  // -10.7654664
  s21_decimal decimal1 = {{0x066AAE08, 0x0, 0x0, 0x80070000}};
  // -234.8765
  s21_decimal decimal2 = {{0x0023D6DD, 0x0, 0x0, 0x80040000}};
  // -245.6419664
  s21_decimal check = {{0x8594A140, 0x0, 0x0, 0x00070000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_29) {
  // 10.7654664
  s21_decimal decimal1 = {{0x066AAE08, 0x0, 0x0, 0x00070000}};
  // 234.876587665543
  s21_decimal decimal2 = {{0x7792E887, 0x0000D59E, 0x0, 0x000C0000}};
  // -224.111121265543
  s21_decimal check = {{0xEFC5F387, 0x0000CBD3, 0x0, 0x800C0000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_30) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 24246937143470783.81744120110
  s21_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000}};
  // 7922816251402186822210924249.2
  s21_decimal check = {{0x2EB8D47C, 0xFCA29364, 0xFFFFFFFF, 0x10000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_31) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -7922816251426433759354395034
  s21_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_32) {
  // 10.7654664
  s21_decimal decimal1 = {{0x066AAE08, 0x0, 0x0, 0x00070000}};
  // 2.7654664
  s21_decimal decimal2 = {{0x01A5FA08, 0x0, 0x0, 0x00070000}};
  // 8.0000000
  s21_decimal check = {{0x04C4B400, 0x0, 0x0, 0x00070000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_33) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 0.5000000000000000000000000001
  s21_decimal check = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_34) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 0.4999999999999999999999999999
  s21_decimal check = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_sub_35) {
  // 1.0000000000000000000000000001
  s21_decimal decimal1 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 0.5000000000000000000000000001
  s21_decimal check = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  test_sub(decimal1, decimal2, check);
}
END_TEST

Suite *suite_sub(void) {
  Suite *s = suite_create("Check");

  TCase *tcase_add = tcase_create("test_sub_tc");

  tcase_add_test(tcase_add, test_sub_1);
  tcase_add_test(tcase_add, test_sub_2);
  tcase_add_test(tcase_add, test_sub_3);
  tcase_add_test(tcase_add, test_sub_4);
  tcase_add_test(tcase_add, test_sub_5);
  tcase_add_test(tcase_add, test_sub_6);
  tcase_add_test(tcase_add, test_sub_7);
  tcase_add_test(tcase_add, test_sub_8);
  tcase_add_test(tcase_add, test_sub_9);
  tcase_add_test(tcase_add, test_sub_10);
  tcase_add_test(tcase_add, test_sub_11);
  tcase_add_test(tcase_add, test_sub_12);
  tcase_add_test(tcase_add, test_sub_13);
  tcase_add_test(tcase_add, test_sub_14);
  tcase_add_test(tcase_add, test_sub_15);
  tcase_add_test(tcase_add, test_sub_16);
  tcase_add_test(tcase_add, test_sub_17);
  tcase_add_test(tcase_add, test_sub_18);
  tcase_add_test(tcase_add, test_sub_19);
  tcase_add_test(tcase_add, test_sub_20);
  tcase_add_test(tcase_add, test_sub_21);
  tcase_add_test(tcase_add, test_sub_22);
  tcase_add_test(tcase_add, test_sub_23);
  tcase_add_test(tcase_add, test_sub_24);
  tcase_add_test(tcase_add, test_sub_25);
  tcase_add_test(tcase_add, test_sub_26);
  tcase_add_test(tcase_add, test_sub_27);
  tcase_add_test(tcase_add, test_sub_28);
  tcase_add_test(tcase_add, test_sub_29);
  tcase_add_test(tcase_add, test_sub_30);
  tcase_add_test(tcase_add, test_sub_31);
  tcase_add_test(tcase_add, test_sub_32);
  tcase_add_test(tcase_add, test_sub_33);
  tcase_add_test(tcase_add, test_sub_34);
  tcase_add_test(tcase_add, test_sub_35);

  suite_add_tcase(s, tcase_add);
  return s;
}

void test_sub(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  numb_test_sub++;
  printf("-----------TEST_SUB_%d------------\n", numb_test_sub);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_sub(decimal1, decimal2, &result);
  printf("RESULTAT:\n");
  printf("Check:  ");
  print_dec_decimal(check);
  printf("Result: ");
  print_dec_decimal(result);
  print_match_decimal(result, check);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, 0);
}
void test_sub_fail(s21_decimal decimal1, s21_decimal decimal2, int check) {
  s21_decimal result;
  numb_test_sub++;
  printf("-----------TEST_SUB_%d------------\n", numb_test_sub);
  int code = s21_sub(decimal1, decimal2, &result);
  printf("RESULTAT:\n");
  printf("Check error code:  %d\n", check);
  printf("Result error code: %d\n", code);
  ck_assert_int_eq(code, check);
}