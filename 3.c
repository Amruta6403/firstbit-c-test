
#include <stdio.h>

int main() {
    int a[100], n, i;
    int largest, smallest;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid array size");
        return 0;
    }

    printf("Enter array elements: ");

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    largest = a[0];
    smallest = a[0];

    for (i = 1; i < n; i++) {

        if (a[i] > largest) {
            largest = a[i];
        }

        if (a[i] < smallest) {
            smallest = a[i];
        }
    }

    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);

    return 0;
}
