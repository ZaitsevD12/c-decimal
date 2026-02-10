#include <assert.h>

#include "../s21_decimal.h"

#define WRONGVALUE 0b01111111000000001111111111111111

bool is_overflow(s21_big_decimal value) {
  for (int i = 3; i < 6; i++) {
    if (value.bits[i] != 0) {
      return true;
    }
  }
  return false;
}

int decimal_to_big_decimal(s21_decimal value, s21_big_decimal *result) {
  for (int i = 0; i < 3; i++) {
    result->bits[i] = value.bits[i];
  }

  for (int i = 3; i <= 5; i++) {
    result->bits[i] = 0;
  }

  result->bits[6] = value.bits[3];
  return 0;
}

int big_decimal_to_decimal(s21_big_decimal value, s21_decimal *result) {
  int ostatok = 0;
  s21_big_decimal ten = {{0x0000000A, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal one = {{0x1, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal tmp = {{0, 0, 0, 0, 0, 0, 0}};
  int ost_dumb = 0;
  int step = 0;
  int count_zeros = 0;
  int pow_input = s21_get_pow(value);

  int sign = s21_get_sign(value);
  while (is_overflow(value) || ((pow_input - step) > 28)) {
    ostatok = div_ost(value, ten, &value);
    step++;
    if (ostatok != 0) {
      count_zeros++;
    }
  }

  ost_dumb = div_ost(value, ten, &tmp);
  if (ostatok >= 5 && ostatok <= 9) {
    if (ostatok == 5 && count_zeros == 1) {
      if (ost_dumb % 2) {
        s21_bit_add(value, one, &value);
      }
    } else {
      s21_bit_add(value, one, &value);
    }
  }
  for (int i = 0; i < 3; i++) {
    result->bits[i] = value.bits[i];
  }

  s21_set_pow(&value, (pow_input - step));
  if (sign) {
    if (!s21_get_sign(value)) {
      s21_set_sign(&value);
    }
  }
  result->bits[3] = value.bits[6];
  return 0;
}

void s21_clear_exp(s21_big_decimal *value, int position) {
  int index = position / 32;
  int bit_position = position % 32;
  value->bits[index] &= ~(1 << bit_position);
}

void s21_clear_sign(s21_big_decimal *value) { value->bits[6] &= ~(1 << 31); }

void s21_bit_shift_left(s21_big_decimal *value, int shift) {
  if (shift < 0 || shift >= 192) {
    printf("Overflow\n");
    return;
  }
  for (int i = 191; i >= shift; i--) {
    if (s21_get_bit(*value, i - shift)) {
      if (s21_get_bit(*value, i) == 0) s21_set_bit(value, i);
    } else {
      s21_clear_exp(value, i);
    }
  }
  for (int i = 0; i < shift; i++) {
    s21_clear_exp(value, i);
  }
}

int s21_get_sign(s21_big_decimal value) {
  int res = s21_get_bit(value, 223);
  return res;
}

int s21_get_bit(s21_big_decimal value, int n) {
  unsigned int f = 0b00000001;
  unsigned int res;

  int index = n / 32;
  int bit_position = n % 32;
  res = value.bits[index] & (f << bit_position);

  res = res >> n;
  return res;
}

int s21_set_bit(s21_big_decimal *value, int n) {
  unsigned int f = 0b00000001;
  unsigned int res = 0;
  unsigned int bit = s21_get_bit(*value, n);

  int index = n / 32;
  int bit_position = n % 32;
  f = f << bit_position;
  value->bits[index] = bit ? value->bits[index] & (~f) : value->bits[index] | f;

  return res;
}

int s21_set_sign(s21_big_decimal *value) {
  s21_set_bit(value, 223);
  return 0;
}

int s21_clear_decimal(s21_decimal *value) {
  value->bits[0] = 0;
  value->bits[1] = 0;
  value->bits[2] = 0;
  value->bits[3] = 0;
  return 0;
}

int s21_clear_big_decimal(s21_big_decimal *value) {
  value->bits[0] = 0;
  value->bits[1] = 0;
  value->bits[2] = 0;
  value->bits[3] = 0;
  value->bits[4] = 0;
  value->bits[5] = 0;
  value->bits[6] = 0;
  return 0;
}

void s21_normalize(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  int pow_1 = s21_get_pow(*value_1);
  int pow_2 = s21_get_pow(*value_2);

  if (pow_1 != pow_2) {
    int denom = s21_find_denom(pow_1, pow_2);
    int diff_1 = denom - pow_1;
    int diff_2 = denom - pow_2;

    if (diff_1 != 0) {
      s21_normalize_mantis(value_1, diff_1);
      diff_1 = 0;
    }

    if (diff_2 != 0) {
      s21_normalize_mantis(value_2, diff_2);
      diff_2 = 0;
    }
    s21_set_pow(value_1, denom);
    s21_set_pow(value_2, denom);
  }
}

void s21_normalize_mantis(s21_big_decimal *value, int diff) {
  s21_big_decimal ten = {{0x0000000A, 0, 0, 0, 0, 0, 0}};
  if (diff > 0) {
    for (int i = 0; i < diff; i++) {
      s21_bit_mul(*value, ten, value);
    }
  }
  if (diff < 0) {
    for (int i = 0; i < diff; i++) {
      div_ost(*value, ten, value);
    }
  }
}

void s21_bit_mul(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  s21_clear_big_decimal(result);
  s21_big_decimal temp;
  s21_clear_big_decimal(&temp);
  for (int i = 0; i < 192; i++) {
    if (s21_get_bit(value_2, i)) {
      temp = value_1;
      for (int j = 0; j < i; j++) {
        s21_bit_shift_left(&temp, 1);
      }
      s21_bit_add(*result, temp, result);
    }
  }
}

int s21_get_pow(s21_big_decimal value) {
  int res = 0b00000000;
  for (int i = 23; i > 15; i--) {
    res = res << 1;
    res = res | s21_get_bit(value, i + 192);
  }

  return res;
}

void s21_set_pow(s21_big_decimal *value, int pow) {
  for (int i = 23; i > 15; i--) {
    if (s21_get_bit(*value, i + 192)) {
      s21_set_bit(value, i + 192);
    }
  }

  int j = 0;
  unsigned int f = 0b00000001;
  for (int i = 16; i < 24; i++, j++) {
    if (abs(pow) & (f << j)) {
      s21_set_bit(value, i + 192);
    }
  }
}

int s21_find_denom(int pow_1, int pow_2) {
  int min = pow_1 < pow_2 ? pow_1 : pow_2;
  int max = min == pow_1 ? pow_2 : pow_1;

  while (min < max) {
    min++;
  }

  return min;
}
int s21_get_dec_sign(s21_decimal value) {
  int res = s21_get_dec_bit(value, 127);
  return res;
}

int s21_get_dec_bit(s21_decimal value, int n) {
  unsigned int f = 0b00000001;
  unsigned int res;

  int index = n / 32;
  int bit_position = n % 32;
  res = value.bits[index] & (f << bit_position);

  res = res >> bit_position;
  return res;
}

int s21_is_correct(s21_decimal decimal) {
  int res = 1;
  s21_big_decimal tmp;
  decimal_to_big_decimal(decimal, &tmp);
  int pow = s21_get_pow(tmp);
  int null = 0x00000000;

  if (null != (decimal.bits[3] &= WRONGVALUE)) {
    res = 0;
  }

  if (pow < 0 || pow > 28) {
    res = 0;
  }

  return res;
}