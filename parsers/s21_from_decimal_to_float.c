#include "../s21_decimal.h"

int s21_get_dec_sign(s21_decimal value);

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int flag = 0;
  if (s21_is_correct(src) && !(dst == NULL)) {
    double res = 0;
    for (int i = 0; i < 96; i++) {
      if (s21_get_dec_bit(src, i) == 1) {
        res += pow(2.0, i);
      }
    }

    int scale = s21_get_scale(&src);
    res /= pow(10, scale);

    int sign = s21_get_dec_sign(src);
    if (sign == 1) {
      res = res * (-1);
    }

    *dst = (float)res;
  } else
    flag = 1;
  return flag;
}

unsigned s21_get_scale(const s21_decimal *dec) {
  int big = 0b11111111;
  return (dec->bits[3] >> 16) & big;
}