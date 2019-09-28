#include<iostream>
#include "functions.h"

int factorial(int n)
{
int fac=1;
for(int i=n;i>0;i--)
{
fac=fac*i;
}
return fac;
}
