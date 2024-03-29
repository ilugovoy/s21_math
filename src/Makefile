#------------> Опции компилятора
FLAGS_MACOS = -L $(shell brew --prefix)/lib -lcheck
SLFLAGS = -lcheck -lsubunit
MACOS_FLAG = 0

# флаги специальных библиотек для сборки на макос
ifeq ($(shell uname), Darwin)
SLFLAGS = $(FLAGS_MACOS)
MACOS_FLAG = 1
endif

CC=gcc # компилятор
LFLAGS=-g # для сборки с отладочной информацией
LIBFLAGS=-lm # для линковки c математической либой
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic # для обработки ошибок
GCOVFLAGS=--coverage -fprofile-arcs -ftest-coverage # для анализа покрытия

# указывает флаги для сборки на маке с камнем M1
ifeq ($(shell uname -m), arm64)
CFLAGS := $(filter-out -pedantic,$(CFLAGS))
CFLAGS += -arch arm64
endif

# указывает флаги для сборки на маке с камнем M2
ifeq ($(shell uname -m), arm64e)
CFLAGS := $(filter-out -pedantic,$(CFLAGS))
endif


#------------> Адреса, пути и цели для сборки программы
BUILD_SOURCES=$(shell find functions -maxdepth 2 -name '*.c') # Папки для сборки библиотеки
TEST_SOURCES=$(shell find functions -maxdepth 2 -name '*.c') tests/cases/*.c tests/s21_tests.c # Папки для тестирования библиотечных функций

all: rebuild

rebuild: clean s21_math.a test gcov_report open_report
# cpp style

s21_math.a: 
	$(CC) -c $(BUILD_SOURCES)
	ar rc s21_math.a *.o

test: s21_math.a 
	$(CC) $(CFLAGS) $(TEST_SOURCES) s21_math.a $(SLFLAGS) $(LIBFLAGS) -o s21_tests
	./s21_tests

gcov_report:
	$(CC) $(CFLAGS) $(TEST_SOURCES) s21_math.a $(SLFLAGS) $(LIBFLAGS) -o s21_gcov $(GCOVFLAGS)
	./s21_gcov
	lcov -t "gcov_report" -o s21_gcov_report.info -c -d .
# следующая строчка исключает папку tests из отчёта о покрытии
	lcov -r s21_gcov_report.info '*/tests/*' -o s21_gcov_report.info
	genhtml -o s21_report s21_gcov_report.info

open_report:
	@open s21_report/index.html
# @google-chrome s21_report/index.html 2> /dev/null 

# очистка
clean: clean_s21_report clean_o
	rm -rf s21_tests s21_gcov *.gcno *.gcda *.info *.html *.css *.png *.deb

clean_o:    
	@rm -f *.a
	@rm -f *.o

clean_s21_report:
	@rm -rf report s21_report


#------------> Дополнительные проверки
valgrind:
	@valgrind  --leak-check=full --track-origins=yes ./s21_tests

cpp:    
	@cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h **/*.c **/*.h

style:
	@cd resources/scripts && bash ./style_test.sh || (echo "Style tests failed")

check:    
	@cd resources/scripts && bash ./install_brew.sh || (echo "install_brew.sh failed")
	@cd resources/scripts && bash ./check_gcov_lcov.sh || (echo "check_gcov_lcov.sh failed")

# исключения для аналогичных имён файлов
.PHONY: make clean cppcheck style memcheck test gcov_report open_report cpp valgrind
