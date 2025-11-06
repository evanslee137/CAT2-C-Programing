#include <stdio.h>
#include <stdlib.h>

// Function to prompt the user to enter 10 integers and store them in "input.txt"
void writeInputFile() {
    FILE *inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        printf("Error: Could not open input.txt for writing.\n");
        exit(1);
    }

    int number;
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Integer %d: ", i + 1);
        if (scanf("%d", &number) != 1) {
            printf("Invalid input. Exiting.\n");
            fclose(inputFile);
            exit(1);
        }
        fprintf(inputFile, "%d\n", number);
    }

    fclose(inputFile);
}

// Function to read integers from "input.txt",find sum and average, and write to "output.txt"
void processFile() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input.txt for reading.\n");
        exit(1);
    }

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output.txt for writing.\n");
        fclose(inputFile);
        exit(1);
    }

    int number, sum = 0, count = 0;
    while (fscanf(inputFile, "%d", &number) == 1) {
        sum += number;
        count++;
    }

    if (count == 0) {
        printf("No numbers found in input.txt.\n");
        fclose(inputFile);
        fclose(outputFile);
        exit(1);
    }

    double average = (double)sum / count;

    fprintf(outputFile, "Sum: %d\n", sum);
    fprintf(outputFile, "Average: %.2f\n", average);

    fclose(inputFile);
    fclose(outputFile);
}

// Function to read and show contents of both files in formatted manner
void displayFiles() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input.txt for reading.\n");
        exit(1);
    }

    FILE *outputFile = fopen("output.txt", "r");
    if (outputFile == NULL) {
        printf("Error: Could not open output.txt for reading.\n");
        fclose(inputFile);
        exit(1);
    }

    int number;
    printf("\nContents of input.txt:\n");
    printf("----------------------\n");
    while (fscanf(inputFile, "%d", &number) == 1) {
        printf("%d\n", number);
    }

    char line[100];
    printf("\nContents of output.txt:\n");
    printf("-----------------------\n");
    while (fgets(line, sizeof(line), outputFile) != NULL) {
        printf("%s", line);
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    writeInputFile();
    processFile();
    displayFiles();

    return 0;
}