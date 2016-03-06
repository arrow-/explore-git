#include "math-lib.h"
#include <iostream>
#include <string>

using namespace std;

int main(int agrc, char *argv[]){
	int M, i, j;
	double n1, n2, n3, res;
	string response;
	cin>>M;
	switch (M){
		case 0: //add
			cin>>n1>>n2;
			res = ml_add(n1, n2);
			break;
		case 1: //mul
		    cin>>n1>>n2;
			res = ml_mul(n1, n2);
			break;
		case 2: //div
		    cin>>n1>>n2;
			res = ml_div(n1, n2);
			break;
		case 3: //sub
		    cin>>n1>>n2;
			res = ml_sub(n1, n2);
			break;
        case 4://power
            cin>>n1>>n2;
            res = ml_power(n1, n2);
            break;
	}
	cout<<": "<<res<<endl;
}
