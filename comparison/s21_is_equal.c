#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = 1;
  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;

  decimal_to_big_decimal(value_1, &big_value_1);
  decimal_to_big_decimal(value_2, &big_value_2);

  res = is_equal(big_value_1, big_value_2);

  return res;
}

int is_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
  int res = 1;

  if (s21_get_sign(value_1) != s21_get_sign(value_2))
    res = 0;
  else if (res) {
    s21_normalize(&value_1, &value_2);
    for (int i = 0; i < 192 && (res); i++) {
      if (s21_get_bit(value_1, i) != s21_get_bit(value_2, i)) res = 0;
    }
  }
  if (s21_is_zero(value_1) && s21_is_zero(value_2)) res = 1;
  return res;
}

int s21_is_zero(s21_big_decimal value) {
  int res = 1;
  if (value.bits[0] != 0 || value.bits[1] != 0 || value.bits[2] != 0 ||
      value.bits[3] != 0 || value.bits[4] != 0 || value.bits[5] != 0)
    res = 0;
  return res;
}