#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int gvar=555;
int main()
{
int lvar=54;
int cpid=fork();
if(cpid==0)
printf("hello i am child with PID=%ld,gvar=%d,lvar=%d \n",(long)getpid(),gvar,lvar);
else
printf("hello i am parent with PID=%ld,gvar=%d,lvar=%d \n",(long)getpid(),gvar,lvar);
return 0;
}
