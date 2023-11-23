CC=gcc # компилятор
LFLAGS=-g # для сборки с отладочной информацией
SLFLAGS=-lcheck -lsubunit # для модульного тестирования
LIBFLAGS=-lm # для линковки c математической либой
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic # для обработки ошибок
GCOVFLAGS=--coverage -fprofile-arcs -ftest-coverage # для анализа покрытия


all: s21_math.a test gcov_report cpp 
# style

%.o: %.c test_21_math.h
	$(CC) $(CFLAGS) $(LFLAGS) $< $(GCOVFLAGS) -o $@

test: s21_math.a s21_tests.c
	$(CC) $(CFLAGS) s21_tests.c s21_math.a $(SLFLAGS) $(LIBFLAGS) -o s21_tests
	./s21_tests

s21_math.o: s21_math.c s21_math.h
	$(CC) $(CFLAGS) $(LFLAGS) -c s21_math.c 

s21_math.a: s21_math.o
		ar rcs s21_math.a s21_math.o

gcov_report: s21_math.a s21_tests
	$(CC) $(GCOVFLAGS) $(CFLAGS) s21_tests.c s21_math.a $(SLFLAGS) $(LIBFLAGS) -o s21_gcov
	./s21_gcov
	lcov -t "gcov_report" -o s21_gcov_report.info -c -d .
	genhtml -o s21_report s21_gcov_report.info


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
	@cd style_test && bash ./style_test.sh || (echo "Style tests failed")


.PHONY: make clean cppcheck style memcheck test gcov_report cpp

