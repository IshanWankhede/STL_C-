#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *line = NULL;   // start with NULL
    size_t len = 0;      // buffer size starts at 0

    printf("Enter a line: ");
    getline(&line, &len, stdin);   // getline allocates memory

    // remove newline at the end
    line[strcspn(line, "\n")] = '\0';

    printf("You entered: %s\n", line);

    free(line); // free memory allocated by getline
    return 0;
}
