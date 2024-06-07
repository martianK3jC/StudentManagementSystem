#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void setConsoleToUtf8() {
    SetConsoleOutputCP(CP_UTF8);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void headerLine() {
    printf("\033[0;34m");
    printf("----");
    printf("\033[1;34m");
    printf("----");
    printf("\033[0;36m");
    printf("----");
    printf("\033[1;36m");
    printf("----");
    printf("\033[1;37m");
    printf("----");
    printf("\033[1;37m");
    printf("---");
    printf("\033[1;36m");
    printf("----");
    printf("\033[0;36m");
    printf("----");
    printf("\033[1;34m");
    printf("----");
    printf("\033[0;34m");
    printf("----");
    printf("\033[0m");
}

void sideLine(int x, int yStart, int yEnd) {
    for (int y = yStart; y <= yEnd; y++) {
        gotoxy(x, y);
        printf("\033[0;34m|\033[0m");
    }
}

void BlueToCyan() {
    printf("\033[0;34m");
    printf(":");
    printf("\033[1;34m");
    printf(":");
    printf("\033[0;36m");
    printf(":");
    printf("\033[1;36m");
    printf(":");
    printf("\033[0;37m");
    printf(":");
    printf("\033[1;37m");
    printf(":");
    printf("\033[0m");
}

void menu(){
    setConsoleToUtf8();
    
    //left border
    sideLine(12, 4, 23);
    
    //top-left corner
    gotoxy(12, 3);
    printf("\033[0;34m┌\033[0m");
    
    //header line
    gotoxy(13, 3);
    headerLine();
    
    //top-right corner
    gotoxy(52, 3); 
    printf("\033[0;34m┐\033[0m");
    
   
    gotoxy(20, 4);
    printf("\033[1;33mSTUDENT MANAGEMENT SYSTEM\033[0m");

    
    gotoxy(27, 6);
    printf("\033[0;36mMain Menu\033[0m");
    gotoxy(16, 8);
    printf("\033[1;31m[1] Add New Student\033[0m");
    gotoxy(16, 9);
    printf("\033[1;32m[2] Display Student\033[0m");
    gotoxy(16, 10);
    printf("\033[0;33m[3] Search Student\033[0m");
    gotoxy(16, 11);
    printf("\033[0;34m[4] Update Student Information\033[0m");
    gotoxy(16, 12);
    printf("\033[0;35m[5] Delete Student/s\033[0m");
    gotoxy(16, 13);
    printf("\033[0;36m[6] Exit\033[0m");
    gotoxy(16, 16);
    printf("Enter your choice: ");
    
    //bottom-left corner
    gotoxy(12, 24);
    printf("\033[0;34m└\033[0m");
    
    //footer line
    gotoxy(13, 24);
    headerLine();
    
    //bottom-right corner
    gotoxy(52, 24);
    printf("\033[0;34m┘\033[0m");
    
    //right border
    sideLine(52, 4, 23);
	
	gotoxy(35, 16);
}

// Clear screen function
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


