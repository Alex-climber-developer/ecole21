FLAGS=-c -Wall -Werror -Wextra

all: s21_math.a

# s21_math: s21_math.o
# 	gcc s21_math.o -o s21_math

s21_math.a:
	gcc s21_math.c -c -o s21_math
# gcc $(FLAGS) s21_math.c
	ar rc lib_s21_math.a s21_math.o
	ranlib lib_s21_math.a

clean:
	rm -rf *.o
	rm -rf s21_math

re:
	Make clean
	Make

test: test_math.o
	gcc test_math.o -o test_math
test_math.o: test_math.c
	gcc $(FLAGS) test_math.c

check:
	cppcheck *.c *.h
	cp ../../materials/linters/.clang-format ./
	clang-format -n *.c *.h
	rm -rf .clang-format
