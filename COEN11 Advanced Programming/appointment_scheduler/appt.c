//Andy Vainauskas
//Fall Quarter 2015
//COEN 10
//Appointment Scheduling Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void schedule(void);
void cancel(void);
void list(void);
void emergency(void);
int count_letter(char);

	int counter = 0;
	int input = 0;
	int i;
	char names[6][20];
	char nameCancel[20];

int main(void)
{
	//Populates the name array with blank values
	for (i=0; i<6; i++){
		names[i][0]='\0';
	}

	while(1){

		//Takes the user input
		scanf("%d", &input);
		
		switch(input){
			int number = 0;
			char letter;
			
			//Schedules an appointment
			case 1:
				schedule();
				break;

			//Cancels an appointment
			case 2:
				cancel();
				break;
			
			//Lists the appointments
			case 3:
				list();
				break;

			//Scedules an emergency
			case 4:
				emergency();
				break;
			
			//Counts a letter
			case 5:
				printf("What letter would you like to search?\n");
				__fpurge (stdin);
				scanf("%c", &letter);
				__fpurge (stdin);
				number = count_letter(letter);
				printf("Found %d occurrences of %c.\n\n", number, letter);
				break;
			
			//Quits the program
			default:
				return 0;
		}
	}
return 0;
}

//Function for scheduling
void schedule(void)
{		
		int i;
		int f;
		char tempName[20];
		
		//Notifies the user if there are no appointments
		if(counter==6){
			printf("There are no available appointments.\n\n");
		}
		
		//Makes an appoitnment if there is an empty spot
		if(counter<6){
			printf("What is your name?\n");
			scanf("%s", tempName);
			
			//Checks to see if there is a name match
			for(i=0; i<6; i++){
				if(strcmp (names[i], tempName) == 0){
					printf("An appointment under that name already exists.\n\n");
					f++;
					break;
				}
			}
			
			//If there is no name match, it makes the appointment
			if(f==0){
				strcpy(names[counter], tempName);
				counter++;
				printf("Your appointment is at %dpm.\n\n", counter);
			}				
		}
}

//Function for canceling
void cancel(void)
{
	int temp = 0;
	int i;
	int j;

	//Checks if there are any open spots
	if(counter==0){
		printf("There aren't any appointments to cancel.\n\n");
	}
	
	//Asks the user the name of the appointment to cancel
	else{
		printf("What is your name (to cancel)?\n");
		scanf("%s", nameCancel);
		for(i=0; i<6; i++){
			
			//Moves names above slot that was cancelled
			if(strcmp (names[i], nameCancel)==0){
				names[i][0]='\0';
				for(j=0; j<6; j++){
					strcpy(names[i+j], names[i+j+1]);
				}
				counter--;
				temp++;
				printf("You've cancelled your appointment.\n\n");
				break;
			}
		}
		
		//If the previous condition is never true, this says there is no match
		if(temp==0){
			printf("There are no appointments under that name.\n\n");
		}
	}
}

//Function for listing
void list(void)
{
	//Checks if there are any open spots
	if(counter==0){
		printf("There are no appointments to list.\n\n");
	}
	
	//Lists all of the appointments
	else{
		for(i=0; i<6; i++){
			printf("%s has an appointment at %dpm.\n", names[i], i+1);
		}
	}
	printf("\n");
}

//Function for emergency
void emergency(void)
{
	int i;
	int f=0;
	int nameAlert=0;
	char tempName[20];
	char clearName[20];
	
	printf("What is your name (emergency)?\n");
	scanf("%s", tempName);
	
	//Checks for a repetition
	for(i=0; i<6; i++){
		if(strcmp (names[i], tempName) == 0){
			printf("An appointment with that name already exists.\n\n");	
			f++;
			break;
		} 
	}
	
	//If there is no repetition
	if(f == 0){	
		
		//If the schedule is full
		if(counter == 6){
			strcpy(clearName, names[5]);;
			counter--;
			nameAlert++;			
		}
		for(i=counter; i>0; i--){
			strcpy(names[i], names[i-1]);
		}
		strcpy(names[0], tempName);
		counter++;
		printf("Your emergency appointment has been scheduled for 1pm.\n\n");
	}
	if(nameAlert == 1){
		printf("The appointment for %s has been deleted to make space.\n\n", clearName);
	}	
}

//Function for counting a letter
int count_letter(char letter)
{
	int countLetter = 0;
	
	for(i=0; i<counter; i++){
		char *p = names[i];
		while(*p != '\0'){
			if(*p== letter){
				countLetter++;
			}
			p++;
		}
	}
	return countLetter;
}
