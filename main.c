//06-15-2024
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
            	searchStudent(students, studentCount);            	
				break;
				
            case 4:
            	//updateStudent();
            	printf("\033[1;34mWe're still working on this!\n\033[0m");
				printf("Press any key to exit: ");
		        getch();
				clearScreen();             	
				break;
				
            case 5:
            	//deleteStudent();
            	printf("\033[0;35mWe're still working on this!\n\033[0m");
				printf("Press any key to exit: ");
		        getch();
				clearScreen();             	
				break;
				
            case 6:
            	exitBox();
            	gotoxy(16,6);
            	printf("\033[1;35mTHANK YOU FOR USING THIS SYSTEM!\n\033[0m");	
            	gotoxy(15,10);
                exit(0);
				break;
                                
            default:
            	getchar();
            	gotoxy(13, 4);
            	printf("\033[0;31mInvalid choice! Please try again.\n\033[0m");
		        gotoxy(13, 5);
				printf("Press any key to exit: ");
		        getch();
				clearScreen();           	
                break;
                
        }
        
	
    }
    

    return 0;
}