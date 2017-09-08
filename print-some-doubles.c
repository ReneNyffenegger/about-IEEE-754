#include <math.h>
#include <float.h>
#include <stdio.h>

#include "represent-ieee-754.h"

void print_double_as_binary(double d) {

  ieee_754_double_representation r;
  represent_ieee_754_double(d, r);

  printf("%12.6f %s\n", d, r);

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

  return 0;

}
