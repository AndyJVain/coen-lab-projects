//Andy Vainauskas
//Fall Quarter 2015
//COEN 10
//Multiplication Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void input(void);
void reverse(void);
void convert(void);
void info(void);

char names[10][20];
char length[10];
int counter = 0;

int main(void)
{
	printf("\nInput:\n");
	input();	//Task 1
	printf("\nReverse:\n");
	reverse();	//Task 2
	printf("\nConvert:\n");
	convert();	//Task 3
	printf("\nInfo:\n");
	info();		//Task 4	
		
return 1;
}

//Input up to 10 words, alphabetize, and display
void input(void)
{	
	int i = 0;
	int j = 0;
	int k = 0;
	char *p;
	char inputName[20];
	char temp[20];
	
	//Gets user input and puts it in the array (while also checking for ^D)
	for(i = 0; i<10; i++){	

		if(scanf("%s", inputName) == -1){
			break;
		}
		
		for(j=0; j<i; j++){
			if(strcmp(inputName, names[j]) < 0){
				break;
			}
		}
		
		for(k=i; k>=j; k--){
			strcpy(names[k], names[k-1]);
		}
		strcpy(names[j], inputName);
		counter++;
	}	
	
	//Outputs the array
	printf("\n\n");
	for(i=0; i<counter; i++){
		p = names[i];
		while(*p != '\0'){
			printf("%c", *p);
			p++;
		}
		printf("\n");
	}		
}

//Reverse the array and display
void reverse(void)
{
	char temp[10][20];
	int i;
	int f=0;
	char *p;
	
	//Copies the names array in reverse order	
	for(i=counter-1; i>=0; i--){
		strcpy(temp[f], names[i]);
		f++;
	}

	//Outputs the reversed array
	for(i=0; i<counter; i++){
		p = temp[i];
		while(*p != '\0'){
			printf("%c", *p);
			p++;
		}
		printf("\n");
	}
}

//Convert all lowercase to uppercase and display
void convert(void)
{
	char *p;
	int f;
	int i = 0;
	
	//Traverses the array and converts to uppercase
	for(i=0; i<counter; i++){
		f = 0;
		p = names[i];
		while(*p != '\0'){
			if(islower(*p)){
				*p = toupper(*p);
			}
			p++;
			f++;
		}
		length[i] = f;
	}

	//Outputs the array
	for(i=0; i<counter; i++){
		p = names[i];
		while(*p != '\0'){
			printf("%c", *p);
			p++;
		}
		printf("\n");
	}
}

//Display various information
void info(void)
{
	int i;
	int _short = length[0];
	int _long = length[0];
	int shortPos = 0;
	int longPos = 0;
	float average;
	int nonLetter;
	char *p;
	
	//Finds the shortest word length
	for(i=0; i<counter; i++){
		if(length[i] < _short){
			_short = length[i];
			shortPos = i;
		}
	}	

	//Finds the longest word length
	for(i=0; i<counter; i++){
		if(length[i] > _long){
			_long = length[i];
			longPos = i;
		}
	}
	
	//Finds the average
	for(i=0; i<counter; i++){
		average += length[i];
	}
	average/=counter;
	
	//Shows words that start with something other than a letter
	for(i=0; i<counter; i++){
		p = names[i];
		if(!isalpha(*p)){
			nonLetter++;
		}
	}

	printf("Shortest is %s (%d letters long)\n", names[shortPos], _short);
	printf("Longest is %s (%d letters long)\n", names[longPos], _long);
	printf("The average word length is %f\n", average);
	printf("The number of words that start with a nonletter is %d\n", nonLetter);	
}
