#include <math.h>
#include <stdint.h>
#include <stdio.h>

#include "../s21_decimal.h"

#define s21_MAXDEC_FLOAT pow(2, 96) - 1
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"
#define DEBUG 1

union f {
  float fl;
  uint32_t dw;
};

typedef struct {
  int bits[13];
} s21_13_decimal;

int s21_from_float_to_decimal(float src, s21_decimal *dst);
int print_float_bin(float value);
int float_get_bit(int value, int n);
int float_get_sign(float value);
int float_get_exp(float value);
int print_int_bin(int value);
int float_get_mantissa(float value);
int counts_zeros(float value);
int set_float_mantis(s21_big_decimal *value, int diff);

void s21_bit_mul_13(s21_13_decimal value_1, s21_big_decimal value_2,
                    s21_13_decimal *result);
int big_decimal_to_decimal_13(s21_big_decimal value, s21_13_decimal *result);
int s21_clear_13_decimal(s21_13_decimal *value);
void s21_bit_shift_left_13(s21_13_decimal *value, int shift);
int s21_get_bit_13(s21_13_decimal value, int n);
int s21_set_bit_13(s21_13_decimal *value, int n);
void s21_clear_exp_13(s21_13_decimal *value, int position);
void s21_bit_add_13(s21_13_decimal value_1, s21_13_decimal value_2,
                    s21_13_decimal *result);
int decimal_13_to_big_decimal(s21_13_decimal value, s21_big_decimal *result,
                              int diff);
int div_ten_ost_13(s21_13_decimal value_1, s21_13_decimal *result);
bool is_overflow_13(s21_13_decimal value);
int find_index_13(s21_13_decimal decimal);
int s21_is_greater_or_equal_mantisa_13(s21_13_decimal value_1,
                                       s21_13_decimal value_2);
int s21_is_equal_mantisa_13(s21_13_decimal value_1, s21_13_decimal value_2);
int s21_is_greater_mantisa_13(s21_13_decimal value_1, s21_13_decimal value_2);
int s21_sub_mantisa_13(s21_13_decimal value_1, s21_13_decimal value_2,
                       s21_13_decimal *result);
void s21_bit_shift_right_13(s21_13_decimal *value, int shift);
int count_decimal_places(s21_13_decimal value);
int s21_is_zero_13(s21_13_decimal value);

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error_code = 0;
  if (dst == NULL || (fabs(src) >= s21_MAXDEC_FLOAT) ||
      (fabs(src) == INFINITY) || isnan(fabs(src))) {
    error_code = 1;
  } else if (fabs(src) > 0 && fabs(src) < 1e-28) {
    error_code = 1;
    s21_clear_decimal(dst);
  } else {
    s21_clear_decimal(dst);
    int basis = 0b01111111;
    dst->bits[0] = float_get_mantissa(src);
    int zeros = counts_zeros(src);
    int exp = float_get_exp(src);
    int e = 0;
    e = exp - basis;
    int number_after_point = 23 - e - zeros;
    s21_big_decimal big_dst;
    decimal_to_big_decimal(*dst, &big_dst);
    s21_bit_shift_right(&big_dst, zeros);

    int scale = set_float_mantis(&big_dst, number_after_point);

    if (number_after_point > 0) s21_set_pow(&big_dst, scale);
    if (float_get_sign(src)) s21_set_sign(&big_dst);

    for (int i = 0; i < 3; i++) {
      dst->bits[i] = big_dst.bits[i];
    }
    dst->bits[3] = big_dst.bits[6];
  }
  return error_code;
}

int print_float_bin(float value) {
  union f cast_float;
  cast_float.fl = value;
  for (int i = 31; i >= 0; i--) {
    printf("%d", float_get_bit(cast_float.dw, i));
    if (i == 31 || i == 23) printf(" ");
  }
  printf("\n");
  return 0;
}
int float_get_bit(int value, int n) {
  unsigned int f = 0b00000001;
  unsigned int res;
  res = value & (f << n);
  res = res >> n;
  return res;
}
int float_get_sign(float value) {
  union f cast_float;
  cast_float.fl = value;
  int sign = cast_float.dw >> 31;
  return sign;
}
int float_get_exp(float value) {
  union f cast_float;
  cast_float.fl = value;
  int exp = (cast_float.dw >> 23) & 0xFF;
  return exp;
}
int float_get_mantissa(float value) {
  union f cast_float;
  cast_float.fl = value;
  int exp = float_get_exp(value);
  int mantissa = exp ? (cast_float.dw & 0x7FFFFF) | 0x800000
                     : (cast_float.dw & 0x7FFFFF) << 1;
  return mantissa;
}
int counts_zeros(float value) {
  union f cast_float;
  cast_float.fl = value;
  int count = 0;
  while (!float_get_bit(cast_float.dw, count) && count < 23) count++;
  return count;
}

int print_int_bin(int value) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", float_get_bit(value, i));
    if (i % 8 == 0 && i != 0) printf(" ");
  }
  printf("\n");
  return 0;
}
int set_float_mantis(s21_big_decimal *value, int diff) {
  s21_big_decimal five = {{0x00000005, 0, 0, 0, 0, 0, 0}};
  s21_13_decimal value_13 = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  big_decimal_to_decimal_13(*value, &value_13);
  for (int i = 0; i < diff; i++) {
    s21_bit_mul_13(value_13, five, &value_13);
  }
  for (int i = diff; i < 0; i++) {
    s21_bit_shift_left_13(&value_13, 1);
  }
  int scale = decimal_13_to_big_decimal(value_13, value, diff);

  return scale;
}

void s21_bit_mul_13(s21_13_decimal value_1, s21_big_decimal value_2,
                    s21_13_decimal *result) {
  s21_clear_13_decimal(result);
  s21_13_decimal temp;
  s21_clear_13_decimal(&temp);
  for (int i = 0; i < 5; i++) {
    if (s21_get_bit(value_2, i)) {
      temp = value_1;
      for (int j = 0; j < i; j++) {
        s21_bit_shift_left_13(&temp, 1);
      }
      s21_bit_add_13(*result, temp, result);
    }
  }
}
int big_decimal_to_decimal_13(s21_big_decimal value, s21_13_decimal *result) {
  for (int i = 0; i < 6; i++) {
    result->bits[i] = value.bits[i];
  }
  for (int i = 6; i <= 13; i++) {
    result->bits[i] = 0;
  }

  return 0;
}
int decimal_13_to_big_decimal(s21_13_decimal value, s21_big_decimal *result,
                              int diff) {
  s21_clear_big_decimal(result);
  s21_13_decimal tmp = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  s21_13_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal ten = {{0x0000000A, 0, 0, 0, 0, 0, 0}};
  int ostatok = 0;
  int count_zeros = 0;
  int ost_dumb = 0;
  int decimal_places = count_decimal_places(value);
  int scale = diff - (decimal_places - 7);
  for (int i = 0; i < (decimal_places - 7); i++) {
    ostatok = div_ten_ost_13(value, &value);
    if (scale > 28) {
      scale--;
      i--;
    }
    if (ostatok != 0) {
      count_zeros++;
    }
  }
  ost_dumb = div_ten_ost_13(value, &tmp);
  if (ostatok >= 5 && ostatok <= 9) {
    if (ostatok == 5 && count_zeros == 1) {
      if (ost_dumb % 2) {
        s21_bit_add_13(value, one, &value);
      }
    } else {
      s21_bit_add_13(value, one, &value);
    }
  }
  if (diff <= 0) {
    for (int i = 0; i < (decimal_places - 7); i++) {
      s21_bit_mul_13(value, ten, &value);
    }
  }

  for (int i = 0; i < 3; i++) {
    result->bits[i] = value.bits[i];
  }
  if ((decimal_places - 7) < 0) scale = diff;
  return scale;
}
bool is_overflow_13(s21_13_decimal value) {
  for (int i = 3; i < 13; i++) {
    if (value.bits[i] != 0) {
      return true;
    }
  }
  return false;
}
int div_ten_ost_13(s21_13_decimal value_1, s21_13_decimal *result) {
  s21_13_decimal value_2 = {{0xA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  s21_clear_13_decimal(result);
  int index_1 = find_index_13(value_1);
  int index_2 = find_index_13(value_2);
  if ((index_1 - index_2) > 0) {
    s21_bit_shift_left_13(&value_2, index_1 - index_2);
  }
  for (int i = index_1 - index_2 + 1; i > 0; i--) {
    if (s21_is_greater_or_equal_mantisa_13(value_1, value_2)) {
      s21_bit_shift_left_13(result, 1);
      s21_set_bit_13(result, 0);
      s21_sub_mantisa_13(value_1, value_2, &value_1);
    } else {
      s21_bit_shift_left_13(result, 1);
    }
    s21_bit_shift_right_13(&value_2, 1);
  }
  return value_1.bits[0];
}
void s21_bit_shift_right_13(s21_13_decimal *value, int shift) {
  if (shift < 0 || shift >= 416) {
    printf("Overflow\n");
    return;
  }
  for (int i = 0; i <= 415 - shift; i++) {
    if (s21_get_bit_13(*value, i + shift)) {
      if (s21_get_bit_13(*value, i) == 0) s21_set_bit_13(value, i);
    } else {
      s21_clear_exp_13(value, i);
    }
  }
  for (int i = 415; i > 415 - shift; i--) {
    s21_clear_exp_13(value, i);
  }
}
int s21_sub_mantisa_13(s21_13_decimal value_1, s21_13_decimal value_2,
                       s21_13_decimal *result) {
  int error_code = 0;

  s21_clear_13_decimal(result);
  for (int i = 0; i < 416; i++) {
    s21_set_bit_13(&value_2, i);
  }
  s21_13_decimal tmp = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  s21_bit_add_13(value_2, tmp, &value_2);
  s21_bit_add_13(value_1, value_2, result);
  return error_code;
}
int s21_is_greater_or_equal_mantisa_13(s21_13_decimal value_1,
                                       s21_13_decimal value_2) {
  int res = 0;
  if (s21_is_equal_mantisa_13(value_1, value_2) ||
      s21_is_greater_mantisa_13(value_1, value_2))
    res = 1;
  return res;
}
int s21_is_equal_mantisa_13(s21_13_decimal value_1, s21_13_decimal value_2) {
  int res = 1;
  for (int i = 0; i < 416 && (res); i++) {
    if (s21_get_bit_13(value_1, i) != s21_get_bit_13(value_2, i)) res = 0;
  }
  return res;
}
int s21_is_greater_mantisa_13(s21_13_decimal value_1, s21_13_decimal value_2) {
  int res = 1;
  int flag = 1;
  for (int i = 415; i >= 0 && (res) && (flag); i--) {
    if (s21_get_bit_13(value_1, i) < s21_get_bit_13(value_2, i))
      res = 0;
    else if (s21_get_bit_13(value_1, i) > s21_get_bit_13(value_2, i))
      flag = 0;
  }
  return res;
}

int find_index_13(s21_13_decimal decimal) {
  int flag = 0;
  for (int i = 415; i >= 0 && (!flag); i--) {
    if (s21_get_bit_13(decimal, i) == 1) {
      flag = i;
    }
  }
  return flag;
}

int s21_clear_13_decimal(s21_13_decimal *value) {
  for (int i = 0; i < 13; i++) {
    value->bits[i] = 0;
  }

  return 0;
}
void s21_bit_shift_left_13(s21_13_decimal *value, int shift) {
  if (shift < 0 || shift >= 416) {
    printf("Overflow\n");
    return;
  }
  for (int i = 415; i >= shift; i--) {
    if (s21_get_bit_13(*value, i - shift)) {
      if (s21_get_bit_13(*value, i) == 0) s21_set_bit_13(value, i);
    } else {
      s21_clear_exp_13(value, i);
    }
  }
  for (int i = 0; i < shift; i++) {
    s21_clear_exp_13(value, i);
  }
}
int s21_get_bit_13(s21_13_decimal value, int n) {
  unsigned int f = 0b00000001;
  unsigned int res;

  int index = n / 32;
  int bit_position = n % 32;
  res = value.bits[index] & (f << bit_position);

  res = res >> bit_position;
  return res;
}
int s21_set_bit_13(s21_13_decimal *value, int n) {
  unsigned int f = 0b00000001;
  unsigned int res = 0;
  unsigned int bit = s21_get_bit_13(*value, n);

  int index = n / 32;
  int bit_position = n % 32;
  f = f << bit_position;
  value->bits[index] = bit ? value->bits[index] & (~f) : value->bits[index] | f;

  return res;
}
void s21_clear_exp_13(s21_13_decimal *value, int position) {
  int index = position / 32;
  int bit_position = position % 32;
  value->bits[index] &= ~(1 << bit_position);
}
void s21_bit_add_13(s21_13_decimal value_1, s21_13_decimal value_2,
                    s21_13_decimal *result) {
  int bit;
  int in_mind = 0;
  for (int i = 0; i < 416; i++) {
    bit = s21_get_bit_13(value_1, i) + s21_get_bit_13(value_2, i) + in_mind;
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
      if (s21_get_bit_13(*result, i) == 0) s21_set_bit_13(result, i);
    } else {
      if (s21_get_bit_13(*result, i) == 1) s21_set_bit_13(result, i);
    }
  }
}
int count_decimal_places(s21_13_decimal value) {
  int count = 0;
  while (!s21_is_zero_13(value)) {
    div_ten_ost_13(value, &value);
    count++;
  }
  return count;
}
int s21_is_zero_13(s21_13_decimal value) {
  int res = 1;
  for (int i = 0; i < 13; i++) {
    if (value.bits[i] != 0) res = 0;
  }
  return res;
}