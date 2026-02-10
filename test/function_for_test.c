#include "test.h"

// Pechataet decimal pobitovo
int print_bin_decimal(s21_decimal value) {
  print_sign(value);
  printf("Scale factor ");
  print_bit_3(value);
  printf("Mantisa ");
  print_mantisa(value);
  return 0;
}

int print_sign(s21_decimal value) {
  printf("Sign ");
  if (s21_get_dec_sign(value) == 0)
    printf("%s|+| %s", GREEN, RESET);
  else
    printf("%s|-| %s", GREEN, RESET);
  return 0;
}
int print_bit_3(s21_decimal value) {
  for (int i = 127; i >= 96; i--) {
    printf("%d", s21_get_dec_bit(value, i));
    if (i % 8 == 0 && i != 0) printf(" ");
  }
  printf("\n");
  return 0;
}
int print_mantisa(s21_decimal value) {
  for (int i = 95; i >= 0; i--) {
    printf("%d", s21_get_dec_bit(value, i));
    if (i % 8 == 0 && i != 0) printf(" ");
  }
  printf("\n");
  return 0;
}
int print_bin_decimal_big(s21_big_decimal value) {
  print_sign_big(value);
  printf("Scale factor ");
  print_bit_3_big(value);
  printf("Mantisa ");
  print_mantisa_big(value);
  return 0;
}

int print_sign_big(s21_big_decimal value) {
  printf("Sign ");
  if (s21_get_sign(value) == 0)
    printf("%s|+| %s", GREEN, RESET);
  else
    printf("%s|-| %s", GREEN, RESET);
  return 0;
}
int print_bit_3_big(s21_big_decimal value) {
  for (int i = 223; i >= 192; i--) {
    printf("%d", s21_get_bit(value, i));
    if (i % 8 == 0 && i != 0) printf(" ");
  }
  printf("\n");
  return 0;
}
int print_mantisa_big(s21_big_decimal value) {
  for (int i = 191; i >= 0; i--) {
    printf("%d", s21_get_bit(value, i));
    if (i % 8 == 0 && i != 0) printf(" ");
    if (i == 96) printf("\n");
  }
  printf("\n");
  return 0;
}
// Pechataet decimal - etalon pobitovo bez cveta
// Pechataet decimal - real pobitovo i sravnivaet bit c bitom etalona
// V zavisimosti ot resultata sravnenia men'aetc'a cvet
//  Real = predpolagaet resultat nashih functij
//  Etalon = c chem sravnivaem
int print_match_decimal(s21_decimal real, s21_decimal etalon) {
  print_match_bit_3(real, etalon);
  print_match_mantisa(real, etalon);
  return 0;
}
int print_match_bit_3(s21_decimal real, s21_decimal etalon) {
  int bit_real, bit_etalon;
  printf("Scale factor check  ");
  print_bit_3(etalon);
  printf("Scale factor result ");
  for (int i = 127; i >= 96; i--) {
    bit_real = s21_get_dec_bit(real, i);
    bit_etalon = s21_get_dec_bit(etalon, i);
    if (bit_real == bit_etalon) {
      printf("%s%d%s", GREEN, bit_real, RESET);
      if (i % 8 == 0 && i != 0) printf(" ");
    } else {
      printf("%s%d%s", RED, bit_real, RESET);
      if (i % 8 == 0 && i != 0) printf(" ");
    }
  }
  printf("\n");
  return 0;
}
int print_match_mantisa(s21_decimal real, s21_decimal etalon) {
  int bit_real, bit_etalon;
  printf("Mantisa check  ");
  print_mantisa(etalon);
  printf("Mantisa result ");
  for (int i = 95; i >= 0; i--) {
    bit_real = s21_get_dec_bit(real, i);
    bit_etalon = s21_get_dec_bit(etalon, i);
    if (bit_real == bit_etalon) {
      printf("%s%d%s", GREEN, bit_real, RESET);
      if (i % 8 == 0 && i != 0) printf(" ");
    } else {
      printf("%s%d%s", RED, bit_real, RESET);
      if (i % 8 == 0 && i != 0) printf(" ");
    }
  }
  printf("\n");
  return 0;
}
int print_dec_decimal(s21_decimal value) {
  char result[35];
  fill_string_zeros(result);
  set_sign_string(value, result);
  set_dot_string(value, result);
  from_decimal_in_string(value, result);
  remove_extra_zeros(result);
  printf("%s\n", result);
  return 0;
}
int div_return_ost(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  if (dec_is_zero(value_2)) return 10;
  s21_clear_decimal(result);

  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;
  s21_big_decimal big_result;

  decimal_to_big_decimal(value_1, &big_value_1);
  decimal_to_big_decimal(value_2, &big_value_2);
  decimal_to_big_decimal(*result, &big_result);

  int index_1 = find_index(big_value_1);
  int index_2 = find_index(big_value_2);
  if ((index_1 - index_2) > 0) {
    s21_bit_shift_left(&big_value_2, index_1 - index_2);
  }  // normalizacia delitelia
  for (int i = index_1 - index_2 + 1; i > 0; i--) {
    if (s21_is_greater_or_equal_mantisa(big_value_1, big_value_2)) {
      s21_bit_shift_left(&big_result, 1);  // Dublicat koda
      s21_set_bit(&big_result, 0);
      s21_sub_mantisa(big_value_1, big_value_2, &big_value_1);  // bilo s21_sub
    } else {
      s21_bit_shift_left(&big_result, 1);  // Dublicat koda
    }
    s21_bit_shift_right(&big_value_2, 1);
  }
  big_decimal_to_decimal(big_result, result);
  return big_value_1.bits[0];
}
void fill_string_zeros(char *result) {
  for (int i = 0; i < 35; i++) {
    if (i == 34)
      result[i] = '\0';
    else
      result[i] = '0';
  }
}
void set_sign_string(s21_decimal value, char *result) {
  if (s21_get_dec_sign(value)) {
    result[0] = '-';
  } else {
    result[0] = '+';
  }
}
void set_dot_string(s21_decimal value, char *result) {
  s21_big_decimal tmp;
  decimal_to_big_decimal(value, &tmp);
  int index_dot = 33 - s21_get_pow(tmp);
  if (index_dot < 33 && index_dot > 0) {
    result[index_dot] = '.';
  }
}
void from_decimal_in_string(s21_decimal value, char *result) {
  int stop = 1;
  char ost_del_na_10;
  s21_decimal ten = {{0x0000000A, 0, 0, 0}};
  for (int i = 33; i >= 1 && stop; i--) {
    if (result[i] == '.') i--;
    ost_del_na_10 = div_return_ost(value, ten, &value) + 48;
    result[i] = ost_del_na_10;
    if (dec_is_zero(value)) {
      stop = 0;
    }
  }
}
void remove_extra_zeros(char *result) {
  int index_important_numb = find_important_numb(result);
  if (index_important_numb) {
    for (int i = 1; i < 34 - index_important_numb; i++) {
      result[i] = result[i + index_important_numb];
    }
    result[34 - index_important_numb] = '\0';
  } else
    result[2] = '\0';
}
int find_important_numb(char *result) {
  int res = 0;
  for (int i = 1; i < 34 && !res; i++) {
    if (result[i] != '0') {
      if (result[i] == '.') {
        res = i - 2;
      } else {
        res = i - 1;
      }
    }
  }
  return res;
}

int dec_is_zero(s21_decimal value) {  // proveryaet na zero obychniy decimal
  int res = 1;
  if (value.bits[0] != 0 || value.bits[1] != 0 || value.bits[2] != 0) res = 0;
  return res;
}
