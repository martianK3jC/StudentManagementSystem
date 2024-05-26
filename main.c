#include <stdio.h>

int main() {
    int n, i, j, spaces;

    printf("Enter the number: ");
    scanf("%d", &n);

    // Calculate maximum number of spaces needed
    spaces = n * (n + 1) / 2;

    for (i = 1; i <= n; i++) {
        // Print leading spaces
        for (j = 1; j <= spaces - i * (i + 1) / 2; j++) {
            printf(" ");
        }

        // Print numbers from 1 to i
        for (j = 1; j <= i; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }

    return 0;
}
