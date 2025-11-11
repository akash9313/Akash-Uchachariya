#include <stdio.h>

void set(int set1[], int set2[], int n) 
{
    for (int i = 0; i < n; i++) 
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
}

int main() 
{
    int n;
    printf("Enter the size of set1: ");
    scanf("%d", &n);

    int set1[n];
    printf("Enter the numbers in set1: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set1[i]);
    }

    int set2[3];
    printf("Enter the numbers in set2: ");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &set2[i]);
    }

    set(set1, set2, n);

    return 0;
}
