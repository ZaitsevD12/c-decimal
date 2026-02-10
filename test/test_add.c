#include "../s21_decimal.h"
#include "test.h"

int numb_test_add = 0;

START_TEST(test_add_1) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add_2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_3) {
  // 5
  s21_decimal decimal1 = {{0x00000005, 0x0, 0x0, 0x0}};
  // 10
  s21_decimal decimal2 = {{0x0000000A, 0x0, 0x0, 0x0}};
  // 15
  s21_decimal check = {{0x0000000F, 0x0, 0x0, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_4) {
  // 27
  s21_decimal decimal1 = {{0x0000001B, 0x0, 0x0, 0x0}};
  // 15
  s21_decimal decimal2 = {{0x0000000F, 0x0, 0x0, 0x0}};
  // 42
  s21_decimal check = {{0x0000002A, 0x0, 0x0, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_5) {
  // 27456
  s21_decimal decimal1 = {{0x00006B40, 0x0, 0x0, 0x0}};
  // 154
  s21_decimal decimal2 = {{0x0000009A, 0x0, 0x0, 0x0}};
  // 27610
  s21_decimal check = {{0x00006BDA, 0x0, 0x0, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_6) {
  // 21
  s21_decimal decimal1 = {{0x00000015, 0x0, 0x0, 0x0}};
  // 1000000
  s21_decimal decimal2 = {{0x000F4240, 0x0, 0x0, 0x0}};
  // 1000021
  s21_decimal check = {{0x000F4255, 0x0, 0x0, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_7) {
  // 123456789
  s21_decimal decimal1 = {{0x075BCD15, 0x0, 0x0, 0x0}};
  // 987654321
  s21_decimal decimal2 = {{0x3ADE68B1, 0x0, 0x0, 0x0}};
  // 1111111110
  s21_decimal check = {{0x423A35C6, 0x0, 0x0, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_8) {
  // 4294967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x00000001, 0x0, 0x0, 0x0}};
  // 4294967296
  s21_decimal check = {{0x0, 0x00000001, 0x0, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_9) {
  // 4294967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  // 1987789
  s21_decimal decimal2 = {{0x001E54CD, 0x0, 0x0, 0x0}};
  // 4296955084
  s21_decimal check = {{0x001E54CC, 0x00000001, 0x0, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_10) {
  // 4294967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  // 9294967295
  s21_decimal decimal2 = {{0x2A05F1FF, 0x00000002, 0x0, 0x0}};
  // 13589934590
  s21_decimal check = {{0x2A05F1FE, 0x00000003, 0x0, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_11) {
  // 18446744073709551615
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};
  // 18446744073709551615
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};
  // 36893488147419103230
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0x00000001, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_14) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555301
  s21_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_16) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914691236517205
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 79228162508115422902307433130
  s21_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387
  s21_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593517540948
  s21_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_18) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950327
  s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_20) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // +0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x00000000}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_21) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_22) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_23) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_24) {
  // -5948756545
  s21_decimal decimal1 = {{0x6292D241, 0x00000001, 0x0, 0x80000000}};
  // 1034554667875643256
  s21_decimal decimal2 = {{0x37732F78, 0x0E5B79FD, 0x0, 0x0}};
  // 1034554661926886711
  s21_decimal check = {{0xD4E05D37, 0x0E5B79FB, 0x0, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 71305346262837903834189555302
  s21_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_26) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_28) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.4999999999999999999999999999
  s21_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000000000001
  s21_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_30) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 79228162514264337593543950333
  s21_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.704754779197847983445
  s21_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // 79228162514264337593517540947
  s21_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_32) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_33) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_34) {
  // 594875.7623412
  s21_decimal decimal1 = {{0x0D95C274, 0x00000569, 0x0, 0x00070000}};
  // 1034554667875643256.634236888
  s21_decimal decimal2 = {{0x3F725FD8, 0xEC5CB4FC, 0x0357C378, 0x00090000}};
  // 1034554667876238132.396578088
  s21_decimal check = {{0x8DF25528, 0xEC5ED205, 0x0357C378, 0x00090000}};
  test_add(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_35) {
  // -199.124
  s21_decimal decimal1 = {{0x000309D4, 0x0, 0x0, 0x80030000}};
  // 1.634236888
  s21_decimal decimal2 = {{0x616879D8, 0x0, 0x0, 0x00090000}};
  // -197.489763112
  s21_decimal check = {{0xFB4EA328, 0x0000002D, 0x0, 0x80090000}};
  test_add(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_add_36) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int check = 1;
  test_add_fail(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // overflow
  int check = 1;
  test_add_fail(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_add_38) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // overflow
  int check = 2;
  test_add_fail(decimal1, decimal2, check);
}
END_TEST
Suite *suite_add(void) {
  Suite *s = suite_create("Check");

  TCase *tcase_add = tcase_create("test_add_tc");

  tcase_add_test(tcase_add, test_add_1);
  tcase_add_test(tcase_add, test_add_2);
  tcase_add_test(tcase_add, test_add_3);
  tcase_add_test(tcase_add, test_add_4);
  tcase_add_test(tcase_add, test_add_5);
  tcase_add_test(tcase_add, test_add_6);
  tcase_add_test(tcase_add, test_add_7);
  tcase_add_test(tcase_add, test_add_8);
  tcase_add_test(tcase_add, test_add_9);
  tcase_add_test(tcase_add, test_add_10);
  tcase_add_test(tcase_add, test_add_11);
  tcase_add_test(tcase_add, test_add_12);
  tcase_add_test(tcase_add, test_add_13);
  tcase_add_test(tcase_add, test_add_14);
  tcase_add_test(tcase_add, test_add_15);
  tcase_add_test(tcase_add, test_add_16);
  tcase_add_test(tcase_add, test_add_17);
  tcase_add_test(tcase_add, test_add_18);
  tcase_add_test(tcase_add, test_add_19);
  tcase_add_test(tcase_add, test_add_20);
  tcase_add_test(tcase_add, test_add_21);
  tcase_add_test(tcase_add, test_add_22);
  tcase_add_test(tcase_add, test_add_23);
  tcase_add_test(tcase_add, test_add_24);
  tcase_add_test(tcase_add, test_add_25);
  tcase_add_test(tcase_add, test_add_26);
  tcase_add_test(tcase_add, test_add_27);
  tcase_add_test(tcase_add, test_add_28);
  tcase_add_test(tcase_add, test_add_29);
  tcase_add_test(tcase_add, test_add_30);
  tcase_add_test(tcase_add, test_add_31);
  tcase_add_test(tcase_add, test_add_32);
  tcase_add_test(tcase_add, test_add_33);
  tcase_add_test(tcase_add, test_add_34);
  tcase_add_test(tcase_add, test_add_35);
  tcase_add_test(tcase_add, test_add_36);
  tcase_add_test(tcase_add, test_add_37);
  tcase_add_test(tcase_add, test_add_38);

  suite_add_tcase(s, tcase_add);
  return s;
}

void test_add_fail(s21_decimal decimal1, s21_decimal decimal2, int check) {
  s21_decimal result;
  numb_test_add++;
  printf("-----------TEST_ADD_%d------------\n", numb_test_add);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_add(decimal1, decimal2, &result);
  printf("RESULTAT:\n");
  printf("Check error code:  %d\n", check);
  printf("Result error code: %d\n", code);
  ck_assert_int_eq(code, check);
}
void test_add(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  numb_test_add++;
  printf("-----------TEST_ADD_%d------------\n", numb_test_add);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_add(decimal1, decimal2, &result);
  printf("RESULTAT:\n");
  printf("Check:  ");
  print_dec_decimal(check);
  printf("Result: ");
  print_dec_decimal(result);
  print_match_decimal(result, check);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, 0);
}