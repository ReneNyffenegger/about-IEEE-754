
all: print-some-doubles min-double nextafter

print-some-doubles: print-some-doubles.o represent-ieee-754.o
	gcc -Wall -Wextra print-some-doubles.o represent-ieee-754.o -o print-some-doubles

min-double: min-double.o represent-ieee-754.o
	gcc -Wall -Wextra min-double.o represent-ieee-754.o -o min-double

nextafter: nextafter.o represent-ieee-754.o
	gcc -Wall -Wextra nextafter.o represent-ieee-754.o -o nextafter -lm

print-some-doubles.o: print-some-doubles.c represent-ieee-754.h
	gcc -Wall -Wextra -c print-some-doubles.c -o print-some-doubles.o

min-double.o: min-double.c represent-ieee-754.h
	gcc -Wall -Wextra -c min-double.c -o min-double.o

represent-ieee-754.o: represent-ieee-754.c represent-ieee-754.h
	gcc -Wall -Wextra -c represent-ieee-754.c -o represent-ieee-754.o

nextafter.o: nextafter.c represent-ieee-754.h
	gcc -Wall -Wextra -c nextafter.c -o nextafter.o

