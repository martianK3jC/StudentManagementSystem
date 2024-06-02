#include <windows.h>
#include <unistd.h>
#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include "student.h"
#include "manage_student.h"
#include "mainMenu.h"

void addStudent(struct Student students[], int *studentCount) {
    struct Student newStudent;

    printf("\n\nEnter student name: ");
    scanf(" %[^\n]%*c", newStudent.name);

    printf("Enter student age: ");
    scanf("%d", &newStudent.age);


    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);

    printf("Enter student degree: ");
    scanf(" %[^\n]%*c", newStudent.degree);

    printf("Enter student address: ");
    scanf(" %[^\n]%*c", newStudent.address);

    printf("Enter student email: ");
    scanf("%99s", newStudent.email);

    students[*studentCount] = newStudent;
    (*studentCount)++;

    printf("Student added successfully!\n");
}

void viewStudents(struct Student students[], int studentCount) {
    printf("List of Students:\n\n");

    for (int i = 0; i < studentCount; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Id: %d\n", students[i].id);
        printf("Degree: %s\n", students[i].degree);
        printf("Address: %s\n", students[i].address);
        printf("Email: %s\n", students[i].email);
        printf("\n");
    }
}



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
=======
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "manage_student.h"
#include "mainMenu.h"

int main(){
mainMenu();
	
viewStudents();	

>>>>>>> origin/add-student
}