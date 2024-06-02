#include "student.h"

void addStudent(struct Student students[], int *studentCount);
void viewStudents(struct Student students[], int studentCount);


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