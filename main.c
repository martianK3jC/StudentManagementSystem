#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "manage_student.h"
#include "mainMenu.h"


int main() {
    struct Student students[100];
    int studentCount = 0;
    int choice;

    while (1) {
        mainMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);
        

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
    }

    return 0;
}