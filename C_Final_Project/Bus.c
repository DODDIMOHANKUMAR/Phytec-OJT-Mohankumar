#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "bus.h"


#define MAX_BUSES 20
#define MAX_NAME_LENGTH 50
int Busreservation(void);

typedef struct {
    int BusNumber;
    char destination[50];
    char source [50];
    int availableSeats;
    int Reservedseats;
} Buses;

Buses buses[MAX_BUSES];

void initializeBuses() 
{
	int j =0,k =14;
    for (int i = 0; i < MAX_BUSES; i++) 
    {
	    if(j ==15 && k==-1)
	    {
		    j =0;
		    k =14;
	    }

	 char sources[15][20]={"Anakapalle   ","Vijayawada   ","Secunderabad ","Banglore      ","Chennai        ","Visakhapatnam","Hyerabad     ","Delh          ","Kolkata      ","Mumbai       ","Gujarat      ","Goa          ","Tirupathi    ","Nellore      ","Jaipur       "};
        char destinations[15][20]={"Chennai   ","Lucknow   ","Surat     ","Pune      ","Guwahati  ","Vizag     ","Hyerabad  ","Delhi     ","Jaipur    ","Banglore  ","Mumbai    ","Gujarat   ","Goa       ","Tirupathi ","Anakapalle"};

        buses[i].BusNumber = i + 1;
	snprintf(buses[i].source,sizeof(buses[i].source),"\t%s",sources[j]);
        snprintf(buses[i].destination, sizeof(buses[i].destination),"\t%s",destinations[k]);
	printf("\t");
	buses[i].availableSeats =40;
	printf("\t");
	printf("\t");
        buses[i].Reservedseats =0;
	j++;
	k--;
    }
}

void displayBuses() {
    printf("Available buses:\n");
    printf("Bus Number\tsource\t\tDestination\t\tAvailable Seats\t\tReserved Seats\n");
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    for (int i = 0; i < MAX_BUSES; i++) 
    {

        printf("%d\t%s\t%s\t\t%d\t\t%d\n",3678 +i,buses[i].source, buses[i].destination, buses[i].availableSeats,buses[i].Reservedseats);
    }
}
void ReservationBus(int busNumber, int seats) {
    if (busNumber < 3678 || busNumber > 4250) {
        printf("Invalid Bus number\n");
        return;
    }

    Buses *selectedBus = &buses[busNumber - 3678];

    if (seats > selectedBus->availableSeats) {
        printf("Not enough available seats on this Bus.\n");
        return;
    }

    selectedBus->availableSeats -= seats;
    buses[busNumber -3678].Reservedseats+=seats;
    printf("Reservation successful for %d seats on Bus %d source %sto destination %s.\n", seats, selectedBus->BusNumber,selectedBus ->source, selectedBus->destination);
}

int  Busreservation()

{
    initializeBuses();

    while (1)
     {
        int choice,BusNumber,seats;
        printf("\nIndian Bus Reservation System\n");
        printf("1. Display Available Buses\n");
        printf("2. Reservation Bus\n");
	printf("3. Back to main menu\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBuses();
                break;
            case 2:

                printf("Enter Bus  number: ");
                scanf("%d", &BusNumber);
                printf("Enter number of seats to reserve: ");
                scanf("%d", &seats);
                ReservationBus(BusNumber, seats);
                break;
            case 3:
                printf("Thank you for Using Reservation system.Good Bye!\n");
                main();
	        case 4:
		exit(0);
            default:
                printf("Invalid choice.Please try Agin\n");
		return 0;
         }
    }
}



