#include "math-lib.h"

int isPrime(int a)
{
    for(int i=2;i<a;i++)
    {
	if(a%i==0)
	{
	 return 0; 
	}
    }
    return 1;
}

int ml_nextPrime(int n1)
// return the prime number >= n1
{
    int i=n1;
    while(1)
    {
	if(isPrime(i))
	{ return i;
	  break;
	}
        i++;
    }
    return 0;
}

