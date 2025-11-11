#include<stdio.h>
int main()
{
    float sal;

    printf("Enter the salary : \n");
    scanf("%0.2f",&sal);

    sal >= 25000 && sal <= 40000 ? printf("Manager\n") :
    sal >= 15000 && sal < 25000 ? printf("Accoutant\n") :
    printf("Clerk\n");

return 0;
}

