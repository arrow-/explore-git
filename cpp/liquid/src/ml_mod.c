#include "math-lib.h"

int ml_mod(int n1, int n2)
// Compute the remainder when n1 divides n2 (n1 % n2)
// You cannot use the % operator.
{
 int mod,q;
	q=n1/n2;
	mod=n1-(n2*q);
   return mod;
}
