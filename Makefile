FLAGS_MACOS = -L /usr/local/lib -lcheck
SLFLAGS = -lcheck -lsubunit

ifeq ($(shell uname), Darwin)
SLFLAGS = $(FLAGS_MACOS)
endif

CC=gcc # компилятор
LFLAGS=-g # для сборки с отладочной информацией
LIBFLAGS=-lm # для линковки c математической либой
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic # для обработки ошибок
GCOVFLAGS=--coverage -fprofile-arcs -ftest-coverage # для анализа покрытия


all: s21_math.a test gcov_report cpp style

s21_math.a:
	$(CC) $(CFLAGS) -c s21_math.c
	ar rc s21_math.a s21_math.o

test: s21_math.a
	$(CC) $(CFLAGS) s21_tests.c s21_math.a $(SLFLAGS) $(LIBFLAGS) -o s21_tests
	./s21_tests

gcov_report:
	$(CC) $(CFLAGS) s21_tests.c s21_math.c s21_math.a  $(SLFLAGS) $(LIBFLAGS) -o s21_gcov $(GCOVFLAGS)
	./s21_gcov
	lcov -t "gcov_report" -o s21_gcov_report.info -c -d .
	genhtml -o s21_report s21_gcov_report.info
	open s21_report/index.html

# очистка
clean: clean_s21_report clean_o
	rm -rf s21_tests s21_gcov *.a *.gcno *.gcda *.info *.html *.css *.png

clean_o:    
	@rm -f *.o

clean_s21_report:
	@rm -rf report s21_report

# тесты стиля и cpp
cpp:    
	@cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

style:
	@cd materials/scripts && bash ./style_test.sh || (echo "Style tests failed")

check:    
	@cd materials/scripts && bash ./check_gcov_lcov.sh || (echo "check_gcov_lcov.sh failed")

# исключения для аналогичных имён файлов
.PHONY: make clean cppcheck style memcheck test gcov_report cpp