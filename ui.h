//12-06-2024
//ui.h
#ifndef UI_H
#define UI_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void setConsoleToUtf8() {
    SetConsoleOutputCP(CP_UTF8);
}

//hmmm this one triggers flying lines
//void gotoxy(int x, int y) {
//    COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}

//this one below definitely works
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
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

void redHeaderLine() {
    printf("\033[0;31m");
    printf("----");
    printf("\033[0;35m");
    printf("----");
    printf("\033[1;35m");
    printf("----");
    printf("\033[1;31m");
    printf("----");
    printf("\033[1;37m");
    printf("----");
    printf("\033[1;37m");
    printf("---");
    printf("\033[1;31m");
    printf("----");
    printf("\033[1;35m");
    printf("----");
    printf("\033[0;35m");
    printf("----");
    printf("\033[0;31m");
    printf("----");
    printf("\033[0m");
}

void greenHeaderLine() {
    printf("\033[0;32m");
    printf("----");
    printf("\033[1;32m");
    printf("----");
    printf("\033[0;33m");
    printf("----");
    printf("\033[1;33m");
    printf("----");
    printf("\033[1;37m");
    printf("----");
    printf("\033[1;37m");
    printf("---");
    printf("\033[1;33m");
    printf("----");
    printf("\033[0;33m");
    printf("----");
    printf("\033[1;32m");
    printf("----");
    printf("\033[0;32m");
    printf("----");
    printf("\033[0m");
}


void sideLine(int x, int yStart, int yEnd) {
    for (int y = yStart; y <= yEnd; y++) {
        gotoxy(x, y);
        printf("\033[0;34m|\033[0m");
    }
}

void redSideLine(int x, int yStart, int yEnd) {
    for (int y = yStart; y <= yEnd; y++) {
        gotoxy(x, y);
        printf("\033[0;31m|\033[0m");
    }
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
    
   
    gotoxy(20, 5);
    printf("\033[1;33mSTUDENT MANAGEMENT SYSTEM\033[0m");

    
    gotoxy(27, 6);
    printf("\033[0;30mMain Menu\033[0m");
    gotoxy(16, 8);
    printf("\033[0;36m[1] Add New Student\033[0m");
    gotoxy(16, 10);
    printf("\033[0;32m[2] Display Student\033[0m");
    gotoxy(16, 12);
    printf("\033[0;33m[3] Search Student\033[0m");
    gotoxy(16, 14);
    printf("\033[1;34m[4] Update Student Information\033[0m");
    gotoxy(16, 16);
    printf("\033[0;35m[5] Delete Student/s\033[0m");
    gotoxy(16, 18);
    printf("\033[0;31m[6] Exit\033[0m");
    gotoxy(22, 21);
    printf("ENTER YOUR CHOICE: ");
    
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
	
	gotoxy(41, 21);
}


void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


void addStudentBox(){
		// header line
        gotoxy(13, 3);
        headerLine();
        
        //left side
		sideLine(12, 4, 32);       
		
    	//top-right corner
    	gotoxy(52, 3); 
    	printf("\033[0;34m\u2510\033[0m\n");	 
        
    	//top-left corner
    	gotoxy(12, 3);
    	printf("\033[0;34m\u250C\033[0m");        
        
        //right side
        sideLine(52, 4, 32); 
        
		// footer line
        gotoxy(13, 32);
        headerLine();      	

  		//bottom-left corner
    	gotoxy(12, 32);
   		printf("\033[0;34m\u2514\033[0m");
   
    	//bottom-right corner
    	gotoxy(52, 32);
    	printf("\033[0;34m\u2518\033[0m");
}

void printSAS(){
		gotoxy(19,29);
	    printf("\033[0;32m");
		printf("S");
		Sleep(60);
		printf("T");
		Sleep(60);
		printf("U");
		Sleep(60);
		printf("D");
		Sleep(60);
		printf("E");
		Sleep(60);
		printf("N");
		Sleep(60);
		printf("T");
		Sleep(60);
		printf(" ");
		Sleep(90);
		printf("A");
		Sleep(60);
		printf("D");
		Sleep(60);
		printf("D");
		Sleep(60);
		printf("E");
		Sleep(60);
		printf("D");
		Sleep(60);
		printf(" ");
		Sleep(90);
		printf("S");
		Sleep(60);
		printf("U");
		Sleep(60);
		printf("C");
		Sleep(60);
		printf("C");
		Sleep(60);
		printf("E");
		Sleep(60);
		printf("S");
		Sleep(60);
		printf("S");
		Sleep(60);
		printf("F");
		Sleep(60);
		printf("U");
		Sleep(60);
		printf("L");
		Sleep(60);
		printf("L");
		Sleep(60);
		printf("Y");
		Sleep(60);
		printf("!");
		Sleep(60);
		printf("\033[0m\n");
}

void addAnotherStudentBox(){
	// header line
    gotoxy(13, 3);
    headerLine();
			        
    //left side
	sideLine(12, 4, 9);       
					
   	//top-right corner
   	gotoxy(52, 3); 	
   	printf("\033[0;34m\u2510\033[0m\n");	 
			        
   	//top-left corner
   	gotoxy(12, 3);
   	printf("\033[0;34m\u250C\033[0m");        
			        
	//right side
	sideLine(52, 4, 9); 
			        
	// footer line
    gotoxy(13, 10);
    headerLine();      	
			
	//bottom-left corner
   	gotoxy(12, 10);
	printf("\033[0;34m\u2514\033[0m");
					   			   
   	//bottom-right corner
	gotoxy(52, 10);
	printf("\033[0;34m\u2518\033[0m");
}

void exitBox(){
	//red-violet header line
    gotoxy(13, 3);
    redHeaderLine();
			        
    //red left side
	redSideLine(12, 4, 8);       
					
   	//red top-right corner
   	gotoxy(52, 3); 	
   	printf("\033[0;31m\u2510\033[0m\n");	 
			        
   	//red top-left corner
   	gotoxy(12, 3);
   	printf("\033[0;31m\u250C\033[0m");        
			        
	//red right side
	redSideLine(52, 4, 8); 
			        
	//red-violet footer line
    gotoxy(13, 9);
    redHeaderLine();      	
			
	//red bottom-left corner
   	gotoxy(12, 9);
	printf("\033[0;31m\u2514\033[0m");
					   			   
   	//red bottom-right corner
	gotoxy(52, 9);
	printf("\033[0;31m\u2518\033[0m");
}
#endif