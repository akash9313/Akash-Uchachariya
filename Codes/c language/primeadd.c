#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    if (n % 2 != 0 && n > 5) {
        int found = 0;
        for (int i = 2; i < n; i++) {
            if (!isPrime(i)) continue;
            for (int j = 2; j < n; j++) {
                if (!isPrime(j)) continue;
                for (int k = 2; k < n; k++) {
                    if (!isPrime(k)) continue;
                    if (i + j + k == n) {
                        printf("%d + %d + %d = %d\n", i, j, k, n);
                        found = 1;
                    }
                }
            }
        }
        if (!found) {
            printf("No combinations found.\n");
        }
    } else {
        printf("Entered number is invalid\n");
    }

    return 0;
}
