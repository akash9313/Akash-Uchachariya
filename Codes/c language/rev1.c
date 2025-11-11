#include <stdio.h>

int increasing(int n) 
{
    int count = 0;
    int arr[10]; 

    while (n > 0) 
    {
        arr[count++] = n % 10;
        n /= 10;
    }

    for (int i = 0; i < count; i++) 
    {
        for (int j = i + 1; j < count; j++) 
        {
            if (arr[j] < arr[i]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int num = 0;
    for (int i = 0; i < count; i++) 
    {
        num = num * 10 + arr[i];
    }
    return num;
}

int decreasing(int n) 
{
    int count = 0;
    int arr[10]; 

    while (n > 0) 
    {
        arr[count++] = n % 10;
        n /= 10;
    }

    for (int i = 0; i < count; i++) 
    {
        for (int j = i + 1; j < count; j++) 
        {
            if (arr[j] > arr[i]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int num = 0;
    for (int i = 0; i < count; i++) 
    {
        num = num * 10 + arr[i];
    }
    return num;
}

int main() 
{
    int x;
    printf("Enter a natural number: ");
    scanf("%d", &x);

    int num1 = increasing(x);
    printf("Number in increasing order: %d\n", num1);

    int num2 = decreasing(x);
    printf("Number in decreasing order: %d\n", num2);

    while (1) 
    {
        int y = increasing(x);
        int z = decreasing(x);

        int new_x = z - y;
        printf("%d - %d = %d\n", z, y, new_x);
        
        if (new_x == x) 
        {
            break;
        }
        x = new_x;
    }

    printf("%d is the Kaprekar's constant.\n", x);
    return 0;
}
