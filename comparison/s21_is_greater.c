#include "../s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int res = 1;
  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;

  decimal_to_big_decimal(value_1, &big_value_1);
  decimal_to_big_decimal(value_2, &big_value_2);

  res = is_greater(big_value_1, big_value_2);
  return res;
}

int is_greater(s21_big_decimal value_1, s21_big_decimal value_2) {
  int res = 1;
  int flag = 1;
  if (s21_get_sign(value_1) && s21_get_sign(value_2)) {
    s21_set_sign(&value_1);
    s21_set_sign(&value_2);
    res = is_less(value_1, value_2);
  } else if (s21_get_sign(value_1) >= s21_get_sign(value_2)) {
    if (is_equal(value_1, value_2))
      res = 0;
    else if (s21_get_sign(value_1) > s21_get_sign(value_2))
      res = 0;
    else {
      s21_normalize(&value_1, &value_2);

      for (int i = 191; i >= 0 && (res) && (flag); i--) {
        if (s21_get_bit(value_1, i) < s21_get_bit(value_2, i))
          res = 0;
        else if (s21_get_bit(value_1, i) > s21_get_bit(value_2, i)) {
          flag = 0;
        }
      }
    }
  } else if (s21_is_zero(value_1) && s21_is_zero(value_2))
    res = 0;
  return res;
}