#include<stdio.h>

void set(int set1[10],int set2[10],int set3[10])
{
    for (int i = 0; i < 10; i++) 
    {
        if (set1[i] == set2[i]) 
        {
            printf("1");
        } 
        else 
        {
            printf("0");
        }
    }
    printf("\n");

    for (int i = 0; i < 10; i++) 
    {
        if (set1[i] == set3[i-2]) 
        {
            printf("1");
        } 
        else 
        {
            printf("0");
        }
    }
    printf("\n");
}
int main()
{
    int set1[10] = {1,2,3,4,5,6,7,8,9,10};
    int set2[10] = {1,2,3};
    int set3[10] = {3,4,5};

    set(set1,set2,set3);

return 0;
}