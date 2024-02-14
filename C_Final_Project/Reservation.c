#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"flight.h"
#include "Train.h"
#include"bus.h"
int Reservation()
{

    initializeFlights();
    initializeTrain();
    initializeBuses();

    while (1) {
        int choice;
        printf("\n*********************************Indian Reservation System*****************************\n");
        printf("1. View Information About Flights\n");
        printf("2. View Information About Train\n");
	printf("3. View Information About Buses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                 displayFlights();
		 Flightreservation();

                break;
            case 2:
		 displayTrains();
		Trainreservation();
              	break;
	    case 3:
                 displayBuses();
		 Busreservation();
              break;
	    case 4:
                printf("Thank you for using the reservation system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                return 0;
          }	
   

	}
}


