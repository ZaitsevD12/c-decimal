#ifndef S21_DECIMAL
#define S21_DECIMAL

#define s21_MAXDEC 2e96 - 1

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[7];
} s21_big_decimal;

// HELP
int s21_get_sign(s21_big_decimal value);
int s21_get_bit(s21_big_decimal value, int n);
int s21_get_dec_bit(s21_decimal value, int n);
int s21_get_dec_sign(s21_decimal value);
int s21_set_bit(s21_big_decimal *value, int exp);
int s21_set_sign(s21_big_decimal *value);
int s21_clear_decimal(s21_decimal *value);
int s21_clear_big_decimal(s21_big_decimal *value);
void s21_normalize(s21_big_decimal *value_1, s21_big_decimal *value_2);
void s21_normalize_mantis(s21_big_decimal *value, int diff);
int s21_get_pow(s21_big_decimal value);
void s21_set_pow(s21_big_decimal *value, int pow);
int s21_find_denom(int pow_1, int pow_2);
void s21_bit_shift_left(s21_big_decimal *value, int shift);
void s21_clear_sign(s21_big_decimal *value);
void s21_clear_exp(s21_big_decimal *value, int position);
int s21_is_zero(s21_big_decimal value);
bool is_overflow(s21_big_decimal value);
int decimal_to_big_decimal(s21_decimal value, s21_big_decimal *result);
int big_decimal_to_decimal(s21_big_decimal value, s21_decimal *result);
unsigned s21_get_scale(const s21_decimal *dec);
int s21_is_correct(s21_decimal decimal);

// HELP TRUNC
int div_ost(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result);
int find_index(s21_big_decimal decimal);
void s21_bit_shift_right(s21_big_decimal *value, int shift);
int s21_sub_mantisa(s21_big_decimal value_1, s21_big_decimal value_2,
                    s21_big_decimal *result);
int s21_is_equal_mantisa(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_is_greater_mantisa(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_is_greater_or_equal_mantisa(s21_big_decimal value_1,
                                    s21_big_decimal value_2);
int big_trunc(s21_big_decimal big_value, s21_big_decimal *big_result);

// PRINTING
int print_bit_3(s21_decimal value);
int print_mantisa(s21_decimal value);
int print_sign(s21_decimal value);
int print_bin_decimal(s21_decimal value);

// ARITHMETIC
//  ERROR CODES:
//  0 - OK
//  1 - the value is too big or infinity
//  2 - the value is too small or negative infinity
//  3 - division by 0

int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // "+"
int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // "-"
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // "*"
int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // "/"

// ARITHMETIC EXTRAS
// int s21_bit_div(s21_decimal value_1, s21_decimal value_2, s21_decimal*
// result);
void s21_bit_mul(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
int s21_sub_positive(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result);
int s21_add_positive(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result);
void s21_bit_add(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
// COMPARISON

// RETURN VALUE:
// 0 - FALSE
// 1 - TRUE

int s21_is_less(
    s21_decimal value_1,
    s21_decimal value_2);  // "<" // Returns 1, if value_1 is less, than value_2
int s21_is_less_or_equal(s21_decimal value_1,
                         s21_decimal value_2);  // "<=" // Returns 1, if value_1
                                                // is less or equal value_2
int s21_is_greater(s21_decimal value_1,
                   s21_decimal value_2);  // ">" // Returns 1, if value_1 if
                                          // greater, than value_2
int s21_is_greater_or_equal(
    s21_decimal value_1,
    s21_decimal
        value_2);  // ">=" // Returns 1, if value_1 is greater or equal value_2
int s21_is_equal(
    s21_decimal value_1,
    s21_decimal value_2);  // "==" // Returns 1, if value_1 is equal value_2
int s21_is_not_equal(
    s21_decimal value_1,
    s21_decimal value_2);  // "!=" // Returns 1, if value_1 is not equal value_2

int is_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int is_greater(s21_big_decimal value_1, s21_big_decimal value_2);
int is_less(s21_big_decimal value_1, s21_big_decimal value_2);

// PARSERS

// RETURN VALUE - ERROR CODE:
// 0 - OK
// 1 - convertion error

int s21_from_int_to_decimal(int src, s21_decimal *dst);      //
int s21_from_float_to_decimal(float src, s21_decimal *dst);  //
int s21_from_decimal_to_int(s21_decimal src, int *dst);      //
int s21_from_decimal_to_float(s21_decimal src, float *dst);  //

// OTHER FUNCS

/* RETURN VALUE:
 * 0 - ОК;
 * 1 - any error;
 */

int s21_floor(s21_decimal value,
              s21_decimal *result);  // rounds to the nearest integer to
                                     // negative infinity (smth strange here)
int s21_round(s21_decimal value,
              s21_decimal *result);  // rounds to the nearest integer
int s21_truncate(s21_decimal value,
                 s21_decimal *result);  // returns integer part of decimal
int s21_negate(s21_decimal value,
               s21_decimal *result);  // changes sign (result = value * (-1))
#endif