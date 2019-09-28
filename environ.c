#include<stdio.h>
#include<stdlib.h>
extern char **environ;
int main()
{
printf("\n Environment variables passed are:\n");
for(int i=0;environ[i]!=NULL;i++)
{
printf("environ[%d]:%s\n",i,environ[i]);
sleep(100);
}
return 0;
}
