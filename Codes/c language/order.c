#include<stdio.h>

int main()
{
    int num[5];
    printf("Enter five numbers : \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&num[i]);
    }
    int ascend = 0;
    int descend = 0;
    
    for (int i = 0; i < 4; i++)
    {
        if(num[i]>num[i+1])
        {
            descend = descend + 1;
        }
        if(num[i]<num[i+1])
        {
            ascend = ascend + 1;
        }
    }   
    if(ascend == 4){
        printf(" array is ascending ");

    }
    else if(descend == 4){
        printf(" array is descending ");

    }
    else 
    {
        printf("Neither ascending nor descending");
    }
    
    return 0;
}