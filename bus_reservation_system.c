#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BUSES 5
#define MAX_SEATS 40
#define MAX_NAME_LENGTH 50
#define MAX_USERS 10

typedef struct {
    int seatNumber;
    char passengerName[MAX_NAME_LENGTH];
    bool isBooked;
} Seat;

typedef struct {
    int busNumber;
    char busName[MAX_NAME_LENGTH];
    Seat seats[MAX_SEATS];
} Bus;

typedef struct {
    char username[MAX_NAME_LENGTH];
    char password[MAX_NAME_LENGTH];
} User;

Bus buses[MAX_BUSES];
User users[MAX_USERS];
int userCount = 0;
char loggedInUser[MAX_NAME_LENGTH] = "";

// Initialize buses with seats
void initializeBuses() {
    for (int i = 0; i < MAX_BUSES; i++) {
        buses[i].busNumber = i + 1;
        snprintf(buses[i].busName, MAX_NAME_LENGTH, "Bus %d", i + 1);

        for (int j = 0; j < MAX_SEATS; j++) {
            buses[i].seats[j].seatNumber = j + 1;
            buses[i].seats[j].isBooked = false;
            strcpy(buses[i].seats[j].passengerName, "");
        }
    }
}

// Register a user
void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }

    char username[MAX_NAME_LENGTH];
    char password[MAX_NAME_LENGTH];

    printf("Enter a username: ");
    scanf("%s", username);
    printf("Enter a password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists. Please choose another.\n");
            return;
        }
    }

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;

    printf("User registered successfully!\n");
}

// Login a user
bool loginUser() {
    char username[MAX_NAME_LENGTH];
    char password[MAX_NAME_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            strcpy(loggedInUser, username);
            printf("Login successful! Welcome, %s.\n", username);
            return true;
        }
    }

    printf("Invalid username or password.\n");
    return false;
}

// Logout a user
void logoutUser() {
    strcpy(loggedInUser, "");
    printf("Logged out successfully.\n");
}

// Display seat status of a bus
void displayBusStatus() {
    int busNumber;
    printf("Enter bus number (1-%d): ", MAX_BUSES);
    scanf("%d", &busNumber);

    if (busNumber < 1 || busNumber > MAX_BUSES) {
        printf("Invalid bus number!\n");
        return;
    }

    Bus *bus = &buses[busNumber - 1];
    printf("\n--- %s Status ---\n", bus->busName);
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("Seat %2d: %s\n", bus->seats[i].seatNumber, bus->seats[i].isBooked ? bus->seats[i].passengerName : "Available");
    }
    printf("---------------------\n\n");
}

// Book a ticket
void bookTicket() {
    int busNumber, seatNumber;
    printf("Enter bus number (1-%d): ", MAX_BUSES);
    scanf("%d", &busNumber);

    if (busNumber < 1 || busNumber > MAX_BUSES) {
        printf("Invalid bus number!\n");
        return;
    }

    Bus *bus = &buses[busNumber - 1];

    printf("Enter seat number to book (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number!\n");
        return;
    }

    if (bus->seats[seatNumber - 1].isBooked) {
        printf("Seat %d is already booked!\n", seatNumber);
        return;
    }

    strcpy(bus->seats[seatNumber - 1].passengerName, loggedInUser);
    bus->seats[seatNumber - 1].isBooked = true;
    printf("Seat %d successfully booked for %s in %s.\n", seatNumber, loggedInUser, bus->busName);
}

// Cancel a ticket
void cancelTicket() {
    int busNumber, seatNumber;
    printf("Enter bus number (1-%d): ", MAX_BUSES);
    scanf("%d", &busNumber);

    if (busNumber < 1 || busNumber > MAX_BUSES) {
        printf("Invalid bus number!\n");
        return;
    }

    Bus *bus = &buses[busNumber - 1];

    printf("Enter seat number to cancel (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number!\n");
        return;
    }

    if (!bus->seats[seatNumber - 1].isBooked) {
        printf("Seat %d is not booked!\n", seatNumber);
        return;
    }

    if (strcmp(bus->seats[seatNumber - 1].passengerName, loggedInUser) != 0) {
        printf("You can only cancel tickets booked under your name.\n");
        return;
    }

    bus->seats[seatNumber - 1].isBooked = false;
    strcpy(bus->seats[seatNumber - 1].passengerName, "");
    printf("Booking for seat %d successfully canceled.\n", seatNumber);
}

// Main menu
void menu() {
    printf("\n--- Bus Reservation System ---\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Display Bus Status\n");
    printf("4. Book a Ticket\n");
    printf("5. Cancel a Ticket\n");
    printf("6. Logout\n");
    printf("7. Exit\n");
    printf("--------------------------------\n");
}

int main() {
    int choice;

    initializeBuses();

    while (true) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loggedInUser[0] != '\0') {
                    printf("You are already logged in as %s. Please log out first.\n", loggedInUser);
                } else {
                    loginUser();
                }
                break;
            case 3:
                if (loggedInUser[0] != '\0') {
                    displayBusStatus();
                } else {
                    printf("Please log in to view bus status.\n");
                }
                break;
            case 4:
                if (loggedInUser[0] != '\0') {
                    bookTicket();
                } else {
                    printf("Please log in to book a ticket.\n");
                }
                break;
            case 5:
                if (loggedInUser[0] != '\0') {
                    cancelTicket();
                } else {
                    printf("Please log in to cancel a ticket.\n");
                }
                break;
            case 6:
                if (loggedInUser[0] != '\0') {
                    logoutUser();
                } else {
                    printf("You are not logged in.\n");
                }
                break;
            case 7:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
