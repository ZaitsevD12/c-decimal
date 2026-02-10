#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 0;
  if (!(dst == NULL) && !(abs(src) > s21_MAXDEC)) {
    s21_clear_decimal(dst);
    s21_big_decimal big_dst;
    decimal_to_big_decimal(*dst, &big_dst);

    if (src < 0) {
      s21_set_sign(&big_dst);
      src = -src;
    }
    big_dst.bits[0] = src;

    big_decimal_to_decimal(big_dst, dst);
  } else
    res = 1;

  return res;
}