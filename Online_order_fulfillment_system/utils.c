#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

int getValidatedChoice() {
    char input[10];
    int choice;
    while (1) {
        printf("Enter your choice: ");
        if (!fgets(input, sizeof(input), stdin))
            continue;

        input[strcspn(input, "\n")] = '\0';
        int isValid = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                isValid = 0;
                break;
            }
        }

        if (!isValid) {
            printf(" Invalid input! Enter a number between 1 and 8.\n");
            continue;
        }

        choice = atoi(input);
        if (choice < 1 || choice > 8) {
            printf(" Invalid choice. Enter between 1 and 8.\n");
            continue;
        }

        return choice;
    }
}

int getValidatedInt(const char *prompt) {
    char input[20];
    int value;

    while (1) {
        printf("%s", prompt);
        if (!fgets(input, sizeof(input), stdin))
            continue;

        input[strcspn(input, "\n")] = '\0';
        int isValid = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                isValid = 0;
                break;
            }
        }

        if (!isValid) {
            printf(" Enter a positive integer.\n");
            continue;
        }

        value = atoi(input);
        if (value <= 0) {
            printf(" Value must be > 0.\n");
            continue;
        }

        return value;
    }
}

void getValidatedName(const char *prompt, char *name, size_t size) {
    while (1) {
        printf("%s", prompt);
        if (!fgets(name, size, stdin))
            continue;

        name[strcspn(name, "\n")] = '\0';
        int isValid = 1;

        if (strlen(name) == 0) {
            printf(" Name cannot be empty.\n");
            continue;
        }

        for (int i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i]) && name[i] != ' ') {
                isValid = 0;
                break;
            }
        }

        if (!isValid) {
            printf(" Invalid name! Use alphabets and spaces only.\n");
            continue;
        }

        break;
    }
}
