#include "math-lib.h"

int ml_gcd(int n1, int n2)
// Compute the GCD(n1, n2)
{
   	int r;
	while(1){
		r=n1%n2;
		if(r==0)
			return n2;
		n1=n2;
		n2=r;
	}
	 return 0;
}

