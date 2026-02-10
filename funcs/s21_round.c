#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (s21_is_correct(value) && !(result == NULL)) {
    s21_big_decimal big_value;
    s21_big_decimal big_result;

    decimal_to_big_decimal(value, &big_value);
    decimal_to_big_decimal(*result, &big_result);

    big_result = big_value;

    s21_big_decimal ten = {{0x0000000A, 0, 0, 0, 0, 0, 0}};
    s21_big_decimal one = {{0x1, 0, 0, 0, 0, 0, 0}};
    s21_big_decimal tmp = {{0, 0, 0, 0, 0, 0, 0}};
    int ostatok = 0;
    int ost_dumb = 0;
    int count_zeros = 0;
    int pow = s21_get_pow(big_value);
    if (pow) {
      for (int i = 0; i < pow; i++) {
        ostatok = div_ost(big_result, ten, &big_result);
        if (ostatok != 0) {
          count_zeros++;
        }
      }
      ost_dumb = div_ost(big_result, ten, &tmp);
      if (ostatok >= 5 && ostatok <= 9) {
        if (ostatok == 5 && count_zeros == 1) {
          if (ost_dumb % 2) {
            s21_bit_add(big_result, one, &big_result);
          }
        } else {
          s21_bit_add(big_result, one, &big_result);
        }
      }
      if (s21_get_sign(big_value)) {
        s21_set_sign(&big_result);
      }
    }

    big_decimal_to_decimal(big_result, result);
  } else
    error = 1;

  return error;
}