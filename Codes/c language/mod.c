#include<stdio.h>

int mod(int n, int m)
{
int mod = n % m;

return mod;
}

int main()
{
int n,m;
printf("Enter n and m : ");
scanf("%d %d",&n,&m);

printf("Reminder is : %d\n",mod(n,m));
return 0;

}