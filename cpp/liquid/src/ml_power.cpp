#include "math-lib.h"

double ml_power(double n1, double n2)
{
    double result;

    if(n2==0)
    {
        return 1;
    }
    else if(n2>0)
    {
        result=1;

        for(int i=0;i<n2;i++)
        {
            result*=n1;
        }

        return result;
    }
    else
    {
        result=1;

        for(int i=0;i<-1*n2;i++)
        {
            result*=n1;
        }
        return 1/result;
    }
}
