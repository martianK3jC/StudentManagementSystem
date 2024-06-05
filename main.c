#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "manage_student.h"
#include "ui.h"
#include "add_Student.h"
#include "clear_Screen.h"

int main(void) {
    int choice = 0;

    while (choice != 6) {
        mainMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        clearScreen();

       switch(choice){
			case 1:
				addStudent();
				break;
			case 2:
				//	displayStudent();
				break;
			case 3:
				//	searchStudent();
				break;
			case 4:
				//	editStudent();
				break;
			case 5:
				//	deleteStudent();
				break;
			case 6:
				printf("Thank you for using this system! ☺");
				exit(0);
				break;
			default:
				getchar();
				printf("Invalid Choice, idiot!\n");
				break;		
	}
        printf("\nPress enter to continue: ");
        getchar();
        clearScreen();
    }

    return 0;
}