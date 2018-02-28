//Andy Vainauskas
//Winter Quarter 2016
//COEN 11
//Reservation Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>

#define NODE struct node
#define LIST struct list

struct list
{
	NODE *head;
	NODE *tail;
};

struct node
{
	char name[20];
	int number;
	NODE *next;
};

void insert(char *, int);
void search(void);
void list(void);
void read_file(char *);
void save_file(char *);
void free_nodes(NODE *);
void insert_check(char *, int, LIST *);
void count(void);
void backwards(void);
void print_rev(char *);
void *autosave(void *);
void binary_print(void);

LIST *head = NULL;
LIST *tail = NULL;
LIST x[4];

pthread_mutex_t mutex;

int main(int argc, char *argv[ ])
{
	NODE *curr;
	int input;
	int i;
	int f = 0;
	int number;
	char name[20];	

	//Makes sure that the user has specified the file name
	if(argc == 1){
		printf("The name of the file is missing!\n");
		return 1;
	}
	
	//Takes the data from the file and puts it into the program
	else{
		read_file(argv[1]);
	}
		
	pthread_t thr;
	pthread_mutex_init(&mutex, NULL);
	
	//This is the thread
	pthread_create(&thr, NULL, autosave, (void*)NULL);
	
	while(1){
		f = 0;
	
		//Takes the user input
		scanf("%d", &input);

		switch(input){
		
			//Adds name and number as a node
			case 1:	
				pthread_mutex_lock (&mutex);
				printf("What is your name?\n");
				scanf("%s", name);
				
				//Traverses the nodes to check for a repetition
				for(i = 0; i<4; i++){
					curr = x[i].head;
					while(curr != NULL){
						if(strcmp(curr->name, name) == 0){
							printf("That name already exists.\n\n");
							f = 1;
						}
						curr = curr->next;
					}
				}			

				if(f == 1){
					continue;
				}
					printf("\n");
					printf("How many people?\n");
					scanf("%d", &number);
					
					insert(name, number);
					printf("\n");
					printf("The name has been added\n");
					pthread_mutex_unlock (&mutex);
					break;

			//Shows and deletes a node
			case 2:
				pthread_mutex_lock (&mutex);
				search();
				pthread_mutex_unlock (&mutex);
				break;

			//Lists all the nodes
			case 3:
				list();
				break;
				
			//Counts the occurrences of a specific character
			case 4:
				count();
				break;

			//Shows all the names backwards
			case 5:
				backwards();
				break;

            // Prints the data of the previous save file
			case 6:
				pthread_mutex_lock (&mutex);
				binary_print();
				pthread_mutex_unlock (&mutex);
				break;
			 
			//Quits the program
			default:
				pthread_mutex_lock (&mutex);
	        		pthread_cancel(thr);
				pthread_mutex_unlock (&mutex);
				save_file(argv[1]);
				return 0;
		}
	}
}

//Saves the list to a file every five seconds
void *autosave(void *arg)
{
	FILE *fp;
        NODE *p;
        NODE *q;
        char name[20];
        int number;
        int i;
	
	while(1){
	
		pthread_mutex_lock (&mutex);
        	fp = fopen("temp.bin", "w");

        	for(i=0; i<4; i++){
                	p = x[i].head;
			
			//Moves all the node data into the file
                	while(p != NULL){
				fwrite(p, sizeof(NODE), 1, fp);
				p = p->next;
                	}
        	}
	
	        fclose(fp);
		pthread_mutex_unlock (&mutex);
		sleep(5);
	}
}

void binary_print(void)
{
	FILE *fp;
	NODE temp;

	fp = fopen("temp.bin", "r");

	if(fp == NULL){
		printf("Error");
		return;
	}
	
	//Outputs the binary file, stored as a temp node, one at a time
	while(fread(&temp, sizeof(NODE), 1, fp) > 0){
		printf("%s has a table for %d\n", temp.name, temp.number);
	}
	
	fclose(fp);
}

void read_file(char *fname)
{
	FILE *fp;
	char name[20];
	int number;

	fp = fopen(fname, "r");
	
	//Checks to see if you can access the file
	if(fp == NULL){
		printf("Can't access the file\n");
		return;
	}

	//Moves the file pointer past the header in the file
	fseek(fp, 17, SEEK_SET);
	
	//Calls the insert function, which populates the nodes in the program
	while(fscanf(fp, "%s%d", name, &number) == 2){
		insert(name, number);
	} 
	
	fclose(fp);
	return;
}

void save_file(char *fname)
{
	FILE *fp;
	NODE *p;
	NODE *q;
	char name[20];
	int number;
	int i;
	
	fp = fopen(fname, "w");

	//Checks to see if you can access the file
	if(fp == NULL){
		printf("Can't access the file");
		return;
	}

	//Creates the header
	fprintf(fp, "Name\tGroup Size\n\n");

	for(i=0; i<4; i++){
		p = x[i].head;
		
		//Moves all the node data into the file
		while(p != NULL){
			fprintf(fp, "%s\t%d\n", p->name, p->number);
			p = p->next;
		}
	}

	fclose(fp);

	//Frees the nodes
	for(i=0; i<4; i++){
		p = x[i].head;
		free_nodes(p);
	}
}

//Recursive function to free the nodes
void free_nodes(NODE *p)
{
	if(p == NULL){
		return;
	}
	else{
		free_nodes(p->next);
		free(p);
	}
}

void insert_check(char *name, int number, LIST *p)
{
	NODE *q;
	
	//Checks to see if this is the first node being created
	if(p->head == NULL){
		p->head = (NODE*)malloc(sizeof(NODE));
		assert(p->head != NULL);
		
		q = p->head;
		strcpy(q->name, name);
		q->number = number;
		q->next = NULL;
		p->tail = p->head;
	}
	
	//If nodes already exist, this adds a node at the end
	else{
		q = p->tail;
		q->next = (NODE*)malloc(sizeof(NODE));
		assert(q->next != NULL);
		
		q = q->next;
		p->tail = p->tail->next;
		q->next = NULL;
		strcpy(q->name, name);
		q->number = number;
	}
}

void insert(char *name, int number)
{
	//Checks to see which list to insert into
	switch(number){
		case 1:
		case 2:
			insert_check(name, number, &x[0]);
			break;
		case 3:
		case 4:
			insert_check(name, number, &x[1]);
			break;
		case 5:
		case 6:
			insert_check(name, number, &x[2]);
			break;
		default:
			insert_check(name, number, &x[3]);
	}
}	

void search(void)
{
	LIST *p;
	NODE *curr;
	NODE *prev;
	int i;
	int numDel;

	printf("What table would you like to delete?\n");
	scanf("%d", &numDel);
	
	for(i = 3; i>=0; i--){
		p = &x[i];
		
		//Checks if the list is empty
		if(p->head == NULL){
			continue;
		}
		
		curr = p->head;
		prev = p->head;

		//Loops through the conditions
		while(curr != NULL){
			if(curr->number <= numDel){
				
				//If the node is at the beginning of the list
				if(curr == p->head){
					
					//If it is the only node
					if(p->head->next == NULL){
						printf("%s with a table size %d removed\n\n", curr->name, curr->number);
						p->head = NULL;
						p->tail = NULL;
						free(curr);
						return;
					}
					
					//If the node is not the only one, but still the first one
					else{
						printf("%s with a table size %d removed\n\n", curr->name, curr->number);
						p->head = p->head->next;
						free(curr);
						return;
					}
				}
				
				//If the node is at the end of the list
				if(curr == p->tail){
					printf("%s with a table size %d removed\n\n", curr->name, curr->number);
					p->tail = prev;
					p->tail->next = NULL;
					free(curr);
					return;
				}
				
				//If the node is in the middle
				if(curr->next != NULL){
					printf("%s with a table size %d removed\n\n", curr->name, curr->number);
					prev->next = curr->next;
					free(curr);
					return;
				}
			}
		prev = curr;
		curr = curr->next;
		}	
	}
}

void list(void)
{
	LIST *p;
	NODE *curr;
	int i;
	
	for(i = 0; i<4; i++){
		p = &x[i];
		curr = p->head;

		//Loops through the nodes and prints each of them
		while(curr != NULL){
			printf("%s has a table for %d\n", curr->name, curr->number);
			curr = curr->next;
		}
	}
}

void count(void)
{
	LIST *p;
	NODE *curr;
	char *q;
	int i;
	int counter = 0;
	char letter;

	printf("What letter would you like to look for?\n");
	__fpurge(stdin);
	scanf("%c", &letter);
	__fpurge(stdin);

	for(i = 0; i<4; i++){
		p = &x[i];
		curr = p->head;
	
		//Loops through the nodes and counts each time there is a matching character 
		while(curr != NULL){
			q = &curr->name[0];
			while(*q != '\0'){
				if(*q == letter){
					counter ++;
				}
				q++;
			}
			curr = curr->next;
		}
	}
	printf("The letter '%c' was found %d times.\n", letter, counter);
}

void backwards(void)
{
	LIST *p;
	NODE *curr;
	int i;

	//Loops through each node to find the names and then call a function to recursively print it backwards
	for(i=0; i<4; i++){
		p = &x[i];
		curr = p->head;

		while(curr != NULL){
			print_rev(curr->name);
			curr = curr->next;
			printf("\n");
		}
	}	
}

//Recursive function to return the letters backwards
void print_rev(char *p)
{
	if(*p == '\0'){
		return;
	}
	else{
		print_rev(p+1);
		printf("%c", *p);
	}
}
