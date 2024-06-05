//Menu
#include <stdio.h>
#include <stdlib.h>

void mainMenu()
{
	printf("STUDENT MANAGEMENT SYSTEM\n");
	printf("Main Menu\n\n");
	printf("[1] Add New Student\n");
	printf("[2] Display Student\n");
	printf("[3] Search Student\n");
	printf("[4] Update Student Information\n");
	printf("[5] Delete Student/s\n");
	printf("[6] User Guidelines\n");
	printf("[7] Exit\n");
}
 
 
 void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}