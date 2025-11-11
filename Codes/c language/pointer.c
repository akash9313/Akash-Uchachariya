#include<stdio.h>

int main()
{
   int integer1, integer2, integer3;
   printf("Enter three integers : \n");
   scanf("%d",&integer1);
   scanf("%d",&integer2);
   scanf("%d",&integer3);


   if (integer1>integer2 && integer1>integer3)
    {
        printf("Maximum no. is : %d",integer1);
    }
    else if (integer2>integer1 && integer2>integer3)
    {
        printf("Maximum no. is : %d",integer2);
    }
    else if (integer3>integer2 && integer3>integer1)
    {
        printf("Maximum no. is : %d",integer3);
    }
    else
    {
        printf("no defualt value");
    }
    return 0;
}