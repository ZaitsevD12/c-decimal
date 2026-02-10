#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (s21_is_correct(value) && !(result == NULL)) {
    s21_big_decimal big_value;
    decimal_to_big_decimal(value, &big_value);
    s21_set_sign(&big_value);
    big_decimal_to_decimal(big_value, result);
  } else
    error = 1;

  return error;
}