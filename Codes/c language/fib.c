 #include<stdio.h>

int main()
{
 int n;
 int x = 0;
 int y = 1;

printf("enter number: ");
scanf("%d",&n);
printf("%d\n%d\n",x,y);

for(int i=1;i<=n;i++)
{
 int z = x +y;
x=y;
y=z;
 printf("%d\t ",z);
 
 printf("%.2f   \n",(float)y/(float)x );
}
return 0;
} 
