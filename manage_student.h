#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void addStudent(struct Student students[], int *studentCount) {
	char addAnother;
	
	FILE *fp;
	struct Student newStudent;
	
	do{
	printf("\nADD STUDENT/S");
	
    fp = fopen("student_info.txt", "a");

    if(fp == NULL){
    	fprintf(stderr, "Can't open file\n");
    	return;
	}
	
	//Input Student Information
	printf("\n\nEnter first name: ");
    scanf(" %[^\n]%*c", newStudent.firstName);
    printf("Enter last name: ");
    scanf(" %[^\n]%*c", newStudent.lastName);
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student degree: ");
    scanf(" %[^\n]%*c", newStudent.degree);
    printf("Enter student age: ");
    scanf("%d", &newStudent.age);
    printf("Enter student address: ");
    scanf(" %[^\n]%*c", newStudent.address);
    printf("Enter student email: ");
    scanf("%99s", newStudent.email);
    
    // Write to the text file in a readable format
    fprintf(fp, "First Name: %s\n", newStudent.firstName);
    fprintf(fp, "Last Name: %s\n", newStudent.lastName);
    fprintf(fp, "Student ID: %d\n", newStudent.id);
    fprintf(fp, "Degree: %s\n", newStudent.degree);
    fprintf(fp, "Age: %d\n", newStudent.age);
    fprintf(fp, "Address: %s\n", newStudent.address);
    fprintf(fp, "Email: %s\n", newStudent.email);
    fprintf(fp, "------------------------\n");
    
    fclose(fp);
    
    students[*studentCount] = newStudent;
    (*studentCount)++;

		printf("\nSTUDENT ADDED SUCCESSFULLY!\n");
    printf("\nWould you like to add another student? (y/n): ");
    scanf(" %c", &addAnother);
    
	}while (addAnother == 'y' || addAnother == 'Y');
	
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



void displayStudents(struct Student students[], int studentCount) {
    printf("List of Students:\n\n");

    for (int i = 0; i < studentCount; i++) {
        printf("Name: %s\n", students[i].firstName);
        printf("Name: %s\n", students[i].lastName);
        printf("Id: %d\n", students[i].id);
        printf("Degree: %s\n", students[i].degree);
		printf("Age: %d\n", students[i].age);
        printf("Address: %s\n", students[i].address);
        printf("Email: %s\n", students[i].email);
        printf("\n");
    }
}



