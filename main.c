#include <windows.h>
<<<<<<< HEAD
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
=======
#include <unistd.h>
#include <windows.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "student.h"
#include "manage_student.h"
#include "ui.h"

int main() {
    struct Student students[100];
    int studentCount = 0;
    int choice;

    while (1) {
>>>>>>> 4b22c22e52452a4cb4063f9267440c5be69ee949
        mainMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        clearScreen();

<<<<<<< HEAD
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
=======
        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                
                break;
            case 2:
                viewStudents(students, studentCount);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("Pressed any key to continue...\n\n");
        getch();
>>>>>>> 4b22c22e52452a4cb4063f9267440c5be69ee949
    }

    return 0;
}