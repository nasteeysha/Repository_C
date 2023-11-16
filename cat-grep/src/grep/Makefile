CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: s21_grep

s21_grep: s21_grep.c s21_grep_main.c
	$(CC) $(CFLAGS) -o s21_grep s21_grep.c s21_grep_main.c

python:
	python3 ../../materials/linters/cpplint.py --extensions=c s21_grep.c s21_grep.h s21_grep_main.c

leaks:
	leaks -atExit -- ./s21_grep

clean:
	rm -rf s21_grep

rebuild: clean all