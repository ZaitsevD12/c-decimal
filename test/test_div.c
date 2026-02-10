#include "../s21_decimal.h"
#include "test.h"

int numb_test_div = 0;

START_TEST(test_div_1) {
  // 15
  s21_decimal decimal1 = {{0x0000000F, 0x0, 0x0, 0x0}};
  // 5
  s21_decimal decimal2 = {{0x00000005, 0x0, 0x0, 0x0}};
  // 3
  s21_decimal check = {{0x00000003, 0x0, 0x0, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_div_2) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_3) {
  // 50
  s21_decimal decimal1 = {{0x00000032, 0x0, 0x0, 0x0}};
  // 10
  s21_decimal decimal2 = {{0x0000000A, 0x0, 0x0, 0x0}};
  // 5
  s21_decimal check = {{0x00000005, 0x0, 0x0, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_4) {
  // 405
  s21_decimal decimal1 = {{0x00000195, 0x0, 0x0, 0x0}};
  // 15
  s21_decimal decimal2 = {{0x0000000F, 0x0, 0x0, 0x0}};
  // 27
  s21_decimal check = {{0x0000001B, 0x0, 0x0, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_5) {
  // 4228224
  s21_decimal decimal1 = {{0x00408480, 0x0, 0x0, 0x0}};
  // 154
  s21_decimal decimal2 = {{0x0000009A, 0x0, 0x0, 0x0}};
  // 27456
  s21_decimal check = {{0x00006B40, 0x0, 0x0, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_6) {
  // 21000000
  s21_decimal decimal1 = {{0x01406F40, 0x0, 0x0, 0x0}};
  // 1000000
  s21_decimal decimal2 = {{0x000F4240, 0x0, 0x0, 0x0}};
  // 21
  s21_decimal check = {{0x00000015, 0x0, 0x0, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_7) {
  // 121932631112635269
  s21_decimal decimal1 = {{0xFBFF5385, 0x01B13114, 0x0, 0x0}};
  // 987654321
  s21_decimal decimal2 = {{0x3ADE68B1, 0x0, 0x0, 0x0}};
  // 123456789
  s21_decimal check = {{0x075BCD15, 0x0, 0x0, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_8) {
  // 4294967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x00000001, 0x0, 0x0, 0x0}};
  // 4294967295
  s21_decimal check = {{0xFFFFFFFF, 0x00000000, 0x0, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_9) {
  // 8537488744360755
  s21_decimal decimal1 = {{0xFFE1AB33, 0x001E54CC, 0x0, 0x0}};
  // 1987789
  s21_decimal decimal2 = {{0x001E54CD, 0x0, 0x0, 0x0}};
  // 4294967295
  s21_decimal check = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_10) {
  // 39921580540119617025
  s21_decimal decimal1 = {{0xD5FA0E01, 0x2A05F1FC, 0x00000002, 0x0}};
  // 9294967295
  s21_decimal decimal2 = {{0x2A05F1FF, 0x00000002, 0x0, 0x0}};
  // 4294967295
  s21_decimal check = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_11) {
  // 2268949521066274848645
  s21_decimal decimal1 = {{0xFFFFFF85, 0xFFFFFFFF, 0x0000007A, 0x0}};
  // 123
  s21_decimal decimal2 = {{0x0000007B, 0x0, 0x0, 0x0}};
  // 18446744073709551615
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_12) {
  // 1.2640938749860586450804312205
  s21_decimal decimal1 = {{0x1888888D, 0xBE250261, 0x28D856E6, 0x1C0000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 0.6320469374930293225402156102
  s21_decimal check = {{0x8C444446, 0x5F128130, 0x146C2B73, 0x1C0000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_13) {
  // 2
  s21_decimal decimal1 = {{0x2, 0x0, 0x0, 0x0}};
  // 1.2640938749860586450804312205
  s21_decimal decimal2 = {{0x1888888D, 0xBE250261, 0x28D856E6, 0x1C0000}};
  // 1.5821609767882606564463392905
  s21_decimal check = {{0x8B80B889, 0x20B8279E, 0x331F5430, 0x1C0000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_14) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 12.640938749860586450805
  s21_decimal decimal2 = {{0x2EB3EF75, 0x4444026F, 0x2AD, 0x150000}};
  // 113255494.17884722765619814067
  s21_decimal check = {{0x6D7C5EB3, 0x2C521AF0, 0x24984660, 0x140000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_15) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 500
  s21_decimal decimal2 = {{0x1F4, 0x0, 0x0, 0x0}};
  // 0.002
  s21_decimal check = {{0x2, 0x0, 0x0, 0x30000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_16) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal check = {{0x1, 0x0, 0x0, 0x1C0000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -3
  s21_decimal check = {{0x3, 0x0, 0x0, 0x80000000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_18) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 156064767525876035022225408
  s21_decimal decimal2 = {{0x0, 0x0, 0x811800, 0x0}};
  // -169.22068909868474138626644073
  s21_decimal check = {{0x8C085869, 0xC05E68BD, 0x36AD9B79, 0x801A0000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_19) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -429496729.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80010000}};
  // 61489146926681729710
  s21_decimal check = {{0xAAAAAAAE, 0x55555558, 0x3, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_20) {
  // 1.2640938749860586450804312207
  s21_decimal decimal1 = {{0x1888888F, 0xBE250261, 0x28D856E6, 0x1C0000}};
  // 2.0000000000000000000000000000
  s21_decimal decimal2 = {{0x20000000, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 0.6320469374930293225402156104
  s21_decimal check = {{0x8C444448, 0x5F128130, 0x146C2B73, 0x1C0000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_21) {
  // 3.6336660283201536
  s21_decimal decimal1 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 36336660283201536000000000000
  s21_decimal check = {{0x89800000, 0xFEE8FB1C, 0x7568FB1C, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_22) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = 3;
  test_div_fail(decimal1, decimal2, code_check);
}
END_TEST
START_TEST(test_div_23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = 1;
  test_div_fail(decimal1, decimal2, code_check);
}
END_TEST
START_TEST(test_div_24) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = 2;
  test_div_fail(decimal1, decimal2, code_check);
}
END_TEST
START_TEST(test_div_25) {
  // 0.0000000074505801528346182749
  s21_decimal decimal1 = {{0xCAD4845D, 0x9F9C7BD, 0x4, 0x1C0000}};
  // 1152921504606846976
  s21_decimal decimal2 = {{0x0, 0x10000000, 0x0, 0x0}};
  // 0.0000000000000000000000000065
  s21_decimal check = {{0x41, 0x0, 0x0, 0x1C0000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_26) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};
  int code_check = 2;

  test_div_fail2(decimal1, decimal2, decimal_check, code_check);
}
END_TEST
START_TEST(test_div_27) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};
  int code_check = 2;

  test_div_fail2(decimal1, decimal2, decimal_check, code_check);
}
END_TEST
START_TEST(test_div_28) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -1152921504606846976
  s21_decimal decimal2 = {{0x0, 0x10000000, 0x0, 0x80000000}};
  // -0
  s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_29) {
  // -987.4423
  s21_decimal decimal1 = {{0x0096ABF7, 0x0, 0x0, 0x80040000}};
  // -115292150460.6846976
  s21_decimal decimal2 = {{0x0, 0x10000000, 0x0, 0x80070000}};
  // 0.0000000085646966949126657198
  s21_decimal check = {{0xC450D4AE, 0xA49726A9, 0x00000004, 0x001C0000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_30) {
  // 1
  s21_decimal decimal1 = {{0x00000001, 0x0, 0x0, 0x0}};
  // 3
  s21_decimal decimal2 = {{0x00000003, 0x0, 0x0, 0x0}};
  // 0.3333333333333333333333333333
  s21_decimal check = {{0x05555555, 0x14B700CB, 0x0AC544CA, 0x001C0000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_31) {
  // 4
  s21_decimal decimal1 = {{0x00000004, 0x0, 0x0, 0x0}};
  // 3
  s21_decimal decimal2 = {{0x00000003, 0x0, 0x0, 0x0}};
  // 1.3333333333333333333333333333
  s21_decimal check = {{0x15555555, 0x52DC032C, 0x2B151328, 0x001C0000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_32) {
  // 4
  s21_decimal decimal1 = {{0x00000004, 0x0, 0x0, 0x0}};
  // 10
  s21_decimal decimal2 = {{0x0000000A, 0x0, 0x0, 0x0}};
  // 0.4
  s21_decimal check = {{0x00000004, 0x0, 0x0, 0x00010000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_33) {
  // 43
  s21_decimal decimal1 = {{0x0000002B, 0x0, 0x0, 0x0}};
  // 10
  s21_decimal decimal2 = {{0x0000000A, 0x0, 0x0, 0x0}};
  // 4.3
  s21_decimal check = {{0x0000002B, 0x0, 0x0, 0x00010000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_34) {
  // 10.0
  s21_decimal decimal1 = {{0x00000064, 0x0, 0x0, 0x00010000}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // 1.0
  s21_decimal check = {{0x0000000A, 0x0, 0x0, 0x00010000}};
  test_div(decimal1, decimal2, check);
}
END_TEST
START_TEST(test_div_35) {
  // 100
  s21_decimal decimal1 = {{0x00000064, 0x0, 0x0, 0x0}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // 10
  s21_decimal check = {{0x0000000A, 0x0, 0x0, 0x0}};
  test_div(decimal1, decimal2, check);
}
END_TEST

START_TEST(test_div_36) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = 1;

  test_div_fail(decimal1, decimal2, code_check);
}
END_TEST
START_TEST(test_div_37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950327
  s21_decimal decimal_check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_38) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_39) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 79149013500763574019524425909
  s21_decimal decimal_check = {{0xFBE878B5, 0x6170458F, 0xFFBE878B, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_40) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950326
  s21_decimal decimal_check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_41) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 79149013500763574019524425908
  s21_decimal decimal_check = {{0xFBE878B4, 0x6170458F, 0xFFBE878B, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_42) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.6666666666666666666666666667
  s21_decimal decimal_check = {{0xAAAAAAB, 0x296E0196, 0x158A8994, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_43) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // 922337203685477580850000000
  s21_decimal decimal_check = {{0x2FAF080, 0x0, 0x2FAF080, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_44) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 0.5000000001164153218269348145
  s21_decimal decimal_check = {{0xA7128131, 0x2F3A685F, 0x1027E72F, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_45) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_46) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_47) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_48) {
  // 79228162495817593524129366015
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162495817593524129366007
  s21_decimal decimal_check = {{0xFFFFFFF7, 0x0, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_49) {
  // 79228162495817593524129366015
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162495817593524129366023
  s21_decimal decimal_check = {{0x7, 0x1, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_50) {
  // 79228162495817593524129366015
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 79149013482335258265863502512
  s21_decimal decimal_check = {{0x9A36BAB0, 0x61B1BE05, 0xFFBE878A, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_51) {
  // 2147483648
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 0.4999999998835846782001702399
  s21_decimal decimal_check = {{0x791565FF, 0xEEA9A01, 0x1027E72F, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_52) {
  // 2147483648
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 0.0000542101086116534472168365
  s21_decimal decimal_check = {{0x87B453AD, 0x5BD7F056, 0x72CB, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_53) {
  // 2147483648
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // 50000000
  s21_decimal decimal_check = {{0x2FAF080, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_54) {
  // 5
  s21_decimal decimal1 = {{0x5, 0x0, 0x0, 0x0}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 1.2621774483536188886587657045
  s21_decimal decimal_check = {{0xEBFDCB55, 0xC89A2571, 0x28C87CB5, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_55) {
  // 1.0000000000000000000000000001
  s21_decimal decimal1 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_56) {
  // 60.000000000000000000000000005
  s21_decimal decimal1 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 30.000000000000000000000001503
  s21_decimal decimal_check = {{0x300005DF, 0xBA6F0723, 0x60EF6B1A, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_57) {
  // 42.94967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // 42.953968346834683468346834683
  s21_decimal decimal_check = {{0xA1DC3EFB, 0xECF351CD, 0x8ACAB099, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_58) {
  // 0.9999
  s21_decimal decimal1 = {{0x270F, 0x0, 0x0, 0x40000}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // 52.626315789473684210526315789
  s21_decimal decimal_check = {{0x4835E50D, 0x7159F0E6, 0xAA0B77D7, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_59) {
  // 8.000
  s21_decimal decimal1 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 0.0000000018626451492309570312
  s21_decimal decimal_check = {{0xF1281308, 0x27E72F1, 0x1, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_60) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // 614891469123651720533333333.33
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0xC6AEA155, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_61) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // 122978293824730344106666.66667
  s21_decimal decimal_check = {{0xAAAAAAAB, 0xAAAAAAAA, 0x27BC86AA, 0x50000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST
START_TEST(test_div_62) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // 614891469123651720533333333.33
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0xC6AEA155, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}
END_TEST

Suite *suite_div(void) {
  Suite *s = suite_create("Check");

  TCase *tcase_add = tcase_create("test_div_tc");

  tcase_add_test(tcase_add, test_div_1);
  tcase_add_test(tcase_add, test_div_2);
  tcase_add_test(tcase_add, test_div_3);
  tcase_add_test(tcase_add, test_div_4);
  tcase_add_test(tcase_add, test_div_5);
  tcase_add_test(tcase_add, test_div_6);
  tcase_add_test(tcase_add, test_div_7);
  tcase_add_test(tcase_add, test_div_8);
  tcase_add_test(tcase_add, test_div_9);
  tcase_add_test(tcase_add, test_div_10);
  tcase_add_test(tcase_add, test_div_11);
  tcase_add_test(tcase_add, test_div_12);
  tcase_add_test(tcase_add, test_div_13);
  tcase_add_test(tcase_add, test_div_14);
  tcase_add_test(tcase_add, test_div_15);
  tcase_add_test(tcase_add, test_div_16);
  tcase_add_test(tcase_add, test_div_17);
  tcase_add_test(tcase_add, test_div_18);
  tcase_add_test(tcase_add, test_div_19);
  tcase_add_test(tcase_add, test_div_20);
  tcase_add_test(tcase_add, test_div_21);
  tcase_add_test(tcase_add, test_div_22);
  tcase_add_test(tcase_add, test_div_23);
  tcase_add_test(tcase_add, test_div_24);
  tcase_add_test(tcase_add, test_div_25);
  tcase_add_test(tcase_add, test_div_26);
  tcase_add_test(tcase_add, test_div_27);
  tcase_add_test(tcase_add, test_div_28);
  tcase_add_test(tcase_add, test_div_29);
  tcase_add_test(tcase_add, test_div_30);
  tcase_add_test(tcase_add, test_div_31);
  tcase_add_test(tcase_add, test_div_32);
  tcase_add_test(tcase_add, test_div_33);
  tcase_add_test(tcase_add, test_div_34);
  tcase_add_test(tcase_add, test_div_35);
  tcase_add_test(tcase_add, test_div_36);
  tcase_add_test(tcase_add, test_div_37);
  tcase_add_test(tcase_add, test_div_38);
  tcase_add_test(tcase_add, test_div_39);
  tcase_add_test(tcase_add, test_div_40);
  tcase_add_test(tcase_add, test_div_41);
  tcase_add_test(tcase_add, test_div_42);
  tcase_add_test(tcase_add, test_div_43);
  tcase_add_test(tcase_add, test_div_44);
  tcase_add_test(tcase_add, test_div_45);
  tcase_add_test(tcase_add, test_div_46);
  tcase_add_test(tcase_add, test_div_47);
  tcase_add_test(tcase_add, test_div_48);
  tcase_add_test(tcase_add, test_div_49);
  tcase_add_test(tcase_add, test_div_50);
  tcase_add_test(tcase_add, test_div_51);
  tcase_add_test(tcase_add, test_div_52);
  tcase_add_test(tcase_add, test_div_53);
  tcase_add_test(tcase_add, test_div_54);
  tcase_add_test(tcase_add, test_div_55);
  tcase_add_test(tcase_add, test_div_56);
  tcase_add_test(tcase_add, test_div_57);
  tcase_add_test(tcase_add, test_div_58);
  tcase_add_test(tcase_add, test_div_59);
  tcase_add_test(tcase_add, test_div_60);
  tcase_add_test(tcase_add, test_div_61);
  tcase_add_test(tcase_add, test_div_62);

  suite_add_tcase(s, tcase_add);
  return s;
}

void test_div(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  numb_test_div++;
  printf("-----------TEST_DIV_%d------------\n", numb_test_div);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_div(decimal1, decimal2, &result);
  printf("RESULTAT:\n");
  printf("Check:  ");
  print_dec_decimal(check);
  printf("Result: ");
  print_dec_decimal(result);
  print_match_decimal(result, check);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, 0);
}
void test_div_fail(s21_decimal decimal1, s21_decimal decimal2, int check) {
  s21_decimal result;
  numb_test_div++;
  printf("-----------TEST_DIV_%d------------\n", numb_test_div);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_div(decimal1, decimal2, &result);
  printf("RESULTAT:\n");
  printf("Check error code:  %d\n", check);
  printf("Result error code: %d\n", code);
  ck_assert_int_eq(code, check);
}
void test_div_fail2(s21_decimal decimal1, s21_decimal decimal2,
                    s21_decimal decimal_check, int code_check) {
  s21_decimal result;
  numb_test_div++;
  printf("-----------TEST_DIV_%d------------\n", numb_test_div);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal1);
  print_dec_decimal(decimal2);
  int code = s21_div(decimal1, decimal2, &result);
  printf("RESULTAT:\n");
  printf("Check:  ");
  print_dec_decimal(decimal_check);
  printf("Result: ");
  print_dec_decimal(result);
  print_match_decimal(result, decimal_check);
  printf("Check error code:  %d\n", code_check);
  printf("Result error code: %d\n", code);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(code, code_check);
}