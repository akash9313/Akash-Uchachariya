#include<stdio.h> 

int main()
{
    int n;
    printf("Enter that how many numbers do you want to enter : ");
    scanf("%d",&n);

    int num;
    printf("Enter that number : ");
    scanf("%d",&num);

    int sum = 0;
    for (int i = num;i>0; i=i/10)
    {
        sum = sum + i%10;
    }

    float avg = (float)sum/(float)n;
    printf("Sum and average of these numbers are %d and %0.2f",sum,avg);
    

return 0;
}