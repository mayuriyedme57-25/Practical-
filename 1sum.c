#include <stdio.h>

int main() {
    int n, i;
    int evenSum = 0, oddSum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (i % 2 == 0)
            evenSum += arr[i];  // index 0,2,4,... (even positions)
        else
            oddSum += arr[i];   // index 1,3,5,... (odd positions)
    }

    printf("\nSum of numbers at even positions = %d", evenSum);
    printf("\nSum of numbers at odd positions  = %d\n", oddSum);

    return 0;
}
