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

    while (choice != 6) {
<<<<<<< HEAD
    	
=======
>>>>>>> origin/view-students
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
<<<<<<< HEAD
            	printf("We're still working on this!\n");
            	break;
            case 4:
            	//editStudent();
            	printf("We're still working on this!\n");
            	break;
            case 5:
            	//deleteStudent();
            	printf("We're still working on this!\n");
=======
            	break;
            case 4:
            	//editStudent();
            	break;
            case 5:
            	//deleteStudent();
>>>>>>> origin/view-students
            	break;
            case 6:
            	printf("Thank you for using this system!");
                exit(0);
                break;
            default:
            	getchar();
<<<<<<< HEAD
            	printf("\033[0;31mInvalid choice! Please try again.\n\033[0m");
                break;
                
        }
        
        printf("Press any key to exit: ");
        getch();
		clearScreen();
	
=======
                printf("Invalid choice! Please try again.\n");
                break;
        }
        
        printf("\nPress any key to continue: ");
        getchar();
		clearScreen();
>>>>>>> origin/view-students
    }

    return 0;
}