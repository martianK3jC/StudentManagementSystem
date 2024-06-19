// 06-19-2024
// UPDATED ADDSTUDENT FUNCTION
// manage_student.h

#ifndef MANAGE_STUDENT_H
#define MANAGE_STUDENT_H

#include <ctype.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "student.h"
#include "ui.h"

// ADD STUDENT ----------------------------------------------------------------------------------------------------
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

        int uniqueID;
        do {
            uniqueID = 1;
            gotoxy(14, 14);
            printf("Enter ID:\n");
            gotoxy(14, 15);
            printf("\033[0;36m");
            scanf("%d", &newStudent.id);
            printf("\033[0m\n");

            fp = fopen("student_info.txt", "r");
            if (fp == NULL) {
                fprintf(stderr, "Can't open file\n");
                return;
            }

            struct Student info;
            char line[256];
            while (fgets(line, sizeof(line), fp)) {
                if (sscanf(line, "ID : %d\n", &info.id) == 1) {
                    if (newStudent.id == info.id) {
                        uniqueID = 0;
                        gotoxy(14, 17);
                        printf("\033[0;31mID already exists. Enter a unique ID.\033[0m\n");
                        Sleep(2000);
                        gotoxy(14, 17);
                        printf("                                      ");
                        gotoxy(14, 15);
                        printf("                                      ");
                        break;
                    }
                }
            }
            fclose(fp);
        } while (!uniqueID);

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

        
        fp = fopen("student_info.txt", "a");
        if (fp == NULL) {
            fprintf(stderr, "Can't open file\n");
            return;
        }

        fprintf(fp, "Name : %s %s\n", newStudent.firstName, newStudent.lastName);
        fprintf(fp, "ID : %d\n", newStudent.id);
        fprintf(fp, "Degree : %s\n", newStudent.degree);
        fprintf(fp, "Age : %d\n", newStudent.age);
        fprintf(fp, "Address : %s\n", newStudent.address);
        fprintf(fp, "Email : %s\n", newStudent.email);
        fprintf(fp, "----------------------------------\n");

        fclose(fp);

        students[*studentCount] = newStudent;
        (*studentCount)++;

        printSAS();
        Sleep(1000);

        
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

        gotoxy(21, 8);
        printf("\033[0;36mPress any key to exit: \033[0m");
        getch();
        clearScreen();
    } while (addAnother == 'y' || addAnother == 'Y');
}

// DISPLAY STUDENT ----------------------------------------------------------------------------------------------------
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

// SEARCH STUDENT ----------------------------------------------------------------------------------------------------
void searchStudent(struct Student students[], int studentCount) {
    FILE *fp;
    struct Student info;
    int idNum, found = 0;
    char line[256]; 

    searchBox();

    fp = fopen("student_info.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't open file\n");
        return;
    }

    while (1) {
        gotoxy(26, 4);
        printf("\033[0;33mSEARCH STUDENT\033[0m");
        gotoxy(14, 8);
        printf("\033[1;33m");
        printf("Enter Student Id: ");
        
        if (scanf("%d", &idNum) != 1) {
            
            while (getchar() != '\n');

            gotoxy(20, 10);
            printf("\033[0;31mPlease enter a valid ID!\033[0m");
            Sleep(2000);
			clearScreen();
			searchBox();
            continue;
        }

        break; 
    }

    printf("\033[0m\n");

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "Name : %s %s\n", info.firstName, info.lastName) == 2) {
            fgets(line, sizeof(line), fp);
            sscanf(line, "ID : %d\n", &info.id);

            fgets(line, sizeof(line), fp);
            sscanf(line, "Degree : %[^\n]\n", info.degree);

            fgets(line, sizeof(line), fp);
            sscanf(line, "Age : %d\n", &info.age);

            fgets(line, sizeof(line), fp);
            sscanf(line, "Address : %[^\n]\n", info.address);

            fgets(line, sizeof(line), fp);
            sscanf(line, "Email : %[^\n]\n", info.email);

            fgets(line, sizeof(line), fp);

            if (info.id == idNum) {
                found = 1;
                gotoxy(26, 6);
                printf("\033[0;32mStudent Found!\033[0m");
                gotoxy(14, 10);
                printf("Name    : %s %s", info.firstName, info.lastName);
                gotoxy(14, 11);
                printf("ID      : %d", info.id);
                gotoxy(14, 12);
                printf("Degree  : %s", info.degree);
                gotoxy(14, 13);
                printf("Age     : %d", info.age);
                gotoxy(14, 14);
                printf("Address : %s", info.address);
                gotoxy(14, 15);
                printf("Email   : %s", info.email);
                break;
            }
        }
    }

    if (!found) {
        gotoxy(24, 6);
        printf("\033[0;31mStudent Not Found!\n\n\033[0m");
    }

    fclose(fp);
    printf("\033[0;33m\n\n\t\t     Press any key to exit:\033[0m");
    getch();
    clearScreen();
}




// UPDATE STUDENT ----------------------------------------------------------------------------------------------------
void updateStudent(struct Student students[], int studentCount) {
    FILE *fp, *fp1;
    struct Student info, newStudent;
    int idNum, found = 0;
    char overwrite;
    char line[256];

    fp = fopen("student_info.txt", "r");
    fp1 = fopen("temp.txt", "w");

    if (fp == NULL || fp1 == NULL) {
        fprintf(stderr, "Can't open file\n");
        return;
    }

    while (1) {
        gotoxy(26, 4);
        printf("\033[1;34mUPDATE STUDENT\033[0m");
        gotoxy(18, 6);
        printf("Enter Student Id to Update: ");

        if (scanf("%d", &idNum) != 1) {
            while (getchar() != '\n');
            gotoxy(20, 10);
            printf("\033[0;31mPlease enter a valid ID!\033[0m");
            Sleep(2000);
            gotoxy(20, 10);
            printf("                        ");
            gotoxy(45, 6);
            printf("      ");
            gotoxy(45, 6);
            continue;
        }

        break;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "Name : %49s %49s", info.firstName, info.lastName) == 2) {
            fgets(line, sizeof(line), fp);
            sscanf(line, "ID : %d", &info.id);

            fgets(line, sizeof(line), fp);
            sscanf(line, "Degree : %49[^\n]", info.degree);

            fgets(line, sizeof(line), fp);
            sscanf(line, "Age : %d", &info.age);

            fgets(line, sizeof(line), fp);
            sscanf(line, "Address : %99[^\n]", info.address);

            fgets(line, sizeof(line), fp);
            sscanf(line, "Email : %99[^\n]", info.email);

            fgets(line, sizeof(line), fp);

            if (info.id == idNum) {
                found = 1;
                clearScreen();

                gotoxy(26, 4);
                printf("\033[1;34mUPDATE STUDENT\033[0m");
                gotoxy(18, 6);
                printf("\033[1;36mEnter New Student Information\033[0m");

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
                printf("Enter degree: ");
                gotoxy(14, 15);
                printf("\033[0;36m");
                scanf(" %[^\n]%*c", newStudent.degree);
                printf("\033[0m\n");

                gotoxy(14, 17);
                printf("Enter age: ");
                gotoxy(14, 18);
                printf("\033[0;36m");
                scanf("%d", &newStudent.age);
                printf("\033[0m\n");

                gotoxy(14, 20);
                printf("Enter address: ");
                gotoxy(14, 21);
                printf("\033[0;36m");
                scanf(" %[^\n]%*c", newStudent.address);
                printf("\033[0m\n");

                gotoxy(14, 23);
                printf("Enter email: ");
                gotoxy(14, 24);
                printf("\033[0;36m");
                scanf(" %[^\n]%*c", newStudent.email);
                printf("\033[0m\n");

                newStudent.id = info.id;

                fprintf(fp1, "Name : %s %s\n", newStudent.firstName, newStudent.lastName);
                fprintf(fp1, "ID : %d\n", newStudent.id);
                fprintf(fp1, "Degree : %s\n", newStudent.degree);
                fprintf(fp1, "Age : %d\n", newStudent.age);
                fprintf(fp1, "Address : %s\n", newStudent.address);
                fprintf(fp1, "Email : %s\n", newStudent.email);
                fprintf(fp1, "----------------------------------\n");
            } else {
                fprintf(fp1, "Name : %s %s\n", info.firstName, info.lastName);
                fprintf(fp1, "ID : %d\n", info.id);
                fprintf(fp1, "Degree : %s\n", info.degree);
                fprintf(fp1, "Age : %d\n", info.age);
                fprintf(fp1, "Address : %s\n", info.address);
                fprintf(fp1, "Email : %s\n", info.email);
                fprintf(fp1, "----------------------------------\n");
            }
        }
    }

    fclose(fp);
    fclose(fp1);

    if (found) {
        do {
            gotoxy(14, 26);
            printf("Do you want to save changes? (y/n): ");
            printf("\033[0;36m");
            scanf(" %c", &overwrite);
            printf("\033[0m\n");

            if (overwrite != 'y' && overwrite != 'Y' && overwrite != 'n' && overwrite != 'N') {
                gotoxy(14, 27);
                printf("\033[1;31mInvalid choice. Please select y/n!\033[0m");
                Sleep(2000);
                gotoxy(14, 27);
                printf("                                  ");
                gotoxy(49, 26);
                printf("         ");
                gotoxy(49, 26);
            }
        } while (overwrite != 'y' && overwrite != 'Y' && overwrite != 'n' && overwrite != 'N');

        if (overwrite == 'y' || overwrite == 'Y') {
            gotoxy(14, 28);
            printf("\033[0;32mChanges Saved!\033[0m");

            if (rename("student_info.txt", "student_info.bak") != 0) {
                perror("\033[1;31mError renaming original file\033[0m");
            } else {
                if (rename("temp.txt", "student_info.txt") != 0) {
                    perror("\033[1;31mError renaming temporary file\033[0m");
                }
            }
        } else {
            gotoxy(14, 28);
            printf("\033[0;31mChanges Discarded!\033[0m");
            remove("temp.txt");
        }
    } else {
        gotoxy(24, 8);
        printf("\033[0;31mStudent Not Found!\033[0m");
        remove("temp.txt");
    }

    printf("\033[1;36m\n\n\t     Press any key to exit:\033[0m");
    clearInputBuffer();
    getch();
    clearScreen();
}

// DELETE STUDENT ----------------------------------------------------------------------------------------------------
void deleteStudent(struct Student students[], int *studentCount) {
    FILE *fp = fopen("student_info.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't open file\n");
        return;
    }

    FILE *tempFp = fopen("temp.txt", "w");
    if (tempFp == NULL) {
        fprintf(stderr, "Can't open temporary file\n");
        fclose(fp);
        return;
    }

    int studentIdToDelete;
    int studentDeleted = 0;
    char line[256];
    char confirm;

    clearScreen();

    gotoxy(26, 4);
    printf("\033[0;35mDELETE STUDENT\033[0m");
    gotoxy(18, 6);
    printf("Enter Student Id to Delete: ");
    printf("\033[0;36m");
    scanf("%d", &studentIdToDelete);
    printf("\033[0m\n");

    while (fgets(line, sizeof(line), fp)) {
        struct Student tempStudent = {0};

        if (sscanf(line, "Name : %49s %49s", tempStudent.firstName, tempStudent.lastName) != 2) {
            fprintf(stderr, "Error reading name\n");
            continue;
        }

        if (!fgets(line, sizeof(line), fp) || sscanf(line, "ID : %d", &tempStudent.id) != 1) {
            fprintf(stderr, "Error reading ID\n");
            continue;
        }

        if (!fgets(line, sizeof(line), fp) || sscanf(line, "Degree : %49[^\n]", tempStudent.degree) != 1) {
            fprintf(stderr, "Error reading degree\n");
            continue;
        }

        if (!fgets(line, sizeof(line), fp) || sscanf(line, "Age : %d", &tempStudent.age) != 1) {
            fprintf(stderr, "Error reading age\n");
            continue;
        }

        if (!fgets(line, sizeof(line), fp) || sscanf(line, "Address : %99[^\n]", tempStudent.address) != 1) {
            fprintf(stderr, "Error reading address\n");
            continue;
        }

        if (!fgets(line, sizeof(line), fp) || sscanf(line, "Email : %99[^\n]", tempStudent.email) != 1) {
            fprintf(stderr, "Error reading email\n");
            continue;
        }
        
        if (!fgets(line, sizeof(line), fp)) {
            fprintf(stderr, "Error reading delimiter\n");
            continue;
        }

        if (tempStudent.id != studentIdToDelete) {
            fprintf(tempFp, "Name : %s %s\n", tempStudent.firstName, tempStudent.lastName);
            fprintf(tempFp, "ID : %d\n", tempStudent.id);
            fprintf(tempFp, "Degree : %s\n", tempStudent.degree);
            fprintf(tempFp, "Age : %d\n", tempStudent.age);
            fprintf(tempFp, "Address : %s\n", tempStudent.address);
            fprintf(tempFp, "Email : %s\n", tempStudent.email);
            fprintf(tempFp, "----------------------------------\n");
        } else {
            studentDeleted = 1;

            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Name    : %s %s", tempStudent.firstName, tempStudent.lastName);
            gotoxy(14, 8);
            printf("%s\n", buffer);

            snprintf(buffer, sizeof(buffer), "ID      : %d", tempStudent.id);
            gotoxy(14, 9);
            printf("%s\n", buffer);

            snprintf(buffer, sizeof(buffer), "Degree  : %s", tempStudent.degree);
            gotoxy(14, 10);
            printf("%s\n", buffer);

            snprintf(buffer, sizeof(buffer), "Age     : %d", tempStudent.age);
            gotoxy(14, 11);
            printf("%s\n", buffer);

            snprintf(buffer, sizeof(buffer), "Address : %s", tempStudent.address);
            gotoxy(14, 12);
            printf("%s\n", buffer);

            snprintf(buffer, sizeof(buffer), "Email   : %s", tempStudent.email);
            gotoxy(14, 13);
            printf("%s\n", buffer);

            while (1) {
                gotoxy(14, 15);
                printf("\033[1;31mDelete Student? (y/n): \033[0m");
                scanf(" %c", &confirm);

                if (confirm == 'y' || confirm == 'Y') {
                    break;
                } else if (confirm == 'n' || confirm == 'N') {
                	gotoxy(14, 16);
                    printf("\033[0;31mChanges Discarded!\033[0m");
                    fclose(fp);
                    fclose(tempFp);
                    remove("temp.txt");
                    goto exit_function;
                } else {
                    gotoxy(14, 16);
                    printf("\033[1;31mInvalid choice. Please choose y/n.\033[0m");
                    clearInputBuffer();
                    Sleep(2000);
                    gotoxy(14, 16);
                    printf("                       ");
                    gotoxy(36, 16);
                    printf(" ");
                    gotoxy(36, 16);
                }
            }
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (studentDeleted) {
        if (remove("student_info.txt") != 0) {
            perror("\033[1;31mError removing existing student data file\033[0m");
        } else {
            if (rename("temp.txt", "student_info.txt") != 0) {
                perror("\033[1;31mError renaming temporary file\033[0m");
            } else {
            	gotoxy(14,16);
                printf("\033[0;32mStudent Deleted Successfully!\033[0m");
                (*studentCount)--;
            }
        }
    } else {
        remove("temp.txt");
        gotoxy(24, 8);
        printf("\033[0;31mStudent Not Found!\033[0m");
    }

exit_function:
    printf("\033[1;35m\n\n\t     Press any key to exit:\033[0m");
    clearInputBuffer();
    getch();
    clearScreen();
}



#endif 
