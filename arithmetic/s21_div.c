#include <math.h>

#include "../s21_decimal.h"

int div_logic(s21_big_decimal *big_value_1, s21_big_decimal tmp,
              s21_big_decimal *big_result);
int round_division(s21_big_decimal tmp, s21_big_decimal big_value_2,
                   s21_big_decimal *big_result);
int get_error_code(s21_big_decimal big_result, s21_decimal value_1,
                   s21_decimal *result, int mod_scale);
int get_error_code_before_round(s21_big_decimal big_result);
void del_extra_zeros(s21_big_decimal value, s21_big_decimal *result);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_code = 0;
  if (s21_is_correct(value_1) && s21_is_correct(value_2) && !(result == NULL)) {
    s21_clear_decimal(result);

    s21_big_decimal big_value_1;
    s21_big_decimal big_value_2;
    s21_big_decimal big_result;

    decimal_to_big_decimal(value_1, &big_value_1);
    decimal_to_big_decimal(value_2, &big_value_2);
    decimal_to_big_decimal(*result, &big_result);

    int pow_1 = s21_get_pow(big_value_1);
    int pow_2 = s21_get_pow(big_value_2);
    int sign_1 = s21_get_sign(big_value_1);
    int sign_2 = s21_get_sign(big_value_2);
    int mod_scale = 0;

    if (s21_is_zero(big_value_2))
      error_code = 3;
    else {
      int scale = div_logic(&big_value_1, big_value_2, &big_result);

      if (!s21_is_zero(big_value_1)) {
        scale = 0;

        s21_big_decimal tmp;
        s21_clear_big_decimal(&tmp);
        tmp = big_value_1;
        s21_clear_big_decimal(&big_value_1);

        while (!s21_is_zero(tmp) && ((pow_1 - pow_2 + scale) < 28)) {
          s21_clear_big_decimal(&big_value_1);
          s21_normalize_mantis(&tmp, 1);
          scale++;
          div_logic(&tmp, big_value_2, &big_value_1);
          s21_normalize_mantis(&big_result, 1);
          s21_bit_add(big_result, big_value_1, &big_result);
        }

        int pow_res = pow_1 - pow_2 + scale;
        if (pow_res >= 0) {
          s21_set_pow(&big_result, pow_1 - pow_2 + scale);
        } else {
          s21_normalize_mantis(&big_result, abs(pow_res));
        }
        if (get_error_code_before_round(big_result) == 0) {
          mod_scale = round_division(tmp, big_value_2, &big_result);
          if (pow_res >= 0)
            s21_set_pow(&big_result, pow_1 - pow_2 + scale - mod_scale);
          del_extra_zeros(big_result, &big_result);
        }
      } else {
        if (pow_1 < pow_2)
          s21_normalize_mantis(&big_result, abs(pow_1 - pow_2));
        if (pow_1 > pow_2)
          s21_set_pow(&big_result, pow_1 - pow_2);
        else
          s21_set_pow(&big_result, 0);
      }

      if (sign_1 != sign_2) s21_set_sign(&big_result);

      for (int i = 0; i < 3; i++) {
        result->bits[i] = big_result.bits[i];
      }
      result->bits[3] = big_result.bits[6];

      error_code = get_error_code(big_result, value_1, result, mod_scale);
    }
  } else
    error_code = 1;
  return error_code;
}

int round_division(s21_big_decimal tmp, s21_big_decimal big_value_2,
                   s21_big_decimal *big_result) {
  s21_big_decimal ten = {{0x0000000A, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal one = {{0x1, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal ostatok = {{0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal dump = {{0, 0, 0, 0, 0, 0, 0}};
  int ost_dumb = 0;
  int scale = 0;
  int count_zeros = 0;

  int pow_input = s21_get_pow(*big_result);
  int step = 0;
  while (is_overflow(*big_result) || ((pow_input - step) > 28)) {
    ostatok.bits[0] = div_ost(*big_result, ten, big_result);
    step++;
  }
  ost_dumb = div_ost(*big_result, ten, &dump);
  if (step < 1) {
    s21_clear_big_decimal(&ostatok);
    s21_normalize_mantis(&tmp, 1);
    div_logic(&tmp, big_value_2, &ostatok);
    scale++;
    if (!s21_is_zero(tmp)) {
      count_zeros++;
    }
  } else if (!s21_is_zero(tmp)) {
    count_zeros++;
  }

  if (ostatok.bits[0] >= 5 && ostatok.bits[0] <= 9) {
    if (ostatok.bits[0] == 5 && count_zeros == 0) {
      if (ost_dumb % 2 || (scale == 0 && step != 1)) {
        s21_bit_add(*big_result, one, big_result);
      }
    } else {
      s21_bit_add(*big_result, one, big_result);
    }
  }

  return step;
}

int get_error_code(s21_big_decimal big_result, s21_decimal value_1,
                   s21_decimal *result, int mod_scale) {
  // 79228162514264337593543950335.5
  s21_big_decimal max = {
      {0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x9, 0x0, 0x0, 0x00010000}};
  s21_big_decimal min = {
      {0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x9, 0x0, 0x0, 0x80010000}};
  s21_decimal null = {{0x0, 0x0, 0x0, 0x0}};
  int error_code = 0;
  if (is_greater(big_result, max) || is_equal(big_result, max)) {
    error_code = 1;
  } else if (is_less(big_result, min) || is_equal(big_result, min)) {
    error_code = 2;
  }
  if (s21_is_zero(big_result) && !s21_is_equal(value_1, null)) {
    error_code = 2;
    s21_set_pow(&big_result, 0);
    big_decimal_to_decimal(big_result, result);
  } else if (mod_scale > 28) {
    if (s21_get_sign(big_result))
      error_code = 2;
    else
      error_code = 1;
  }
  return error_code;
}
int get_error_code_before_round(s21_big_decimal big_result) {
  // 79228162514264337593543950335.5
  s21_big_decimal max = {
      {0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x9, 0x0, 0x0, 0x00010000}};
  int error_code = 0;
  if (is_greater(big_result, max) || is_equal(big_result, max)) {
    error_code = 1;
  }
  return error_code;
}

int div_logic(s21_big_decimal *big_value_1, s21_big_decimal big_value_2,
              s21_big_decimal *big_result) {
  s21_big_decimal tmp;
  int scale = 0;
  int flag = 0;
  while (s21_is_greater_or_equal_mantisa(*big_value_1, big_value_2) && !flag) {
    s21_big_decimal two = {{0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}};
    tmp = big_value_2;
    scale = 0;

    while (s21_is_greater_mantisa(*big_value_1, tmp)) {
      s21_bit_shift_left(&tmp, 1);
      scale++;
    }
    if (scale > 0) {
      scale--;
      s21_bit_shift_right(&tmp, 1);
    }
    if (scale == 0) {
      s21_bit_shift_right(&two, 1);
      flag = 1;
    } else {
      s21_bit_shift_left(&two, scale - 1);
    }
    s21_bit_add(*big_result, two, big_result);

    s21_sub_mantisa(*big_value_1, tmp, big_value_1);
  }

  return scale;
}

void del_extra_zeros(s21_big_decimal value, s21_big_decimal *result) {
  s21_big_decimal ten = {{0x0000000A, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal tmp = value;
  int pow = s21_get_pow(value);
  int new_pow = pow - 1;
  int i = 0;
  while (div_ost(tmp, ten, &tmp) == 0 && i < pow) {
    div_ost(value, ten, &value);
    s21_set_pow(&value, new_pow);
    new_pow--;
    i++;
  }
  *result = value;
}