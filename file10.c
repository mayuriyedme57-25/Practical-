#include <stdio.h>

int main() {
    FILE *source, *destination;
    char ch;

    source = fopen("input.txt", "r");   // open input file for reading
    destination = fopen("output.txt", "w");  // open output file for writing

    if (source == NULL || destination == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File copied successfully.\n");

    fclose(source);
    fclose(destination);

    return 0;
}