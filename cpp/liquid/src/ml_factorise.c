#include "math-lib.h"

int ml_factorise(int n1, int *factors, int *exponent){
/*
	n1         > 0
	factors    is an array of ints, initiallised to ALL ZERO {size = 120}
	exponent   is an array of ints, initiallised to ALL ZERO {size = 120}
 The arrays must look like:
 {2, 3, 5, 19}
 {1, 1, 1, 2}
 Order is not important. Your primes might be in any jumbled order, exponent and facor must match.
 Feel free to contact a volunteer if you have doubts!
 
 NOT LIKE
 {1, 2, 3, 5, 7, 9, ... , 19, 23, ...., 113, ...}
 {1, 1, 1, 1, 0, 0, ... ,  1,  0, ....,   0, ...}
 
 Return 0 if operation failed, else 1
*/
	factors[0] = 3;
	exponent[0] = 1;
	factors[1] = 78;
	exponent[1] = 1;
	factors[2] = 31;
	exponent[2] = 1;
	return 1;
}
