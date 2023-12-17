// password_manager.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

void encryptPassword(char *password) {
    // You can implement a proper encryption algorithm here.
    // For simplicity, this example just prints the encrypted password.
    printf("Encrypted Password: %s\n", password);
}

void storePassword(const char *username, const char *password) {
    encryptPassword(password);

    // In a real scenario, you'd want to securely store this information, maybe in a file or database.
    FILE *file = fopen("passwords.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %s\n", username, password);
        fclose(file);
        printf("Password for %s stored successfully.\n", username);
    } else {
        printf("Error opening file.\n");
    }
}

void retrievePassword(const char *username) {
    // In a real scenario, you'd retrieve this information securely from your storage.
    FILE *file = fopen("passwords.txt", "r");
    if (file != NULL) {
        char storedUsername[MAX_USERNAME_LENGTH];
        char storedPassword[MAX_PASSWORD_LENGTH];

        while (fscanf(file, "%s %s", storedUsername, storedPassword) != EOF) {
            if (strcmp(username, storedUsername) == 0) {
                printf("Retrieved Password: %s\n", storedPassword);
                fclose(file);
                return;
            }
        }

        fclose(file);
        printf("Username not found.\n");
    } else {
        printf("Error opening file.\n");
    }
}

int main() {
    const char *username = "user1";
    const char *password = "secret123";

    storePassword(username, password);
    retrievePassword(username);

    return 0;
}

