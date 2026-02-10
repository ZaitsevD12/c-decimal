#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_code = 0;
  if (s21_is_correct(value_1) && s21_is_correct(value_2) && !(result == NULL)) {
    s21_clear_decimal(result);
    // 79228162514264337593543950335.5
    s21_big_decimal max = {
        {0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x9, 0x0, 0x0, 0x00010000}};

    s21_big_decimal big_value_1;
    s21_big_decimal big_value_2;
    s21_big_decimal big_result;

    decimal_to_big_decimal(value_1, &big_value_1);
    decimal_to_big_decimal(value_2, &big_value_2);
    decimal_to_big_decimal(*result, &big_result);

    int pow = s21_get_pow(big_value_1) + s21_get_pow(big_value_2);
    s21_bit_mul(big_value_1, big_value_2, &big_result);
    if (s21_get_sign(big_value_1) != s21_get_sign(big_value_2)) {
      s21_set_sign(&big_result);
    }
    s21_set_pow(&big_result, pow);

    big_decimal_to_decimal(big_result, result);

    if (result->bits[0] == 0 && result->bits[1] == 0 && result->bits[2] == 0) {
      if (!s21_is_zero(big_value_1) && !s21_is_zero(big_value_2)) {
        error_code = 2;
      }
      if (is_greater(big_result, max) || is_equal(big_result, max)) {
        error_code = 1;
      }
    } else {
      big_trunc(big_result, &big_result);
      if (is_overflow(big_result)) {
        if (!s21_get_sign(big_result)) {
          error_code = 1;
        } else
          error_code = 2;
      }
    }
  } else
    error_code = 1;
  return error_code;
}