#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef enum { FALSE, TRUE } Bool;

typedef union {
    Bool isActive;
    int flagValue;  // to allow any integer value for the flag
} UserFlag;

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    UserFlag flag;
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum user limit reached.\n");
        return;
    }

    User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    printf("Enter password: ");
    scanf("%s", newUser.password);

    printf("Set user active status (1 for true, 0 for false): ");
    scanf("%d", &newUser.flag.flagValue);

    users[userCount++] = newUser;

    printf("Registration successful.\n");
}

int loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    for (int i = 0; i < userCount; i++) {
        User user = users[i];
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            if (user.flag.isActive) {
                printf("Login successful. HELLO, %s!\n", user.username);
                return 1;
            } else {
                printf("User is not active. Cannot log in.\n");
                return 0;
            }
        }
    }
    printf("Invalid user or pass.\n");
    return 0;
}

int main() {
    int choice;
    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser())
                    return 0;  
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (1);

    return 0;
}

