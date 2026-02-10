CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -std=c11

all:
	make s21_decimal.a

s21_decimal.a:
	$(CC) $(CFLAGS) arithmetic/*.c comparison/*.c funcs/*.c help/*.c parsers/*.c
	ar rcs s21_decimal.a *.o

s21_test: s21_decimal.a
	$(CC) $(CFLAGS) test/test_add.c test/test_comp.c test/test_div.c test/test_funcs.c test/test_mul.c test/test_pars.c test/test_sub.c test/test.c test/function_for_test.c
	$(CC) -L. -I. -o test_all *.o s21_decimal.a `pkg-config --cflags --libs check`

clean:
	rm *.o *.a *.gcno *.gcda *.gcov *.info *.log test_all
	rm -rf report

rebuild: 
	make clean
	make all

gcov_report:
	mkdir -p report
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage arithmetic/*.c comparison/*.c funcs/*.c help/*.c parsers/*.c
	ar rcs s21_decimal_gcov.a *.o
	ranlib s21_decimal_gcov.a
	rm *.o
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage test/*.c
	$(CC) -L. -I. -o test_gcov *.o s21_decimal_gcov.a -lgcov -pthread -lcheck_pic -lrt -lm -lsubunit
	./test_gcov
	gcov -o . arithmetic/*.c comparison/*.c funcs/*.c help/*.c parsers/*.c
	lcov -b ./ -d . --gcov-tool /usr/bin/gcov -c -o output.info --no-external
	genhtml -o report/ output.info