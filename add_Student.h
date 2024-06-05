#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void addStudent() {
    char addAnother;
    
    FILE *fp; //fp = file pointer
    struct Student info;
    
    do {
        printf("Add Student\n\n");
    
		//This part opens the .txt file to place inputted info
	    fp = fopen("student_info.txt", "a");
        
        if (fp == NULL) {
            fprintf(stderr, "Can't open file\n");
            return;
        }
        
        //Input Student Information
       	printf("Enter first name: ");
		scanf(" %[^\n]%*c", info.firstName); 
        printf("Enter last name: ");
		scanf(" %[^\n]%*c", info.lastName);
        printf("Enter Student Id: ");
        scanf("%d", &info.id);
        printf("Enter degree: ");
        scanf(" %[^\n]%*c", info.degree);
        printf("Enter age: ");
        scanf("%d", &info.age);
        printf("Enter address: ");
        scanf(" %[^\n]%*c", info.address);
        printf("Enter email: ");
        scanf(" %[^\n]%*c", info.email);
        
    	// Write to the text file in a readable format
        fprintf(fp, "First Name: %s\n", info.firstName);
        fprintf(fp, "Last Name: %s\n", info.lastName);
        fprintf(fp, "Student ID: %d\n", info.id);
        fprintf(fp, "Degree: %s\n", info.degree);
        fprintf(fp, "Age: %d\n", info.age);
        fprintf(fp, "Address: %s\n", info.address);
        fprintf(fp, "Email: %s\n", info.email);
        fprintf(fp, "------------------------\n");
        
        
        fclose(fp);
        
        printf("\nSTUDENT ADDED SUCCESSFULLY!\n");
        
        
        printf("\nWould you like to add another student? (y/n): ");
        scanf(" %c", &addAnother);
        
    } while (addAnother == 'y' || addAnother == 'Y');
}
