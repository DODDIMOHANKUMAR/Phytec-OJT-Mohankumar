#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "flight.h"


#define MAX_FLIGHTS 20
#define MAX_NAME_LENGTH 50

int Flightreservation(void);

typedef struct {
    int flightNumber;
    char source [50];
    char destination[50];
    int availableSeats;
    int reservedseats;
  
}Flight;

Flight flights[MAX_FLIGHTS];

void initializeFlights() {

	int j=0,k=9;
    for( int i = 0; i < MAX_FLIGHTS; i++) 
    {

	if(j==10 && k==-1)
	{
		j=0;
		k=9;
	}
	char sources[10][15]={"Banglore ","Chennai  ","Vizag    ","Hyerabad ","Delhi    ","Kolkata  ","Mumbai   ","Gujarat  ","Goa      ","Tirupathi"};
	char destinations[10][15]={"Chennai  ","Vizag    ","Hyerabad ","Delhi    ","Jaipur   ","Banglore ","Mumbai   ","Gujarat  ","Goa      ","Tirupathi"};
        flights[i].flightNumber = i + 2258;
        snprintf(flights[i].source, sizeof(flights[i].source), "\t%s",sources[j]);
	snprintf(flights[i].destination,sizeof(flights[i].destination),"\t%s",destinations[k]);
	printf("\t");
        flights[i].availableSeats = 50;
	printf("\t");
	printf("\t");
	flights[i].reservedseats =0;
	j++;
	k--;
    }
}

void displayFlights() {
    printf("Available flights:\n");
    printf("Flight Number\tsource\t\tDestination\t\tAvailable Seats\t\tReserved Seats\n");
    printf("***************************************************************************************************\n");
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("%d\t%s\t%s\t\t%d\t\t%d\n", 2258 +i,flights[i].source, flights[i].destination, flights[i].availableSeats,flights[i].reservedseats);
    }
}

void ReservationFlight( int flightNumber, int seats) {
    if (flightNumber < 2258 || flightNumber > 2500) {
        printf("Invalid flight number\n");
        return;
    }

    Flight *selectedFlight = &flights[flightNumber - 2258];

    if (seats > selectedFlight->availableSeats) {
        printf("Not enough available seats on this flight.\n");
        return;
    }

    selectedFlight->availableSeats -= seats;
    flights[flightNumber -2258].reservedseats+=seats;
    printf("Reservation successful for %d seats on Flight %d  source %sto destination %s.\n", seats, selectedFlight->flightNumber,selectedFlight->source, selectedFlight->destination);
}

int Flightreservation()
// int main()
{

    initializeFlights();

    while (1) {
        int choice, FlightNumber,seats;
        printf("\nIndian Flight Reservation System\n");
        printf("1. Display Available Flights\n");
        printf("2. Reservation Flight\n");
        printf("3. Back to Main menu\n");
	printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFlights();
                break;
            case 2:

                printf("Enter Flight  number: ");
                scanf("%d", &FlightNumber);
                printf("Enter number of seats to reserve: ");
                scanf("%d", &seats);
                ReservationFlight(FlightNumber, seats);
                break;
            case 3:
                printf("Thank you for using the reservation system. Goodbye!\n");
		main();
		case 4:
		exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                return 0;
        }
    }

}





