#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure for each passenger
struct Passenger
{
    char name[50];
    int seatNumber;
    struct Passenger *next;
};
// Structure for each flight
struct Flight
{
    char flightNumber[10];
    char destination[50];
    int capacity;
    int booked;
    struct Passenger *passengers;
    struct Flight *left;
    struct Flight *right;
};
// Function to create a new passenger node
struct Passenger* createPassenger(char name[], int seatNumber)
{
    struct Passenger* newPassenger = (struct Passenger*)malloc(sizeof(struct Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->seatNumber = seatNumber;
    newPassenger->next = NULL;
    return newPassenger;
}
// Function to create a new flight node
struct Flight* createFlight(char flightNumber[], char destination[], int capacity)
{
    struct Flight* newFlight = (struct Flight*)malloc(sizeof(struct Flight));
    strcpy(newFlight->flightNumber, flightNumber);
    strcpy(newFlight->destination, destination);
    newFlight->capacity = capacity;
    newFlight->booked = 0;
    newFlight->passengers = NULL;
    newFlight->left = NULL;
    newFlight->right = NULL;
    return newFlight;
}
// Function to insert a new flight into the tree
struct Flight* insertFlight(struct Flight* root, char flightNumber[], char destination[], int capacity)
{
    if (root == NULL)
    {
        return createFlight(flightNumber, destination, capacity);
    }
    if (strcmp(flightNumber, root->flightNumber) < 0)
    {
        root->left = insertFlight(root->left, flightNumber, destination, capacity);
    }
    else if (strcmp(flightNumber, root->flightNumber) > 0)
    {
        root->right = insertFlight(root->right, flightNumber, destination, capacity);
    }
    return root;
}
// Function to search for a flight by flight number
struct Flight* searchFlight(struct Flight* root, char flightNumber[])
{
    if (root == NULL || strcmp(root->flightNumber, flightNumber) == 0)
    {
        return root;
    }
    if (strcmp(flightNumber, root->flightNumber) < 0)
    {
        return searchFlight(root->left, flightNumber);
    }
    else
    {
        return searchFlight(root->right, flightNumber);
    }
}
// Function to book a seat on a flight
void bookSeat(struct Flight* root, char flightNumber[], char name[])
{
    struct Flight* flight = searchFlight(root, flightNumber);
    if (flight == NULL)
    {
        printf("Flight not found.\n");
    } 
    else
    {
        if (flight->booked < flight->capacity)
        {
            // Increment booked seats
            flight->booked++;
            // Create new passenger node
            struct Passenger* newPassenger = createPassenger(name, flight->booked);
            // Add passenger to the flight's list
            newPassenger->next = flight->passengers;
            flight->passengers = newPassenger;
            printf("Ticket booked successfully on flight %s to %s for %s.\n",flight->flightNumber, flight->destination, name);
        }
        else
        {
            printf("The flight %s to %s is fully booked.\n", flight->flightNumber,flight->destination);
        }
    }
}
// Function to cancel a reservation on a flight
void cancelReservation(struct Flight* root, char flightNumber[], char name[])
{
    struct Flight* flight = searchFlight(root, flightNumber);
    if (flight == NULL)
    {
        printf("Flight not found.\n");
    }
    else
    {
        struct Passenger* currentPassenger = flight->passengers;
        struct Passenger* prevPassenger = NULL;
        // Search for the passenger
        while (currentPassenger != NULL && strcmp(currentPassenger->name, name) !=0)
        {
            prevPassenger = currentPassenger;
            currentPassenger = currentPassenger->next;
        }
        if (currentPassenger != NULL)
        {
            // Remove passenger from the flight's list
            if (prevPassenger != NULL)
            {
                prevPassenger->next = currentPassenger->next;
            }
            else
            {
                flight->passengers = currentPassenger->next;
            }
            // Decrement booked seats
            flight->booked--;
            free(currentPassenger);
            printf("Reservation cancelled successfully for %s on flight %s.\n", name,flight->flightNumber);
        }
        else
        {
            printf("Passenger not found on this flight.\n");
        }
    }
}
// Function to display reservation status and passenger information for a flight
void displayReservationStatus(struct Flight* root, char flightNumber[])
{
    struct Flight* flight = searchFlight(root, flightNumber);
    if (flight == NULL)
    {
        printf("Flight not found.\n");
    }
    else
    {
        printf("Flight %s to %s:\n", flight->flightNumber, flight->destination);
        printf("Total Capacity: %d\n", flight->capacity);
        printf("Booked Seats: %d\n", flight->booked);
        printf("Passenger Information:\n");
        struct Passenger* currentPassenger = flight->passengers;
        while (currentPassenger != NULL)
        {
            printf("Seat Number: %d, Passenger Name: %s\n",
            currentPassenger->seatNumber, currentPassenger->name);
            currentPassenger = currentPassenger->next;
        }
    }
}
// Function to display all flights (inorder traversal)
void displayFlights(struct Flight* root)
{
    if (root != NULL)
    {
        displayFlights(root->left);
        printf("Flight Number: %s, Destination: %s\n",root->flightNumber, root->destination);
        displayFlights(root->right);
    }
}
int main()
{
    struct Flight* root = NULL;
    // Example: Adding flights
    root = insertFlight(root, "SA6192", "New Delhi", 100);
    root = insertFlight(root, "SA8972", "Kolkata", 150);
    root = insertFlight(root, "SA71845", "Kochi", 120);
    root = insertFlight(root, "SA5679", "Mumbai", 171);
    root = insertFlight(root, "SA2561", "Singapore", 234);
    root = insertFlight(root, "SA4482", "Tokyo", 231);
    root = insertFlight(root, "SA3624", "Chennai", 120);
    root = insertFlight(root, "SA1468", "Varanasi", 140);
    root = insertFlight(root, "SA4329", "Sharjah", 120);
    root = insertFlight(root, "SA2984", "Dabolim", 5);
    char flightNumber[10];
    char name[50];
    // Displaying options in a loop until user chooses to exit
    int choice = 0;
    printf("\nFlight Reservation System\n");
    printf("1. View available flights\n");
    printf("2. Book a seat\n");
    printf("3. Cancel reservation\n");
    printf("4. Check reservation status\n");
    printf("5. Search for Flight\n");
    printf("6. Exit\n");
    while(choice != 6) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("\nAvailable Flights:\n");
                displayFlights(root);
                break;
            }
            case 2: {
                printf("\nEnter flight number: ");
                scanf("%s", flightNumber);
                printf("Enter passenger name: ");
                scanf("%s", name);
                bookSeat(root, flightNumber, name);
                break;
            }
            case 3: {
                printf("\nEnter flight number: ");
                scanf("%s", flightNumber);
                printf("Enter passenger name: ");
                scanf("%s", name);
                cancelReservation(root, flightNumber, name);
                break;
            }
            case 4: {
                printf("\nEnter flight number: ");
                scanf("%s", flightNumber);
                displayReservationStatus(root, flightNumber);
                break;
            }
            case 5:
            {
                printf("\nEnter flight number to search: ");
                scanf("%s", flightNumber);
                struct Flight* searchedFlight = searchFlight(root, flightNumber);
                if (searchedFlight != NULL)
                {
                    printf("Flight Number: %s, Destination: %s\n", searchedFlight->flightNumber,
                    searchedFlight->destination);
                    printf("Capacity: %d, Booked Seats: %d\n", searchedFlight->capacity,
                    searchedFlight->booked);
                }
                else
                {
                    printf("\nFlight not found.\n");
                }
                break;
            }
            case 6:
            {
                printf(" Exiting...");
                break;
            }
            default:
            {
                printf("\n Please enter a valid option.\n");
            }
        }
    }
    return 0;
}