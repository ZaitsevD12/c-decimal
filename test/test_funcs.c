#include "../s21_decimal.h"
#include "test.h"

int numb_test_truncate = 0;
int numb_test_floor = 0;
int numb_test_round = 0;
int numb_test_negate = 0;

START_TEST(test_truncate_1) {
  // 1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_2) {
  // 10.0
  s21_decimal decimal = {{0x00000064, 0x0, 0x0, 0x00010000}};
  // 10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x0}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_3) {
  // -1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_4) {
  // -10.0
  s21_decimal decimal = {{0x00000064, 0x0, 0x0, 0x80010000}};
  // -10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x80000000}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_5) {
  // 15.5
  s21_decimal decimal = {{0x0000009B, 0x0, 0x0, 0x00010000}};
  // 15
  s21_decimal decimal_check = {{0xF, 0x0, 0x0, 0x0}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_6) {
  // 29.75
  s21_decimal decimal = {{0x00000B9F, 0x0, 0x0, 0x00020000}};
  // 29
  s21_decimal decimal_check = {{0x0000001D, 0x0, 0x0, 0x0}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_7) {
  // 29.01
  s21_decimal decimal = {{0x00000B55, 0x0, 0x0, 0x00020000}};
  // 29
  s21_decimal decimal_check = {{0x0000001D, 0x0, 0x0, 0x0}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_8) {
  // 29.000001
  s21_decimal decimal = {{0x01BA8141, 0x0, 0x0, 0x00060000}};
  // 29
  s21_decimal decimal_check = {{0x0000001D, 0x0, 0x0, 0x0}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_9) {
  // 234.987
  s21_decimal decimal = {{0x000395EB, 0x0, 0x0, 0x00030000}};
  // 234
  s21_decimal decimal_check = {{0x000000EA, 0x0, 0x0, 0x0}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_10) {
  // 0.1
  s21_decimal decimal = {{0x00000001, 0x0, 0x0, 0x00010000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_11) {
  // -0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_12) {
  // 214748364.8
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x10000}};
  // 214748364
  s21_decimal decimal_check = {{0xCCCCCCC, 0x0, 0x0, 0x0}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_13) {
  // 21474836.48
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};
  // 21474836
  s21_decimal decimal_check = {{0x147AE14, 0x0, 0x0, 0x0}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_14) {
  // 214748.3648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x40000}};
  // 214748
  s21_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_15) {
  // 21.47483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000}};
  // 21
  s21_decimal decimal_check = {{0x15, 0x0, 0x0, 0x0}};
  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_16) {
  // 92233720368.54775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000}};
  // 92233720368
  s21_decimal decimal_check = {{0x798EE230, 0x15, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_17) {
  // -92233720368.54775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80080000}};
  // -92233720368
  s21_decimal decimal_check = {{0x798EE230, 0x15, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_18) {
  // 9.223372036854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x120000}};
  // 9
  s21_decimal decimal_check = {{0x9, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_19) {
  // -9.223372036854775808
  s21_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80120000}};
  // -9
  s21_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}
END_TEST
START_TEST(test_truncate_20) {
  // 0.0000
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x40000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}
END_TEST

START_TEST(test_floor_1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_5) {
  // 2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_6) {
  // -2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_7) {
  // 0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_8) {
  // -0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_9) {
  // 0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0xD0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_10) {
  // -0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x800D0000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_11) {
  // 0.9999
  s21_decimal decimal = {{0x270F, 0x0, 0x0, 0x40000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_12) {
  // -0.9999
  s21_decimal decimal = {{0x270F, 0x0, 0x0, 0x80040000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_13) {
  // -0.0
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x80010000}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_14) {
  // 0.0
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x10000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_15) {
  // -0.00
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x80020000}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_16) {
  // 0.00
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x20000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_17) {
  // 2991221486048612559449461.7951
  s21_decimal decimal = {{0x55C3C95F, 0xC794AD09, 0x60A6CDE0, 0x40000}};
  // 2991221486048612559449461
  s21_decimal decimal_check = {{0xDFE16D75, 0x7111CE8E, 0x2796A, 0x0}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_18) {
  // -2991221486048612559449461.7951
  s21_decimal decimal = {{0x55C3C95F, 0xC794AD09, 0x60A6CDE0, 0x80040000}};
  // -2991221486048612559449462
  s21_decimal decimal_check = {{0xDFE16D76, 0x7111CE8E, 0x2796A, 0x80000000}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_19) {
  // -29238170.246572049058153344687
  s21_decimal decimal = {{0xFABAEAF, 0xAAE5571, 0x5E793F61, 0x80150000}};
  // -29238171
  s21_decimal decimal_check = {{0x1BE239B, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}
END_TEST
START_TEST(test_floor_20) {
  // 29238170.246572049058153344687
  s21_decimal decimal = {{0xFABAEAF, 0xAAE5571, 0x5E793F61, 0x150000}};
  // 29238170
  s21_decimal decimal_check = {{0x1BE239A, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}
END_TEST

START_TEST(test_round_1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_5) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_6) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_7) {
  // 52818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};
  // 52818774997211729016086244010
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_8) {
  // -52818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};
  // -52818774997211729016086244010
  s21_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_9) {
  // 5281877499721172901608624401.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};
  // 5281877499721172901608624401
  s21_decimal decimal_check = {{0x11111111, 0x0, 0x11111111, 0x0}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_10) {
  // -5281877499721172901608624401.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80010000}};
  // -5281877499721172901608624401
  s21_decimal decimal_check = {{0x11111111, 0x0, 0x11111111, 0x80000000}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_11) {
  // 5281877499721172.9016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0xD0000}};
  // 5281877499721173
  s21_decimal decimal_check = {{0xF01E35D5, 0x12C3D6, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_12) {
  // -5281877499721172.9016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x800D0000}};
  // -5281877499721173
  s21_decimal decimal_check = {{0xF01E35D5, 0x12C3D6, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_13) {
  // 5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};
  // 5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_14) {
  // -5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
  // -5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_15) {
  // 3.9614081257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_16) {
  // -3.9614081257132168796771975168
  s21_decimal decimal = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -4
  s21_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_17) {
  // 0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_18) {
  // -0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_19) {
  // 0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0xD0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}
END_TEST
START_TEST(test_round_20) {
  // -0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x800D0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}
END_TEST

START_TEST(test_negate_1) {
  // -0
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_2) {
  // 0
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x0}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_3) {
  // -0.0
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x80010000}};
  // 0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_4) {
  // 0.0
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x10000}};
  // -0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_5) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_6) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_7) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_8) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_9) {
  // 0.9999999999999999999999999999
  s21_decimal decimal = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal_check = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_10) {
  // -0.9999999999999999999999999999
  s21_decimal decimal = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal_check = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_11) {
  // 1.0000000000000000000000000001
  s21_decimal decimal = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal_check = {
      {0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_12) {
  // -1.0000000000000000000000000001
  s21_decimal decimal = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal_check = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_13) {
  // 1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_14) {
  // -1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_15) {
  // 0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};
  // -0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_16) {
  // -0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};
  // 0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_17) {
  // 0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0xD0000}};
  // -0.0000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x800D0000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_18) {
  // -0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x800D0000}};
  // 0.0000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0xD0000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_19) {
  // 21.47483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000}};
  // -21.47483648
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}
END_TEST
START_TEST(test_negate_20) {
  // -21.47483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80080000}};
  // 21.47483648
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}
END_TEST

Suite *suite_funcs(void) {
  Suite *s = suite_create("test_funcs");

  TCase *tcase_funcs = tcase_create("test_funcs_tc");

  tcase_add_test(tcase_funcs, test_truncate_1);
  tcase_add_test(tcase_funcs, test_truncate_2);
  tcase_add_test(tcase_funcs, test_truncate_3);
  tcase_add_test(tcase_funcs, test_truncate_4);
  tcase_add_test(tcase_funcs, test_truncate_5);
  tcase_add_test(tcase_funcs, test_truncate_6);
  tcase_add_test(tcase_funcs, test_truncate_7);
  tcase_add_test(tcase_funcs, test_truncate_8);
  tcase_add_test(tcase_funcs, test_truncate_9);
  tcase_add_test(tcase_funcs, test_truncate_10);
  tcase_add_test(tcase_funcs, test_truncate_11);
  tcase_add_test(tcase_funcs, test_truncate_12);
  tcase_add_test(tcase_funcs, test_truncate_13);
  tcase_add_test(tcase_funcs, test_truncate_14);
  tcase_add_test(tcase_funcs, test_truncate_15);
  tcase_add_test(tcase_funcs, test_truncate_16);
  tcase_add_test(tcase_funcs, test_truncate_17);
  tcase_add_test(tcase_funcs, test_truncate_18);
  tcase_add_test(tcase_funcs, test_truncate_19);
  tcase_add_test(tcase_funcs, test_truncate_20);
  tcase_add_test(tcase_funcs, test_floor_1);
  tcase_add_test(tcase_funcs, test_floor_2);
  tcase_add_test(tcase_funcs, test_floor_3);
  tcase_add_test(tcase_funcs, test_floor_4);
  tcase_add_test(tcase_funcs, test_floor_5);
  tcase_add_test(tcase_funcs, test_floor_6);
  tcase_add_test(tcase_funcs, test_floor_7);
  tcase_add_test(tcase_funcs, test_floor_8);
  tcase_add_test(tcase_funcs, test_floor_9);
  tcase_add_test(tcase_funcs, test_floor_10);
  tcase_add_test(tcase_funcs, test_floor_11);
  tcase_add_test(tcase_funcs, test_floor_12);
  tcase_add_test(tcase_funcs, test_floor_13);
  tcase_add_test(tcase_funcs, test_floor_14);
  tcase_add_test(tcase_funcs, test_floor_15);
  tcase_add_test(tcase_funcs, test_floor_16);
  tcase_add_test(tcase_funcs, test_floor_17);
  tcase_add_test(tcase_funcs, test_floor_18);
  tcase_add_test(tcase_funcs, test_floor_19);
  tcase_add_test(tcase_funcs, test_floor_20);
  tcase_add_test(tcase_funcs, test_round_1);
  tcase_add_test(tcase_funcs, test_round_2);
  tcase_add_test(tcase_funcs, test_round_3);
  tcase_add_test(tcase_funcs, test_round_4);
  tcase_add_test(tcase_funcs, test_round_5);
  tcase_add_test(tcase_funcs, test_round_6);
  tcase_add_test(tcase_funcs, test_round_7);
  tcase_add_test(tcase_funcs, test_round_8);
  tcase_add_test(tcase_funcs, test_round_9);
  tcase_add_test(tcase_funcs, test_round_10);
  tcase_add_test(tcase_funcs, test_round_11);
  tcase_add_test(tcase_funcs, test_round_12);
  tcase_add_test(tcase_funcs, test_round_13);
  tcase_add_test(tcase_funcs, test_round_14);
  tcase_add_test(tcase_funcs, test_round_15);
  tcase_add_test(tcase_funcs, test_round_16);
  tcase_add_test(tcase_funcs, test_round_17);
  tcase_add_test(tcase_funcs, test_round_18);
  tcase_add_test(tcase_funcs, test_round_19);
  tcase_add_test(tcase_funcs, test_round_20);
  tcase_add_test(tcase_funcs, test_negate_1);
  tcase_add_test(tcase_funcs, test_negate_2);
  tcase_add_test(tcase_funcs, test_negate_3);
  tcase_add_test(tcase_funcs, test_negate_4);
  tcase_add_test(tcase_funcs, test_negate_5);
  tcase_add_test(tcase_funcs, test_negate_6);
  tcase_add_test(tcase_funcs, test_negate_7);
  tcase_add_test(tcase_funcs, test_negate_8);
  tcase_add_test(tcase_funcs, test_negate_9);
  tcase_add_test(tcase_funcs, test_negate_10);
  tcase_add_test(tcase_funcs, test_negate_11);
  tcase_add_test(tcase_funcs, test_negate_12);
  tcase_add_test(tcase_funcs, test_negate_13);
  tcase_add_test(tcase_funcs, test_negate_14);
  tcase_add_test(tcase_funcs, test_negate_15);
  tcase_add_test(tcase_funcs, test_negate_16);
  tcase_add_test(tcase_funcs, test_negate_17);
  tcase_add_test(tcase_funcs, test_negate_18);
  tcase_add_test(tcase_funcs, test_negate_19);
  tcase_add_test(tcase_funcs, test_negate_20);

  suite_add_tcase(s, tcase_funcs);
  return s;
}

void test_truncate(s21_decimal decimal, s21_decimal decimal_check) {
  numb_test_truncate++;
  s21_decimal result;
  printf("-----------TEST_TRUNCATE_%d------------\n", numb_test_truncate);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal);
  int code = s21_truncate(decimal, &result);
  printf("RESULTAT:\n");
  printf("Check:  ");
  print_dec_decimal(decimal_check);
  printf("Result: ");
  print_dec_decimal(result);
  print_match_decimal(result, decimal_check);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_are_same(result, decimal_check), 1);
}

void test_floor(s21_decimal decimal, s21_decimal decimal_check) {
  numb_test_floor++;
  s21_decimal result;
  printf("-----------TEST_FLOOR_%d------------\n", numb_test_floor);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal);
  int code = s21_floor(decimal, &result);
  printf("RESULTAT:\n");
  printf("Check:  ");
  print_dec_decimal(decimal_check);
  printf("Result: ");
  print_dec_decimal(result);
  print_match_decimal(result, decimal_check);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_are_same(result, decimal_check), 1);
}

void test_round(s21_decimal decimal, s21_decimal decimal_check) {
  numb_test_round++;
  s21_decimal result;
  printf("-----------TEST_ROUND_%d------------\n", numb_test_round);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal);
  int code = s21_round(decimal, &result);
  printf("RESULTAT:\n");
  printf("Check:  ");
  print_dec_decimal(decimal_check);
  printf("Result: ");
  print_dec_decimal(result);
  print_match_decimal(result, decimal_check);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_are_same(result, decimal_check), 1);
}

void test_negate(s21_decimal decimal, s21_decimal decimal_check) {
  numb_test_negate++;
  s21_decimal result;
  printf("-----------TEST_NEGATE_%d------------\n", numb_test_negate);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal);
  int code = s21_negate(decimal, &result);
  printf("RESULTAT:\n");
  printf("Check:  ");
  print_dec_decimal(decimal_check);
  printf("Result: ");
  print_dec_decimal(result);
  print_match_decimal(result, decimal_check);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_are_same(result, decimal_check), 1);
}

int test_are_same(s21_decimal value_1, s21_decimal value_2) {
  int code = 1;
  for (int i = 0; i < 4; i++) {
    if (value_1.bits[i] != value_2.bits[i]) code = 0;
  }
  return code;
}