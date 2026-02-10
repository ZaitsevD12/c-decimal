#include "../s21_decimal.h"
#include "test.h"

int numb_test_from_decimal_to_float = 0;
int numb_test_from_decimal_to_int = 0;
int numb_test_from_float_to_decimal = 0;
int numb_test_from_int_to_decimal = 0;

START_TEST(test_from_decimal_to_int_1) {
  // 1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};
  int check = 1;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_2) {
  // -1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = -1;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_3) {
  // 5
  s21_decimal decimal = {{0x5, 0x0, 0x0, 0x0}};
  int check = 5;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_4) {
  // 10
  s21_decimal decimal = {{0xA, 0x0, 0x0, 0x0}};
  int check = 10;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_5) {
  // 15
  s21_decimal decimal = {{0xF, 0x0, 0x0, 0x0}};
  int check = 15;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_6) {
  // -5
  s21_decimal decimal = {{0x5, 0x0, 0x0, 0x80000000}};
  int check = -5;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_7) {
  // -10
  s21_decimal decimal = {{0xA, 0x0, 0x0, 0x80000000}};
  int check = -10;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_8) {
  // -15
  s21_decimal decimal = {{0xF, 0x0, 0x0, 0x80000000}};
  int check = -15;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_9) {
  // 1802612012
  s21_decimal decimal = {{0x6B71AD2C, 0x0, 0x0, 0x0}};
  int check = 1802612012;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_10) {
  // -1802612012
  s21_decimal decimal = {{0x6B71AD2C, 0x0, 0x0, 0x80000000}};
  int check = -1802612012;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_11) {
  // 1498496264
  s21_decimal decimal = {{0x59513D08, 0x0, 0x0, 0x0}};
  int check = 1498496264;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_12) {
  // -1498496264
  s21_decimal decimal = {{0x59513D08, 0x0, 0x0, 0x80000000}};
  int check = -1498496264;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_13) {
  // 2147483647
  s21_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
  int check = 2147483647;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_14) {
  // -2147483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};
  int check = -2147483648;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_15) {
  // 0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};
  int check = 0;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_16) {
  // -0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};
  int check = 0;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_17) {
  // 21474836.48
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};
  int check = 21474836;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_18) {
  // -21474836.48
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80020000}};
  int check = -21474836;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_19) {
  // 214.7483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x70000}};
  int check = 214;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_20) {
  // -214.7483648
  s21_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80070000}};
  int check = -214;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_21) {
  // 2147483647.765
  s21_decimal decimal = {{0xFFFFFF15, 0x000001F3, 0x0, 0x00030000}};
  int check = 2147483647;
  test_from_decimal_to_int(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_int_22) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  test_from_decimal_to_int_fail(decimal);
}
END_TEST
START_TEST(test_from_decimal_to_int_23) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  test_from_decimal_to_int_fail(decimal);
}
END_TEST
START_TEST(test_from_decimal_to_int_24) {
  // 1844674407370955161.6
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x10000}};
  test_from_decimal_to_int_fail(decimal);
}
END_TEST
START_TEST(test_from_decimal_to_int_25) {
  // -1844674407370955161.6
  s21_decimal decimal = {{0x0, 0x0, 0x1, 0x80010000}};
  test_from_decimal_to_int_fail(decimal);
}
END_TEST
START_TEST(test_from_decimal_to_int_26) {
  // 4294967295
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  test_from_decimal_to_int_fail(decimal);
}
END_TEST

START_TEST(test_from_int_to_decimal_1) {
  int number = -2147483648;
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80000000}};
  test_from_int_to_decimal(number, decimal_check);
}
END_TEST
START_TEST(test_from_int_to_decimal_2) {
  int number = -2147483647;
  s21_decimal decimal_check = {{0x7FFFFFFF, 0x0, 0x0, 0x80000000}};
  test_from_int_to_decimal(number, decimal_check);
}
END_TEST
START_TEST(test_from_int_to_decimal_3) {
  int number = -214748364;
  s21_decimal decimal_check = {{0xCCCCCCC, 0x0, 0x0, 0x80000000}};
  test_from_int_to_decimal(number, decimal_check);
}
END_TEST
START_TEST(test_from_int_to_decimal_4) {
  int number = -214748;
  s21_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x80000000}};
  test_from_int_to_decimal(number, decimal_check);
}
END_TEST
START_TEST(test_from_int_to_decimal_5) {
  int number = -1000;
  s21_decimal decimal_check = {{0x3E8, 0x0, 0x0, 0x80000000}};
  test_from_int_to_decimal(number, decimal_check);
}
END_TEST
START_TEST(test_from_int_to_decimal_6) {
  int number = -1;
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};
  test_from_int_to_decimal(number, decimal_check);
}
END_TEST
START_TEST(test_from_int_to_decimal_7) {
  int number = 0;
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};
  test_from_int_to_decimal(number, decimal_check);
}
END_TEST
START_TEST(test_from_int_to_decimal_8) {
  int number = 1;
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};
  test_from_int_to_decimal(number, decimal_check);
}
END_TEST
START_TEST(test_from_int_to_decimal_9) {
  int number = 1000;
  s21_decimal decimal_check = {{0x3E8, 0x0, 0x0, 0x0}};
  test_from_int_to_decimal(number, decimal_check);
}
END_TEST
START_TEST(test_from_int_to_decimal_10) {
  int number = 214748;
  s21_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x0}};
  test_from_int_to_decimal(number, decimal_check);
}
END_TEST
START_TEST(test_from_int_to_decimal_11) {
  int number = 214748364;
  s21_decimal decimal_check = {{0xCCCCCCC, 0x0, 0x0, 0x0}};
  test_from_int_to_decimal(number, decimal_check);
}
END_TEST
START_TEST(test_from_int_to_decimal_12) {
  int number = 2147483646;
  s21_decimal decimal_check = {{0x7FFFFFFE, 0x0, 0x0, 0x0}};
  test_from_int_to_decimal(number, decimal_check);
}
END_TEST
START_TEST(test_from_int_to_decimal_13) {
  int number = 2147483647;
  s21_decimal decimal_check = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
  test_from_int_to_decimal(number, decimal_check);
}
END_TEST

START_TEST(test_from_decimal_to_float_1) {
  // 0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};
  int check = 1036831949;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_2) {
  // -0.1
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};
  int check = -1110651699;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_3) {
  // 0.265
  s21_decimal decimal = {{0x109, 0x0, 0x0, 0x30000}};
  int check = 1049079316;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_4) {
  // -0.265
  s21_decimal decimal = {{0x109, 0x0, 0x0, 0x80030000}};
  int check = -1098404332;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_5) {
  // 0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0xD0000}};
  int check = 702623251;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_6) {
  // -0.0000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x800D0000}};
  int check = -1444860397;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_7) {
  // 0.000000000000265
  s21_decimal decimal = {{0x109, 0x0, 0x0, 0xF0000}};
  int check = 714419846;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_8) {
  // -0.000000000000265
  s21_decimal decimal = {{0x109, 0x0, 0x0, 0x800F0000}};
  int check = -1433063802;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_9) {
  // 4.294967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x90000}};
  int check = 1082749023;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_10) {
  // -4.294967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80090000}};
  int check = -1064734625;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_11) {
  // 11.38166333440
  s21_decimal decimal = {{0x0, 0x109, 0x0, 0xB0000}};
  int check = 1094064971;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_12) {
  // -11.38166333440
  s21_decimal decimal = {{0x0, 0x109, 0x0, 0x800B0000}};
  int check = -1053418677;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_13) {
  // 42.94967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80000}};
  int check = 1110166647;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_14) {
  // -42.94967296
  s21_decimal decimal = {{0x0, 0x1, 0x0, 0x80080000}};
  int check = -1037317001;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_15) {
  // 347340.779296875
  s21_decimal decimal = {{0x93C4186B, 0x13BE7, 0x0, 0x90000}};
  int check = 1219074457;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_16) {
  // -347340.779296875
  s21_decimal decimal = {{0x93C4186B, 0x13BE7, 0x0, 0x80090000}};
  int check = -928409191;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_17) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_18) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_19) {
  // 0.000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x1B0000}};
  int check = 312374482;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_20) {
  // -0.000000000000000000000000001
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x801B0000}};
  int check = -1835109166;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_21) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  int check = 1842138317;

  test_from_decimal_to_float(decimal, check);
}
END_TEST
START_TEST(test_from_decimal_to_float_22) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  int check = -305345331;

  test_from_decimal_to_float(decimal, check);
}
END_TEST

/*START_TEST(test_from_float_to_decimal_1) {
    // 178,125
    int f = 1127358464;
    // 178,125
    s21_decimal decimal_check = {{0x0002B7CD, 0x0, 0x0, 0x00030000}};

    test_from_float_to_decimal(f, decimal_check);
}
END_TEST*/

START_TEST(test_from_float_to_decimal_1) {
  // 3.08618259
  int f = 1078297604;
  // 3.086183
  s21_decimal decimal_check = {{0x2F1767, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_2) {
  // -3.08618259
  int f = -1069186044;
  // -3.086183
  s21_decimal decimal_check = {{0x2F1767, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_3) {
  // 146891104
  int f = 1292637718;
  // 146891100
  s21_decimal decimal_check = {{0x8C1615C, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_4) {
  // -146891104
  int f = -854845930;
  // -146891100
  s21_decimal decimal_check = {{0x8C1615C, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_5) {
  // 530444320
  int f = 1308422017;
  // 530444300
  s21_decimal decimal_check = {{0x1F9DF00C, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_6) {
  // -530444320
  int f = -839061631;
  // -530444300
  s21_decimal decimal_check = {{0x1F9DF00C, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_7) {
  // 15725.3545
  int f = 1182119275;
  // 15725.35
  s21_decimal decimal_check = {{0x17FEB7, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_8) {
  // -15725.3545
  int f = -965364373;
  // -15725.35
  s21_decimal decimal_check = {{0x17FEB7, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_9) {
  // 1.33397293
  int f = 1068154784;
  // 1.333973
  s21_decimal decimal_check = {{0x145AD5, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_10) {
  // -1.33397293
  int f = -1079328864;
  // -1.333973
  s21_decimal decimal_check = {{0x145AD5, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_11) {
  // 165025.641
  int f = 1210132585;
  // 165025.6
  s21_decimal decimal_check = {{0x192E50, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_12) {
  // -165025.641
  int f = -937351063;
  // -165025.6
  s21_decimal decimal_check = {{0x192E50, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_13) {
  // 3807398.25
  int f = 1248354969;
  // 3807398
  s21_decimal decimal_check = {{0x3A18A6, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_14) {
  // -3807398.25
  int f = -899128679;
  // -3807398
  s21_decimal decimal_check = {{0x3A18A6, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_15) {
  // 807.082397
  int f = 1145685318;
  // 807.0824
  s21_decimal decimal_check = {{0x7B26A8, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_16) {
  // -807.082397
  int f = -1001798330;
  // -807.0824
  s21_decimal decimal_check = {{0x7B26A8, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_17) {
  // 7.77944088
  int f = 1090056494;
  // 7.779441
  s21_decimal decimal_check = {{0x76B471, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_18) {
  // -7.77944088
  int f = -1057427154;
  // -7.779441
  s21_decimal decimal_check = {{0x76B471, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_19) {
  // 3.93075884E+12
  int f = 1415892191;
  // 3930759000000
  s21_decimal decimal_check = {{0x337E6FC0, 0x393, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_20) {
  // -3.93075884E+12
  int f = -731591457;
  // -3930759000000
  s21_decimal decimal_check = {{0x337E6FC0, 0x393, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_21) {
  // 7.42264215E-19
  int f = 559616998;
  // 0.0000000000000000007422642
  s21_decimal decimal_check = {{0x7142B2, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_22) {
  // -7.42264215E-19
  int f = -1587866650;
  // -0.0000000000000000007422642
  s21_decimal decimal_check = {{0x7142B2, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_23) {
  // 1.06286686E-19
  int f = 536540764;
  // 0.0000000000000000001062867
  s21_decimal decimal_check = {{0x1037D3, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_24) {
  // -1.06286686E-19
  int f = -1610942884;
  // -0.0000000000000000001062867
  s21_decimal decimal_check = {{0x1037D3, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_25) {
  // 3.94556822E+15
  int f = 1499482003;
  // 3945568000000000
  s21_decimal decimal_check = {{0x2313C000, 0xE0479, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_26) {
  // -3.94556822E+15
  int f = -648001645;
  // -3945568000000000
  s21_decimal decimal_check = {{0x2313C000, 0xE0479, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_27) {
  // 4.9575518E-22
  int f = 471192883;
  // 0.0000000000000000000004957552
  s21_decimal decimal_check = {{0x4BA570, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_28) {
  // -4.9575518E-22
  int f = -1676290765;
  // -0.0000000000000000000004957552
  s21_decimal decimal_check = {{0x4BA570, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_29) {
  // 3.45355434E-20
  int f = 522393321;
  // 0.00000000000000000003453554
  s21_decimal decimal_check = {{0x34B272, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_30) {
  // -3.45355434E-20
  int f = -1625090327;
  // -0.00000000000000000003453554
  s21_decimal decimal_check = {{0x34B272, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

START_TEST(test_from_float_to_decimal_31) {
  // 8.66900895E-23
  int f = 449944209;
  // 0.0000000000000000000000866901
  s21_decimal decimal_check = {{0xD3A55, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_32) {
  // 1.9929916E-26
  int f = 348479575;
  // 0.0000000000000000000000000199
  s21_decimal decimal_check = {{0xC7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_33) {
  // 12419649
  int f = 1262322241;
  // 12419650
  s21_decimal decimal_check = {{0xBD8242, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_34) {
  // 56497.5
  int f = 1197257088;
  // 56497.5
  s21_decimal decimal_check = {{0x89EEF, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_35) {
  // 1.5
  int f = 1069547520;
  // 1.5
  s21_decimal decimal_check = {{0xF, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_36) {
  // 0.15625
  int f = 1042284544;
  // 0.15625
  s21_decimal decimal_check = {{0x3D09, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST
START_TEST(test_from_float_to_decimal_37) {
  // 0.75
  int f = 1061158912;
  // 0.75
  s21_decimal decimal_check = {{0x4B, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}
END_TEST

Suite *suite_pars(void) {
  Suite *s = suite_create("test_parsers");

  TCase *tcase_pars = tcase_create("test_parsers_tc");

  tcase_add_test(tcase_pars, test_from_decimal_to_int_1);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_2);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_3);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_4);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_5);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_6);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_7);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_8);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_9);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_10);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_11);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_12);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_13);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_14);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_15);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_16);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_17);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_18);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_19);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_20);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_21);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_22);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_23);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_24);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_25);
  tcase_add_test(tcase_pars, test_from_decimal_to_int_26);
  tcase_add_test(tcase_pars, test_from_int_to_decimal_1);
  tcase_add_test(tcase_pars, test_from_int_to_decimal_2);
  tcase_add_test(tcase_pars, test_from_int_to_decimal_3);
  tcase_add_test(tcase_pars, test_from_int_to_decimal_4);
  tcase_add_test(tcase_pars, test_from_int_to_decimal_5);
  tcase_add_test(tcase_pars, test_from_int_to_decimal_6);
  tcase_add_test(tcase_pars, test_from_int_to_decimal_7);
  tcase_add_test(tcase_pars, test_from_int_to_decimal_8);
  tcase_add_test(tcase_pars, test_from_int_to_decimal_9);
  tcase_add_test(tcase_pars, test_from_int_to_decimal_10);
  tcase_add_test(tcase_pars, test_from_int_to_decimal_11);
  tcase_add_test(tcase_pars, test_from_int_to_decimal_12);
  tcase_add_test(tcase_pars, test_from_int_to_decimal_13);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_1);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_2);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_3);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_4);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_5);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_6);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_7);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_8);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_9);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_10);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_11);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_12);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_13);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_14);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_15);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_16);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_17);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_18);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_19);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_20);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_21);
  tcase_add_test(tcase_pars, test_from_decimal_to_float_22);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_1);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_2);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_3);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_4);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_5);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_6);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_7);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_8);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_9);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_10);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_11);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_12);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_13);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_14);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_15);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_16);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_17);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_18);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_19);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_20);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_21);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_22);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_23);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_24);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_25);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_26);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_27);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_28);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_29);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_30);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_31);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_32);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_33);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_34);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_35);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_36);
  tcase_add_test(tcase_pars, test_from_float_to_decimal_37);

  suite_add_tcase(s, tcase_pars);
  return s;
}

void test_from_decimal_to_int(s21_decimal decimal, int check) {
  numb_test_from_decimal_to_int++;
  printf("-----------TEST_FROM_DECIMAL_TO_INT_%d------------\n",
         numb_test_from_decimal_to_int);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal);
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  if (result == check)
    printf("%sTEST_SUCCESS%s\n", GREEN, RESET);
  else
    printf("%sTEST_FAILED%s\n", RED, RESET);
  printf("Check  %d\n", check);
  printf("Result %d\n", result);
  printf("Check error code  %d\n", 0);
  printf("Result error code %d\n", code);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

void test_from_decimal_to_int_fail(s21_decimal decimal) {
  numb_test_from_decimal_to_int++;
  printf("-----------TEST_FROM_DECIMAL_TO_INT_%d------------\n",
         numb_test_from_decimal_to_int);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal);
  int result = 0;
  int code = s21_from_decimal_to_int(decimal, &result);
  if (code == 1)
    printf("%sTEST_SUCCESS%s\n", GREEN, RESET);
  else
    printf("%sTEST_FAILED%s\n", RED, RESET);
  printf("Check error code  %d\n", 1);
  printf("Result error code %d\n", code);
  printf("Result int %d\n", result);
  ck_assert_int_eq(code, 1);
}

void test_from_int_to_decimal(int number, s21_decimal decimal_check) {
  numb_test_from_int_to_decimal++;
  printf("-----------TEST_FROM_INT_TO_DECIMAL_%d------------\n",
         numb_test_from_int_to_decimal);
  printf("INPUT_DATA:\n");
  printf("INT: %d\n", number);
  s21_decimal result;
  int code = s21_from_int_to_decimal(number, &result);
  printf("RESULTAT:\n");
  printf("Check:  ");
  print_dec_decimal(decimal_check);
  printf("Result: ");
  print_dec_decimal(result);
  print_match_decimal(result, decimal_check);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
void test_from_decimal_to_float(s21_decimal decimal, int check) {
  numb_test_from_decimal_to_float++;
  float result;
  printf("-----------TEST_FROM_DECIMAL_TO_FLOAT_%d------------\n",
         numb_test_from_decimal_to_float);
  printf("INPUT_DATA:\n");
  print_dec_decimal(decimal);
  print_bin_decimal(decimal);
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  float_cast_test cast_check;
  cast_check.int32_bytes = check;
  printf("RESULTAT:\n");
  printf("Check:  ");
  printf("%.80f\n", cast_check.f);
  printf("Result: ");
  printf("%.80f\n", cast_result.f);

  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}
void test_from_float_to_decimal(int f, s21_decimal decimal_check) {
  numb_test_from_float_to_decimal++;
  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  printf("-----------TEST_FROM_FLOAT_TO_DECIMAL_%d------------\n",
         numb_test_from_float_to_decimal);
  printf("INPUT_DATA:\n");
  printf("Float:   %.100f\n", cast_float.f);
  print_float_bin(cast_float.f);
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  printf("RESULTAT:\n");
  printf("Check:  ");
  print_dec_decimal(decimal_check);
  printf("Result: ");
  print_dec_decimal(result);
  print_match_decimal(result, decimal_check);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}