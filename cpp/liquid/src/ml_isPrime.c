#include "math-lib.h"

int ml_isPrime(int n1)
// return 1 if n1 is prime.
{	int i=2,flag=0;
	for(;i<n1;i++)
		if(n1%i==0)
			flag=1;
		
	if(flag==1)
		return 0;
	else
		return 1;
}

