// C program to generate random numbers 
#include <stdio.h> 
#include <stdlib.h> 
#include<time.h>
// Driver program 
int main(void) 
{ 
	// This program will create same sequence of 
	// random numbers on every program run 
	FILE* fptr; 

	// creating a file "random.txt" in "write" mode 
	fptr = fopen("first.txt", "w"); 
	int i; 
	if (fptr == NULL) { 
		printf("ERROR"); 
		exit(1); 
	} 
	srand(time(0));
	for (i = 0; i < 100000; i++) { 

		// to generate number less than 100000 
		//int val = rand() % 100000; 
		int val = rand(); 
		// storing data to file 
		fprintf(fptr, "%d ", val); 
	} 

	// closing the file 
	fclose(fptr); 
	printf("numbers generated successfully !! "); 
	return 0; 
} 

