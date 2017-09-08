#include <ieee754.h>

#include "represent-ieee-754.h"

struct D {
  unsigned char pos;
  unsigned char cnt;
  char*    representation;
};

void add_char(char c, struct D *d) {

  d->representation[d->pos] = c;
  d->pos++;

}

void add_repr_char(char c, struct D *d) {

  add_char(c, d);

  d->cnt++;

  if (! (d->cnt % 8)) {
    add_char(' ', d);
    add_char('|', d);
    add_char(' ', d);
  }
  else if (! (d->cnt % 4)) {
    add_char(' ', d);
  }


}

void represent_ieee_754_double(double d, ieee_754_double_representation r) {

  union ieee754_double dd;

  dd.d = d;
  struct D dr;
  dr.cnt=0;
  dr.pos=0;
  dr.representation = r;
//dr.representation[IEEE_755_DOUBLE_REPRESENTATION_SIZE] = 0x00;

  if (dd.ieee.negative) {
    add_repr_char('S', &dr);
  }
  else {
    add_repr_char('.', &dr);
  }

  for (unsigned i=1<<10; i >= 1; i>>=1) {
    if    (dd.ieee.exponent & i) { add_repr_char('E', &dr); }
    else                         { add_repr_char('.', &dr); }
  }


  for (unsigned long int i=1u<<19; i>=1 ; i>>=1) {
    if   (dd.ieee.mantissa0 & i) { add_repr_char('M', &dr); }
    else                         { add_repr_char('.', &dr); }
  }

  for (unsigned long int i = (1u<<31); i>= 1 ; i>>=1) {
    if   (dd.ieee.mantissa1 & i) { add_repr_char('M', &dr); }
    else                         { add_repr_char('.', &dr); }
  }
  add_char(0x00, &dr);

}
