//manage_student.h
#ifndef MANAGE_STUDENT_H
#define MANAGE_STUDENT_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "ui.h"

void addStudent(struct Student students[], int *studentCount) {
    char addAnother;
    FILE *fp;
    struct Student newStudent;
    setConsoleToUtf8();

    do {
        clearScreen();
        
		addStudentBox();
    	
    	
        gotoxy(26, 5);
        printf("\033[0;36mADD STUDENT/S\033[0m");
        gotoxy(25, 6);
        printf("...............");
        
	   
        // Input fields
        gotoxy(14, 8);
        printf("Enter first name:\n");
        gotoxy(14, 9);
	    printf("\033[0;36m");
        scanf(" %[^\n]%*c", newStudent.firstName);
	    printf("\033[0m\n");       
        
        gotoxy(14, 11);
        printf("Enter last name:\n");
        gotoxy(14, 12);
	    printf("\033[0;36m");
		scanf(" %[^\n]%*c", newStudent.lastName);
	    printf("\033[0m\n");

        gotoxy(14, 14);
        printf("Enter student ID:\n");
        gotoxy(14, 15);
	    printf("\033[0;36m");
		scanf("%d", &newStudent.id);
	    printf("\033[0m\n");
        
        gotoxy(14, 17);
        printf("Enter student degree: \n");
        gotoxy(14, 18);
	    printf("\033[0;36m");
		scanf(" %[^\n]%*c", newStudent.degree);
	    printf("\033[0m\n");
        
        gotoxy(14, 20);
        printf("Enter student age: \n");
        gotoxy(14, 21);
	    printf("\033[0;36m");
		scanf("%d", &newStudent.age);
	    printf("\033[0m\n");
        
        gotoxy(14, 23);
        printf("Enter student address: \n");
        gotoxy(14, 24);
	    printf("\033[0;36m");
        scanf(" %[^\n]%*c", newStudent.address);
	    printf("\033[0m\n");
        
   	    gotoxy(14, 26);
        printf("Enter student email: \n");
        gotoxy(14, 27);
	    printf("\033[0;36m");
		scanf(" %[^\n]%*c", newStudent.email);
	    printf("\033[0m\n");
        
		
        //Write to the text file in a readable format
        fp = fopen("student_info.txt", "a");
        if (fp == NULL) {
            fprintf(stderr, "Can't open file\n");
            return;
        }

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


	    //success line
        printSAS();
        Sleep(1000);
        
        
        //add another student 
			do {
			        clearScreen();
				
					addAnotherStudentBox();
					
			        gotoxy(18, 5);
			        printf("Add another student? (y/n): ");
			        gotoxy(47, 5);
			        printf("\033[0;36m");
			        scanf(" %c", &addAnother);
			        printf("\033[0m\n");
			
				        if (addAnother != 'y' && addAnother != 'Y' && addAnother != 'n' && addAnother != 'N') {
				            gotoxy(15, 7);
				            printf("\033[1;31mInvalid choice. Please select y/n!\033[0m");
				            Sleep(2000);
				        }
			
			    } while (addAnother != 'y' && addAnother != 'Y' && addAnother != 'n' && addAnother != 'N');



	    //press-any key to exit (position)
	    gotoxy(14,8);


    } while (addAnother == 'y' || addAnother == 'Y');
    

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void displayStudents(struct Student students[], int studentCount) {
    FILE *fp;
    
	char line[256];
    
	fp = fopen("student_info.txt", "r");
    
    if (fp == NULL) {
        fprintf(stderr, "Can't open file\n");
        return;
    }

    printf("List of Students:\n\n");

    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);

}


#endif