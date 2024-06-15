//06-15-2024
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
        gotoxy(20, 6);
        printf("Enter Student Information");
        
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
        printf("Enter ID:\n");
        gotoxy(14, 15);
	    printf("\033[0;36m");
		scanf("%d", &newStudent.id);
	    printf("\033[0m\n");
        
        gotoxy(14, 17);
        printf("Enter degree: \n");
        gotoxy(14, 18);
	    printf("\033[0;36m");
		scanf(" %[^\n]%*c", newStudent.degree);
	    printf("\033[0m\n");
        
        gotoxy(14, 20);
        printf("Enter age: \n");
        gotoxy(14, 21);
	    printf("\033[0;36m");
		scanf("%d", &newStudent.age);
	    printf("\033[0m\n");
        
        gotoxy(14, 23);
        printf("Enter address: \n");
        gotoxy(14, 24);
	    printf("\033[0;36m");
        scanf(" %[^\n]%*c", newStudent.address);
	    printf("\033[0m\n");
        
   	    gotoxy(14, 26);
        printf("Enter email: \n");
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
        
        fprintf(fp, "Name    : %s %s\n", newStudent.firstName, newStudent.lastName);
        fprintf(fp, "ID      : %d\n", newStudent.id);
        fprintf(fp, "Degree  : %s\n", newStudent.degree);
        fprintf(fp, "Age     : %d\n", newStudent.age);
        fprintf(fp, "Address : %s\n", newStudent.address);
        fprintf(fp, "Email   : %s\n", newStudent.email);
        fprintf(fp, "----------------------------------\n");

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
	    gotoxy(21,8);
    	printf("\033[0;36mPress any key to exit: \033[0m");
		getch();
		clearScreen(); 

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
	gotoxy(13, 3);
    greenHeaderLine();
    
	gotoxy(23, 5);
    printf("\033[0;32mLIST OF STUDENTS:\n\n\033[0m");	

	int counter = 7;
    while (fgets(line, sizeof(line), fp)) {
    	gotoxy(14, counter);
    	
	    printf("%s", line);
    	counter++;
    }
	
	fclose(fp);
	printf("\n");
	gotoxy(14, counter);
	printf("\033[1;32mPress any key to exit: \033[0m");
	getch();
	clearScreen(); 
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void searchStudent(struct Student students[], int studentCount) {
    FILE *fp;
    struct Student info;
    int idNum, found = 0;
    
	searchBox();
    
    fp = fopen("student_info.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't open file\n");
        return;
    }
    
    gotoxy(26,4);
    printf("\033[0;33mSEARCH STUDENT\033[0m");
	gotoxy(14,8);
	printf("\033[1;33m");
    printf("Enter Student Id: ");
    scanf("%d", &idNum);
    printf("\033[0m\n");
    
    // Note to self: format strings in 'fscanf' functions must match labels in the student_info.txt file
    while (fscanf(fp, "Name : %s %s\n", info.firstName, info.lastName) == 2) {
        fscanf(fp, "ID : %d\n", &info.id);
        fscanf(fp, "Degree       : %[^\n]\n", info.degree);
        fscanf(fp, "Age          : %d\n", &info.age);
        fscanf(fp, "Address      : %[^\n]\n", info.address);
        fscanf(fp, "Email        : %[^\n]\n", info.email);
        fscanf(fp, "----------------------------------\n");

        if (info.id == idNum) {
            found = 1;
			gotoxy(26, 6);
    		printf("\033[0;32mStudent Found!\033[0m");
			gotoxy(14, 10);
            printf("Name    : %s %s", info.firstName, info.lastName);
            gotoxy(14, 11);
            printf("ID      : %d", info.id);
            gotoxy(14,12);
            printf("Degree  : %s", info.degree);
            gotoxy(14,13);
            printf("Age     : %d", info.age);
            gotoxy(14,14);
            printf("Address : %s", info.address);
            gotoxy(14,15);
            printf("Email   : %s", info.email);

            break; 
        }
    }

    if (!found) {
		gotoxy(24, 10);
		printf("\033[0;31mStudent Not Found!\033[0m");
    }

    fclose(fp);
    printf("\033[0;33m\n\n\t\t     Press any key to exit:\033[0m");    
	getch();
	clearScreen(); 
}



#endif