#include <stdio.h>
#include <stdlib.h>

// Function to write data to a file (creates or overwrites)
void writeFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }

    char data[200];
    printf("Enter text to write to the file:\n");
    getchar(); // consume leftover newline
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    fclose(fp);
    printf("Data written to '%s' successfully.\n", filename);
}

// Function to append data to an existing file
void appendFile(const char *filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error opening file for appending");
        return;
    }

    char data[200];
    printf("Enter text to append to the file:\n");
    getchar(); // consume leftover newline
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    fclose(fp);
    printf("Data appended to '%s' successfully.\n", filename);
}

// Function to read and display file content
void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return;
    }

    char ch;
    printf("\nContents of '%s':\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
    printf("\nEnd of file.\n");
}

// Main program demonstrating menu-driven file operations
int main() {
    char filename[100];
    int choice;

    printf("Enter the filename to operate on: ");
    scanf("%s", filename);

    do {
        printf("\nFile Operations Menu:\n");
        printf("1. Write to file (create/overwrite)\n");
        printf("2. Append to file\n");
        printf("3. Read from file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeFile(filename);
                break;
            case 2:
                appendFile(filename);
                break;
            case 3:
                readFile(filename);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);
return 0;
}