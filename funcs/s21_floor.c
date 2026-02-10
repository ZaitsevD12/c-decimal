#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (s21_is_correct(value) && !(result == NULL)) {
    s21_decimal tmp = {{0, 0, 0, 0}};
    s21_big_decimal big_value = {{0, 0, 0, 0, 0, 0, 0}};
    decimal_to_big_decimal(value, &big_value);
    s21_truncate(value, &tmp);
    if (s21_get_sign(big_value)) {
      if (!s21_is_equal(value, tmp)) {
        s21_big_decimal one = {{0x1, 0, 0, 0, 0, 0, 0}};
        s21_big_decimal big_tmp = {{0, 0, 0, 0, 0, 0, 0}};
        decimal_to_big_decimal(tmp, &big_tmp);
        s21_bit_add(big_tmp, one, &big_tmp);
        big_decimal_to_decimal(big_tmp, &tmp);
      }
    }
    *result = tmp;
  } else
    error = 1;
  return error;
}