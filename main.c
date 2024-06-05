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
        mainMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        clearScreen();

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);                
                break;
            case 2:
            	getchar();
            	printf("We are still working on this!\nPlease come back later!");
                //displayStudents(students, studentCount);
                break;
            case 3:
            	getchar();
            	printf("We are still working on this!\nPlease come back later!");
            	//searchStudent();
            	break;
            case 4:
            	getchar();
            	printf("We are still working on this!\nPlease come back later!");
            	//editStudent();
            	break;
            case 5:
            	getchar();
            	printf("We are still working on this!\nPlease come back later!");
            	//deleteStudent();
            	break;
            case 6:
            	printf("Thank you for using this system!");
                exit(0);
                break;
            default:
            	getchar();
                printf("Huey! Invalid choice (T^T)\nPlease try again.\n");
                break;
        }
        
        printf("\nPress enter to continue: ");
        getchar();
		clearScreen();
    }

    return 0;
}