#ifndef TEST_H
#define TEST_H

#include <check.h>  //"check.h"
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define s21_MAXDEC 2e96 - 1
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"
#define DEBUG 1

typedef union float_cast_test {
  float f;
  struct {
    uint32_t mantisa : 23;
    uint32_t exponent : 8;
    uint32_t sign : 1;
  } parts;
  uint32_t bytes;
  int int32_bytes;
} float_cast_test;

int print_bin_decimal(s21_decimal value);
int print_sign(s21_decimal value);
int print_bit_3(s21_decimal value);
int print_mantisa(s21_decimal value);
int print_bin_decimal_big(s21_big_decimal value);
int print_sign_big(s21_big_decimal value);
int print_bit_3_big(s21_big_decimal value);
int print_mantisa_big(s21_big_decimal value);
int print_match_decimal(s21_decimal real, s21_decimal etalon);
int print_match_bit_3(s21_decimal real, s21_decimal etalon);
int print_match_mantisa(s21_decimal real, s21_decimal etalon);
int print_dec_decimal(s21_decimal value);
int print_float_bin(float value);
int float_get_bit(int value, int n);
int div_return_ost(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
void fill_string_zeros(char *result);
void set_sign_string(s21_decimal value, char *result);
void set_dot_string(s21_decimal value, char *result);
void from_decimal_in_string(s21_decimal value, char *result);
int find_important_numb(char *result);
void remove_extra_zeros(char *result);
int s21_get_dec_sign(s21_decimal value);
int s21_get_dec_bit(s21_decimal value, int n);
int dec_is_zero(s21_decimal value);

void test_add_fail(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_add(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_is_equal(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_is_greater(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_is_greater_or_equal(s21_decimal decimal1, s21_decimal decimal2,
                              int check);
void test_is_less(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_is_less_or_equal(s21_decimal decimal1, s21_decimal decimal2,
                           int check);
void test_is_not_equal(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_div(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_div_fail(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_div_fail2(s21_decimal decimal1, s21_decimal decimal2,
                    s21_decimal decimal_check, int code_check);
void test_truncate(s21_decimal decimal, s21_decimal decimal_check);
void test_floor(s21_decimal decimal, s21_decimal decimal_check);
void test_round(s21_decimal decimal, s21_decimal decimal_check);
void test_negate(s21_decimal decimal, s21_decimal decimal_check);
int test_are_same(s21_decimal value_1, s21_decimal value_2);
void test_mul(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_mul_fail2(s21_decimal decimal1, s21_decimal decimal2,
                    s21_decimal decimal_check, int code_check);
void test_mul_fail(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_from_decimal_to_int(s21_decimal decimal, int check);
void test_from_decimal_to_int_fail(s21_decimal decimal);
void test_from_int_to_decimal(int number, s21_decimal decimal_check);
void test_from_decimal_to_float(s21_decimal decimal, int check);
void test_from_float_to_decimal(int f, s21_decimal decimal_check);
void test_sub(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_sub_fail(s21_decimal decimal1, s21_decimal decimal2, int check);

Suite *suite_add(void);
Suite *suite_sub(void);
Suite *suite_mul(void);
Suite *suite_div(void);
Suite *suite_comp(void);
Suite *suite_funcs(void);
Suite *suite_pars(void);

#endif