#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_TRAINS 20
#define MAX_NAME_LENGTH 50
int Trainreservation(void);

typedef struct {
    int trainNumber;
    char destination[50];
    char source [50];
    int availableSeats;
    int reservedseats;
    char PassengerName[20];
  
} Train;

Train train[MAX_TRAINS];

void initializeTrain() {

	int j =0,k =10;
    //char PassengerName[20];
    for (int i = 0; i < MAX_TRAINS; i++) 
    {
	   if(j ==11 && k ==-1)
	   {
		   j =0;
		   k =10;
	   }
	   
	char sources[11][15] ={"Visakhapatnam","Vizayanagaram","Vijayawada   ","Nellore      ","Hyderabad    ","Mumbai       ","Goa          ","Delhi        ","kolkata      ","Tirupathi    ","Bangalore    "};
	char destinations[11][15] ={"chennai      ","KRPuram      ","Bangarupeta  ","kakinada     ","Bhopal       ","Jaipur       ","Anakapalle   ","TATA         ","Kadapa       ","Bangalore    ","Bhubaneswar  "};
        train[i].trainNumber = i + 1;
        snprintf(train[i].source, sizeof(train[i].source),"\t%s",sources[j]);
	snprintf(train[i].destination,sizeof(train[i].destination),"\t%s",destinations[k]);
	printf("\t");
        train[i].availableSeats = 120;
	printf("\t");
	printf("\t");
	train[i].reservedseats=0;
	//train[i].PassengerName=;
	j++;
	k--;
    }
}

void displayTrains() {
	//char PassengerName[20]="NOT RESERVED";
    printf("Available trains:\n");
    printf("Train Number\tsource\t\t\tDestination\t\tAvailable Seats\tReserved Seats\t PassengerName\n");
    printf("##############################################################################################################\n");
    for (int i = 0; i < MAX_TRAINS; i++) {
        printf("%d\t%s\t%s\t\t%d\t\t\t%d\t%s\n", 167235+i,train[i].source, train[i].destination,train[i].availableSeats,train[i].reservedseats,train[i].PassengerName);
    }
}

void ReservationTrain(long int trainNumber, int seats) 
{
    if (trainNumber < 167235 || trainNumber > 167255) {
        printf("Invalid train number\n");
        return;
    }

    Train *selectedTraine = &train[trainNumber - 167235];

    if (seats > selectedTraine->availableSeats) {
        printf("Not enough available seats on this train.\n");
        return;
    }

    

    selectedTraine->availableSeats -= seats;
    train[trainNumber-167235].reservedseats+=seats;
    train[trainNumber-167235].PassengerName="Mohan";
    printf("Reservation successful for %d seats on Traine %d source %s to destination %s.\n", seats, selectedTraine->trainNumber,selectedTraine->source, selectedTraine->destination);
}

//int Trainreservation()
int main()


{

    initializeTrain();

    while (1) {
        int choice;
	    long int trainNumber;int seats;char name[10];
        printf("\nIndian Railway Reservation System\n");
        printf("1. Display Available Trains\n");
        printf("2. Reservation Train\n");
	printf("3. Back to main menu\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTrains();
                break;
            case 2:
                printf("Enter train number: ");
                scanf("%ld", &trainNumber);
                printf("Enter number of seats to reserve: ");
                scanf("%d", &seats);
		printf("Enter Your Name: ");
		scanf("%s",name);
                ReservationTrain(trainNumber, seats);
                break;
            case 3:
                printf("Thank you for using the Reservation System.Happy Journey:\n");
		main();
	    case 4:
                exit(0);
            default:
                printf("Invalid choice.Please try again.\n");
                return 0;
        }
    }
}





