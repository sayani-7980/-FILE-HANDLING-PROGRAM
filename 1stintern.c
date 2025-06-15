#include <stdio.h>
#include <stdlib.h>

void writeToFile(const char *filename) {
    FILE *fp = fopen(filename, "w"); // Create or overwrite
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    char data[100];
    printf("Enter data to write to the file: ");
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    fclose(fp);
    printf("Data written successfully.\n");
}

void appendToFile(const char *filename) {
    FILE *fp = fopen(filename, "a"); // Append mode
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }

    char data[100];
    printf("Enter data to append to the file: ");
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    fclose(fp);
    printf("Data appended successfully.\n");
}

void readFromFile(const char *filename) {
    FILE *fp = fopen(filename, "r"); // Read mode
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char ch;
    printf("File content:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
}

int main() {
    char filename[50] = "example.txt";
    int choice;

    do {
        printf("\nFile Operations Menu:\n");
        printf("1. Write to file (create/overwrite)\n");
        printf("2. Append to file\n");
        printf("3. Read from file\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // To consume newline after scanf

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                appendToFile(filename);
                break;
            case 3:
                readFromFile(filename);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
return 0;
}
