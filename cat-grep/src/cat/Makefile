CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: s21_cat

s21_cat: s21_cat.c s21_cat_main.c
	$(CC) $(CFLAGS) -o s21_cat s21_cat.c s21_cat_main.c

python:
	python3 ../../materials/linters/cpplint.py --extensions=c s21_cat.c s21_cat.h s21_cat_main.c

leaks:
	leaks -atExit -- ./s21_cat

clean:
	rm -rf s21_cat

rebuild: clean all