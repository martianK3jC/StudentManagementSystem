
//main.c
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "manage_student.h"
#include "ui.h" 

int main(void) {
    struct Student students[100];
    int studentCount = 0;
    int choice;
	
	SetConsoleTitle("Kesha's Student Management System");
	
    while (choice != 6) {
    	
        menu();
        
        scanf("%d", &choice);
        
        clearScreen();

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);                
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
            	//searchStudent();
            	printf("We're still working on this!\n");
            	break;
            case 4:
            	//editStudent();
            	printf("We're still working on this!\n");
            	break;
            case 5:
            	//deleteStudent();
            	printf("We're still working on this!\n");
            	break;
            case 6:
            	printf("Thank you for using this system!");
                exit(0);
                break;
            default:
            	getchar();
            	printf("\033[0;31mInvalid choice! Please try again.\n\033[0m");
                break;
                
        }
        
        printf("Press any key to exit: ");
        getch();
		clearScreen();
	
    }

    return 0;
}