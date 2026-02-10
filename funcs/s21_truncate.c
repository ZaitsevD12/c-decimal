#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error_code = 0;
  if (s21_is_correct(value) && !(result == NULL)) {
    s21_big_decimal big_value;
    s21_big_decimal big_result;

    decimal_to_big_decimal(value, &big_value);
    decimal_to_big_decimal(*result, &big_result);

    big_trunc(big_value, &big_result);

    big_decimal_to_decimal(big_result, result);
  } else
    error_code = 1;
  return error_code;
}

int big_trunc(s21_big_decimal big_value, s21_big_decimal *big_result) {
  *big_result = big_value;

  s21_big_decimal ten = {{0x0000000A, 0, 0, 0, 0, 0, 0}};
  int pow = s21_get_pow(big_value);
  if (pow) {
    for (int i = 0; i < pow; i++) {
      div_ost(*big_result, ten, big_result);
    }
    if (s21_get_sign(big_value)) {
      s21_set_sign(big_result);
    }
  }
  return 0;
}

int div_ost(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result) {
  if (s21_is_zero(value_2)) return 10;
  s21_clear_big_decimal(result);
  int index_1 = find_index(value_1);
  int index_2 = find_index(value_2);
  if ((index_1 - index_2) > 0) {
    s21_bit_shift_left(&value_2, index_1 - index_2);
  }
  for (int i = index_1 - index_2 + 1; i > 0; i--) {
    if (s21_is_greater_or_equal_mantisa(value_1, value_2)) {
      s21_bit_shift_left(result, 1);
      s21_set_bit(result, 0);
      s21_sub_mantisa(value_1, value_2, &value_1);
    } else {
      s21_bit_shift_left(result, 1);
    }
    s21_bit_shift_right(&value_2, 1);
  }
  return value_1.bits[0];
}
int s21_sub_mantisa(s21_big_decimal value_1, s21_big_decimal value_2,
                    s21_big_decimal *result) {
  int error_code = 0;

  s21_clear_big_decimal(result);
  for (int i = 0; i < 192; i++) {
    s21_set_bit(&value_2, i);
  }
  s21_big_decimal tmp = {{1, 0, 0, 0, 0, 0, 0}};
  s21_bit_add(value_2, tmp, &value_2);
  s21_bit_add(value_1, value_2, result);
  return error_code;
}

int s21_is_greater_or_equal_mantisa(s21_big_decimal value_1,
                                    s21_big_decimal value_2) {
  int res = 0;
  if (s21_is_equal_mantisa(value_1, value_2) ||
      s21_is_greater_mantisa(value_1, value_2))
    res = 1;
  return res;
}
int s21_is_equal_mantisa(s21_big_decimal value_1, s21_big_decimal value_2) {
  int res = 1;
  for (int i = 0; i < 192 && (res); i++) {
    if (s21_get_bit(value_1, i) != s21_get_bit(value_2, i)) res = 0;
  }
  return res;
}
int s21_is_greater_mantisa(s21_big_decimal value_1, s21_big_decimal value_2) {
  int res = 1;
  int flag = 1;
  for (int i = 191; i >= 0 && (res) && (flag); i--) {
    if (s21_get_bit(value_1, i) < s21_get_bit(value_2, i))
      res = 0;
    else if (s21_get_bit(value_1, i) > s21_get_bit(value_2, i))
      flag = 0;
  }
  return res;
}
int find_index(s21_big_decimal decimal) {
  int flag = 0;
  for (int i = 191; i >= 0 && (!flag); i--) {
    if (s21_get_bit(decimal, i) == 1) {
      flag = i;
    }
  }
  return flag;
}
void s21_bit_shift_right(s21_big_decimal *value, int shift) {
  if (shift < 0 || shift >= 192) {
    printf("Overflow\n");
    return;
  }
  for (int i = 0; i <= 191 - shift; i++) {
    if (s21_get_bit(*value, i + shift)) {
      if (s21_get_bit(*value, i) == 0) s21_set_bit(value, i);
    } else {
      s21_clear_exp(value, i);
    }
  }
  for (int i = 191; i > 191 - shift; i--) {
    s21_clear_exp(value, i);
  }
}
