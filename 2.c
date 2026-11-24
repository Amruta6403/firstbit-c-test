
#include <stdio.h>

int main() {
    int n, original, digit;
    int fact, sum = 0, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Negative numbers are not Strong Numbers.");
        return 0;
    }

    original = n;

    do {
        digit = n % 10;
        fact = 1;

        for (i = 1; i <= digit; i++) {
            fact = fact * i;
        }

        sum = sum + fact;
        n = n / 10;

    } while (n > 0);

    if (sum == original) {
        printf("%d is a Strong Number.", original);
    } else {
        printf("%d is not a Strong Number.", original);
    }

    return 0;
}
