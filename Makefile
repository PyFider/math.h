c89:
	clang -O3 main.c -o bin/math -std=c89
c99:
	clang -O3 main.c -o bin/math -std=c99
c11:
	clang -O3 main.c -o bin/math -std=c11
c17:
	clang -O3 main.c -o bin/math -std=c17

test_std_math:
	clang -O3 test.c -o test -std=c89 -lm
