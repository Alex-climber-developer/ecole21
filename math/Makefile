FLAGS=-c -Wall -Werror -Wextra

all: s21_math

s21_math: s21_math.o
	gcc s21_math.o -o s21_math

s21_math.o: s21_math.c
	gcc $(FLAGS) s21_math.c

clean:
	rm -rf *.o
	rm -rf s21_math

rebuild:
	Make clean
	Make

test: test_math.c
	gcc test_math.c

check:
	cppcheck *.c *.h
	cp ../../materials/linters/.clang-format ./
	clang-format -n *.c *.h
	rm -rf .clang-format
