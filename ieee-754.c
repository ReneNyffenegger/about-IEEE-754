#include <stdio.h>
#include <string.h>
#include <float.h>
#include <math.h>

#include <ieee754.h>

void put_char(char* c, int* cnt) {

  printf(c);

  ++*cnt;

  if (! (*cnt % 8)) {
    printf(" | ");
  }
  else if (! (*cnt % 4)) {
    printf("  ");
  }

}

void print_double_as_binary(double d) {

  int cnt = 0;

  union ieee754_double dd;

  printf ("%+20.10f: ", d);

  dd.d = d;

  if (dd.ieee.negative) {
    put_char("S", &cnt);
  }
  else {
    put_char(".", &cnt);
  }

  for (unsigned i=1<<10; i >= 1; i>>=1) {
    if    (dd.ieee.exponent & i) { put_char("E", &cnt); }
    else                         { put_char(".", &cnt); }
  }


  for (unsigned long int i=1u<<19; i>=1 ; i>>=1) {
    if   (dd.ieee.mantissa0 & i) { put_char("M", &cnt); }
    else                         { put_char(".", &cnt); }
  }

  for (unsigned long int i = (1u<<31); i>= 1 ; i>>=1) {
    if   (dd.ieee.mantissa1 & i) { put_char("M", &cnt); }
    else                         { put_char(".", &cnt); }
  }


  printf("\n");

}

int main() {


  print_double_as_binary(  0);
  print_double_as_binary( -0);
  print_double_as_binary(  1);
  print_double_as_binary(  0.5);
  print_double_as_binary(  1.0 + 0.5);
  print_double_as_binary(  1.0 + 0.5 + 0.25);
  print_double_as_binary(  1.0 + 0.5 + 0.25 + 0.125);
  print_double_as_binary(  1.0 + 0.5 + 0.25 + 0.125 + 0.125/2);
  print_double_as_binary(  2*(1.0 + 0.5 + 0.25 + 0.125 + 0.125/2));
  print_double_as_binary(  4*(1.0 + 0.5 + 0.25 + 0.125 + 0.125/2));
  print_double_as_binary(  1*(1.0 + 0.5 + 0.25 + 0.125 + 0.125/2) / pow(2, 1023));
  print_double_as_binary(  2);
  print_double_as_binary(  3);
  print_double_as_binary(  4);
  print_double_as_binary(  8);
  print_double_as_binary( 16);
  print_double_as_binary(- 1);
  print_double_as_binary( 10);
  print_double_as_binary( 1.5/pow(2, 1));
  print_double_as_binary( 1.5/pow(2, 2));
  print_double_as_binary( 1.5/pow(2, 3));
  print_double_as_binary( 250.25); // 11111010.01
  print_double_as_binary( DBL_MIN);
  print_double_as_binary( DBL_MIN * 2);
  print_double_as_binary(  NAN);
  print_double_as_binary(- NAN);
//print_double_as_binary( SNAN);
//print_double_as_binary(-SNAN);
  print_double_as_binary( INFINITY);
  print_double_as_binary(-INFINITY);
  print_double_as_binary( DBL_MAX);

}
