#include <stdio.h>
#include <math.h>

#include "represent-ieee-754.h"

int main() {

   ieee_754_double_representation r;

   double d = 0; represent_ieee_754_double(d, r);
   
   printf("\nWe start with the representation of the double 0:\n");
   printf("    %s\n", r);

   d=nextafter(d, INFINITY); represent_ieee_754_double(d, r);
   printf("\nThe next higher representable double just increases the value of the");
   printf("\nmantissa by one:\n");
   printf("    %s\n", r);

   d=nextafter(d, INFINITY); represent_ieee_754_double(d, r);
   printf("\nEach call to nextafter() increases the value of the mantissa by one:\n");
   printf("    %s\n", r);

   d=nextafter(d, INFINITY); represent_ieee_754_double(d, r);
   printf("\nAgain...:\n");
   printf("    %s\n", r);

   d=nextafter(1.0/pow(2, 1022), -INFINITY);
   printf("\nWe can continue to increase the mantissa until all bits of the");
   printf("\nmantissa are set:\n");
   represent_ieee_754_double(d, r); printf("    %s\n", r);

   d=nextafter(d, INFINITY); represent_ieee_754_double(d, r);
   printf("\nNow, increasing the double to the next representable value clears");
   printf("\nall mantiassa bits and increases the exponent value by one:\n");
   printf("    %s\n", r);

   d=nextafter(d, INFINITY); represent_ieee_754_double(d, r);
   printf("\nThe increasing of the mantissa value starts over:\n");
   printf("    %s\n", r);

   d=nextafter(1.0/pow(2, 1021), -INFINITY); represent_ieee_754_double(d, r);
   printf("\nUntil all mantissa bits are set again:\n");
   printf("    %s\n", r);

   d=nextafter(d, INFINITY); represent_ieee_754_double(d, r);
   printf("\nAfter which the mantissa value is reset to 0 and the");
   printf("\nexponent value is increased by one:\n");
   printf("    %s\n", r);

}
