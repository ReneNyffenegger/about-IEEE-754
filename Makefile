
all: print-some-doubles min-double

print-some-doubles: print-some-doubles.o represent-ieee-754.o
	gcc -Wall -Wextra print-some-doubles.o represent-ieee-754.o -o print-some-doubles

min-double: min-double.o represent-ieee-754.o
	gcc -Wall -Wextra min-double.o represent-ieee-754.o -o min-double

print-some-doubles.o: print-some-doubles.c represent-ieee-754.h
	gcc -Wall -Wextra -c print-some-doubles.c -o print-some-doubles.o

min-double.o: min-double.c represent-ieee-754.h
	gcc -Wall -Wextra -c min-double.c -o min-double.o

represent-ieee-754.o: represent-ieee-754.c represent-ieee-754.h
	gcc -Wall -Wextra -c represent-ieee-754.c -o represent-ieee-754.o

