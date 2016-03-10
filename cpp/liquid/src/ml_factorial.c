#include "math-lib.h"

int ml_factorial(int n1)
// n1 >= 0. No need of error checking!
// Compute the n1!
{
	long int f = 1;
	for(int i=1;i<=n1;i++)
	{
		f *= i;
	}

    return f;
}
