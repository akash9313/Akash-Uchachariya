#include <stdio.h>
#include <math.h>

// Function to check if a number is a Ramanujan number
int isRamanujan(int n) {
    int count = 0;
    for (int a = 1; a <= cbrt(n); a++) {
        for (int b = a + 1; b <= cbrt(n); b++) {
            if (a * a * a + b * b * b == n) {
                count++;
                if (count == 2) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    printf("Ramanujan numbers up to %d are:\n", limit);
    for (int i = 1; i <= limit; i++) {
        if (isRamanujan(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
