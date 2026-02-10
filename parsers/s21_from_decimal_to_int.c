#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;
  if (s21_is_correct(src) && !(dst == NULL)) {
    s21_truncate(src, &src);

    s21_big_decimal big_src;
    decimal_to_big_decimal(src, &big_src);

    if (s21_is_zero(big_src)) {
      *dst = 0;
    } else {
      for (int i = 1; i < 6 && !res; i++) {
        if (big_src.bits[i] != 0) res = 1;
      }
      int sign = s21_get_sign(big_src);

      if (sign == 0 && s21_get_bit(big_src, 31)) {
        res = 1;
      }
      if (sign == 1 && s21_get_bit(big_src, 31)) {
        s21_big_decimal int_min = {{0x80000000, 0x0, 0x0, 0, 0, 0, 0x80000000}};
        if (!is_equal(big_src, int_min)) res = 1;
      }

      if (!res) {
        *dst = big_src.bits[0];
        if (sign == 1) {
          *dst = *dst * (-1);
        }
      }
    }
  } else
    res = 1;
  return res;
}