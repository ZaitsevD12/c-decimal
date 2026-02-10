#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_code = 0;
  if (s21_is_correct(value_1) && s21_is_correct(value_2) && !(result == NULL)) {
    int flag_for_big = 0;

    s21_big_decimal max = {
        {0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x9, 0x0, 0x0, 0x00010000}};
    s21_big_decimal min = {
        {0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x9, 0x0, 0x0, 0x80010000}};

    s21_clear_decimal(result);

    s21_big_decimal big_value_1;
    s21_big_decimal big_value_2;
    s21_big_decimal big_result;

    decimal_to_big_decimal(value_1, &big_value_1);
    decimal_to_big_decimal(value_2, &big_value_2);
    decimal_to_big_decimal(*result, &big_result);

    if (s21_get_sign(big_value_1) && s21_get_sign(big_value_2)) {
      // Если оба числа отрицательны, вычитаем второе число из первого
      s21_clear_sign(&big_value_1);
      s21_clear_sign(&big_value_2);
      if (is_greater(big_value_1, big_value_2)) {
        error_code = s21_sub_positive(big_value_1, big_value_2, &big_result);
        s21_set_sign(&big_result);
      } else {
        error_code = s21_sub_positive(big_value_2, big_value_1, &big_result);
      }
      flag_for_big = 1;
    } else if (!s21_get_sign(big_value_1) && s21_get_sign(big_value_2)) {
      // Если первое число положительное, а второе отрицательное,
      s21_clear_sign(&big_value_2);
      big_decimal_to_decimal(big_value_2, &value_2);
      error_code = s21_add(value_1, value_2, result);
    } else if (s21_get_sign(big_value_1) && !s21_get_sign(big_value_2)) {
      // Если первое число отрицательное, а второе положительное,
      s21_clear_sign(&big_value_1);
      big_decimal_to_decimal(big_value_1, &value_1);
      error_code = s21_add(value_1, value_2, result);
      decimal_to_big_decimal(*result, &big_result);
      s21_set_sign(&big_result);
      if (error_code == 1) error_code = 2;
      flag_for_big = 1;
    } else {
      // Если оба числа положительны - вычитаем
      if (is_greater(big_value_2, big_value_1)) {
        error_code = s21_sub_positive(big_value_2, big_value_1, &big_result);
        s21_set_sign(&big_result);
      } else {
        error_code = s21_sub_positive(big_value_1, big_value_2, &big_result);
      }
      flag_for_big = 1;
    }
    if (flag_for_big && error_code == 0) {
      if (is_greater(big_result, max) || is_equal(big_result, max)) {
        error_code = 1;
      } else if (is_less(big_result, min) || is_equal(big_result, min)) {
        error_code = 2;
      } else
        big_decimal_to_decimal(big_result, result);
    }

  } else
    error_code = 1;

  return error_code;
}

int s21_sub_positive(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result) {
  int error_code = 0;
  s21_normalize(&value_1, &value_2);

  s21_set_pow(result, s21_get_pow(value_1));
  for (int i = 0; i < 192; i++) {
    s21_set_bit(&value_2, i);
  }
  s21_big_decimal tmp = {{1, 0, 0, 0, 0, 0, 0}};
  s21_bit_add(value_2, tmp, &value_2);
  s21_bit_add(value_1, value_2, result);
  return error_code;
}
