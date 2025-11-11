#include<stdio.h>

int main()
{
    int years;
    printf("Enter year : ");
    scanf("%d",&years);

        if(years % 4 == 0)
        {
            printf("Entered year is leap year\n",years);
        }
        else if(years % 400 == 0)           
        {
            printf("Entered year is leap year",years);
        }
        else if(years % 100 == 0)
        {
            printf("Entered year is not leap year",years);
        }
        else
        {
            printf("Entered year is not leap year");
        }

    return 0;
}