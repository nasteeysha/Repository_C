CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11 
LIB = s21_matrix
TEST = test
FILE = s21_matrix

all:$(LIB).a

$(TEST): gcov$(LIB).a
	$(CC) s21_check/*.c -c
	$(CC) $(FLAGS) *.o -L. gcov$(LIB).a --coverage -lcheck -o $(TEST) -lpthread -lrt -lsubunit -lm
	./test

$(LIB).a: $(FILE).c $(LIB).h
	$(CC) -c $(FILE).c
	ar rc $(LIB).a $(FILE).o
	ranlib $(LIB).a

gcov$(LIB).a: *.c $(LIB).h
	# clear
	$(CC) -c *.c --coverage  $(FLAGS)
	ar rc gcov$(LIB).a *.o
	ranlib gcov$(LIB).a
	# rm -rf *.o
	
add_coverage_flag:
	$(eval FLAGS += --coverage)

gcov_report: add_coverage_flag test
	./test
	lcov -t "stest" -o test.info -c -d .
	genhtml -o report test.info

clean:
	rm -rf *.o $(TEST) *.a test.info s21_test.info report *.gcda *.gcno

rebuild: clean $(LIB).a

style:
	clang-format -i -style=Google *.c *.h s21_check/*.c s21_check/*.h

style_test:
	clang-format -n -style=Google *.c *.h s21_check/*.c s21_check/*.h
