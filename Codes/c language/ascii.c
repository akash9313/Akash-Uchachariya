#include <stdio.h>

int main() 
{
    int ascii = 0;
    while (ascii <= 255) 
    {
        printf("%d = %c        ", ascii, ascii);
        if (ascii % 10 == 9) { 
            printf("\n");
        }
        ascii++;
    }
    return 0;
}
