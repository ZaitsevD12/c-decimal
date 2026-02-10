#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_code = 0;
  if (s21_is_correct(value_1) && s21_is_correct(value_2) && !(result == NULL)) {
    int flag_for_big = 0;
    s21_clear_decimal(result);
    // 79228162514264337593543950335.5
    s21_big_decimal max = {
        {0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x9, 0x0, 0x0, 0x00010000}};
    s21_big_decimal min = {
        {0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x9, 0x0, 0x0, 0x80010000}};

    s21_big_decimal big_value_1;
    s21_big_decimal big_value_2;
    s21_big_decimal big_result;

    decimal_to_big_decimal(value_1, &big_value_1);
    decimal_to_big_decimal(value_2, &big_value_2);
    decimal_to_big_decimal(*result, &big_result);

    if (s21_get_sign(big_value_1) && s21_get_sign(big_value_2)) {
      // Если оба числа отрицательны, складываем
      s21_clear_sign(&big_value_1);
      s21_clear_sign(&big_value_2);
      error_code = s21_add_positive(big_value_1, big_value_2, &big_result);
      s21_set_sign(&big_result);
      flag_for_big = 1;
    } else if (!s21_get_sign(big_value_1) && s21_get_sign(big_value_2)) {
      // Если первое число положительное, а второе отрицательное, вычитаем
      s21_clear_sign(&big_value_2);
      big_decimal_to_decimal(big_value_2, &value_2);
      error_code = s21_sub(value_1, value_2, result);
    } else if (s21_get_sign(big_value_1) && !s21_get_sign(big_value_2)) {
      // Если первое число отрицательное, а второе положительное, вычитаем
      s21_clear_sign(&big_value_1);
      big_decimal_to_decimal(big_value_1, &value_1);
      error_code = s21_sub(value_2, value_1, result);
    } else {
      // Если оба числа положительны, просто складываем
      error_code = s21_add_positive(big_value_1, big_value_2, &big_result);
      flag_for_big = 1;
    }

    if (flag_for_big) {
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

int s21_add_positive(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result) {
  int error_code = 0;
  s21_normalize(&value_1, &value_2);

  s21_bit_add(value_1, value_2, result);

  s21_set_pow(result, s21_get_pow(value_2));

  return error_code;
}

void s21_bit_add(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  int bit;
  int in_mind = 0;
  for (int i = 0; i < 192; i++) {
    bit = s21_get_bit(value_1, i) + s21_get_bit(value_2, i) + in_mind;
    if (bit == 2) {
      bit = 0;
      in_mind = 1;
    } else if (bit == 3) {
      bit = 1;
      in_mind = 1;
    } else {
      in_mind = 0;
    }
    if (bit == 1) {
      if (s21_get_bit(*result, i) == 0) s21_set_bit(result, i);
    } else {
      if (s21_get_bit(*result, i) == 1) s21_set_bit(result, i);
    }
  }
}