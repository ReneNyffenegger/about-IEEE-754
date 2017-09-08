#include <float.h>
#include <stdio.h>

#include "represent-ieee-754.h"

int main() {

  double d = 1;

  ieee_754_double_representation r;
  while (d != d/2) {
    represent_ieee_754_double(d, r);
    printf("%1024.1022f %s\n", d, r);

    d = d/2;
  }


//represent_ieee_754_double(min_d, r);
//printf("min_d  : %s\n", r);

  represent_ieee_754_double(DBL_MIN, r);
//printf("DBL_MIN: %s\n", r);

//represent_ieee_754_double(DBL_MIN*2, r);
//printf("DBL_MIN: %s\n", r);

  double x=DBL_MIN;
//while (x<=1) {
    printf("%1024.1022f %s\n", x, r);
//  x*=2;
//}
}
