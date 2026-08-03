#include <stdio.h>
#include <stdlib.h>

int main() {
    // allocate memory for a single int
    int *p = (int*) malloc(sizeof(int));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    *p = 42;
    printf("Value: %d\n", *p);
    free(p); // free memory

    // allocate memory for an array of 5 ints (zero-initialized)
    int *arr = (int*) calloc(5, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < 5; i++) arr[i] = i * 10;
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr); // free memory

    return 0;
}
