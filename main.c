#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USERNAME_LEN 20
#define PASSWORD_LEN 20

typedef struct Car {
    char model[30];
    char brand[30];
    float price;
    int isAvailable;
    struct Car* next;
} Car;

typedef struct User {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    struct User* next;
} User;

Car* carList = NULL;
User* userList = NULL;
User* loggedInUser = NULL;

void initializeCars();
void registerUser();
void loginUser();
void displayCars();
void rentCar();
void returnCar();
void logoutUser();
void exitProgram();

int main() {
    int choice;
    initializeCars();

    do {
        printf("\n--- Car Rental System ---\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void initializeCars() {
    Car* car1 = (Car*)malloc(sizeof(Car));
    strcpy(car1->model, "Model S");
    strcpy(car1->brand, "Tesla");
    car1->price = 100.0;
    car1->isAvailable = 1;
    car1->next = NULL;

    Car* car2 = (Car*)malloc(sizeof(Car));
    strcpy(car2->model, "Mustang");
    strcpy(car2->brand, "Ford");
    car2->price = 80.0;
    car2->isAvailable = 1;
    car2->next = NULL;

    Car* car3 = (Car*)malloc(sizeof(Car));
    strcpy(car3->model, "Civic");
    strcpy(car3->brand, "Honda");
    car3->price = 50.0;
    car3->isAvailable = 1;
    car3->next = NULL;

    Car* car4 = (Car*)malloc(sizeof(Car));
    strcpy(car4->model, "Camry");
    strcpy(car4->brand, "Toyota");
    car4->price = 60.0;
    car4->isAvailable = 1;
    car4->next = NULL;

    Car* car5 = (Car*)malloc(sizeof(Car));
    strcpy(car5->model, "Accord");
    strcpy(car5->brand, "Honda");
    car5->price = 70.0;
    car5->isAvailable = 1;
    car5->next = NULL;

    Car* car6 = (Car*)malloc(sizeof(Car));
    strcpy(car6->model, "Corvette");
    strcpy(car6->brand, "Chevrolet");
    car6->price = 120.0;
    car6->isAvailable = 1;
    car6->next = NULL;

    car1->next = car2;
    car2->next = car3;
    car3->next = car4;
    car4->next = car5;
    car5->next = car6;
    carList = car1;
}

void registerUser() {
    User* newUser = (User*)malloc(sizeof(User));
    printf("Enter username: ");
    fgets(newUser->username, USERNAME_LEN, stdin);
    newUser->username[strcspn(newUser->username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(newUser->password, PASSWORD_LEN, stdin);
    newUser->password[strcspn(newUser->password, "\n")] = '\0';

    newUser->next = userList;
    userList = newUser;
    printf("Registration successful!\n");
}

void loginUser() {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];

    printf("Enter username: ");
    fgets(username, USERNAME_LEN, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(password, PASSWORD_LEN, stdin);
    password[strcspn(password, "\n")] = '\0';

    User* currentUser = userList;
    while (currentUser != NULL) {
        if (strcmp(currentUser->username, username) == 0 && strcmp(currentUser->password, password) == 0) {
            loggedInUser = currentUser;
            printf("Login successful!\n");
            int choice;

            do {
                printf("\n--- User Menu ---\n");
                printf("1. Display Cars\n");
                printf("2. Rent a Car\n");
                printf("3. Return a Car\n");
                printf("4. Logout\n");
                printf("5. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                getchar();

                switch (choice) {
                    case 1:
                        displayCars();
                        break;
                    case 2:
                        rentCar();
                        break;
                    case 3:
                        returnCar();
                        break;
                    case 4:
                        logoutUser();
                        break;
                    case 5:
                        exitProgram();
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            } while (choice != 4 && choice != 5);
            return;
        }
        currentUser = currentUser->next;
    }
    printf("Invalid username or password.\n");
}

void displayCars() {
    printf("\n--- Available Cars ---\n");
    Car* currentCar = carList;
    int count = 1;

    while (currentCar != NULL) {
        if (currentCar->isAvailable) {
            printf("Car Number: %d - %s %s - $%.2f per day\n", count, currentCar->brand, currentCar->model, currentCar->price);
        }
        currentCar = currentCar->next;
        count++;
    }
}

void rentCar() {
    int carNumber;
    printf("Enter the car number to rent: ");
    scanf("%d", &carNumber);
    getchar();

    Car* currentCar = carList;
    int count = 1;

    while (currentCar != NULL) {
        if (count == carNumber) {
            if (currentCar->isAvailable) {
                currentCar->isAvailable = 0;
                printf("You have successfully rented the %s %s.\n", currentCar->brand, currentCar->model);
            } else {
                printf("Sorry, the car is not available.\n");
            }
            return;
        }
        currentCar = currentCar->next;
        count++;
    }

    printf("Invalid car number.\n");
}

void returnCar() {
    int carNumber;
    printf("Enter the car number to return: ");
    scanf("%d", &carNumber);
    getchar();

    Car* currentCar = carList;
    int count = 1;

    while (currentCar != NULL) {
        if (count == carNumber) {
            if (!currentCar->isAvailable) {
                currentCar->isAvailable = 1;
                printf("You have successfully returned the %s %s.\n", currentCar->brand, currentCar->model);
            } else {
                printf("This car was not rented.\n");
            }
            return;
        }
        currentCar = currentCar->next;
        count++;
    }

    printf("Invalid car number.\n");
}

void logoutUser() {
    loggedInUser = NULL;
    printf("You have logged out successfully.\n");
}

void exitProgram() {
    printf("Exiting the program. Goodbye!\n");

    Car* currentCar = carList;
    while (currentCar != NULL) {
        Car* temp = currentCar;
        currentCar = currentCar->next;
        free(temp);
    }

    User* currentUser = userList;
    while (currentUser != NULL) {
        User* temp = currentUser;
        currentUser = currentUser->next;
        free(temp);
    }

    exit(0);
}
