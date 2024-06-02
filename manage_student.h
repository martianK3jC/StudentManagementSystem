#include <stdio.h>
#include "student.h"
void viewStudents(){

	struct Student students[3] = {};


printf("List of Students:\n\n");

for (int i = 0; i < 3; i++){
	printf("Name: %s\n", students[i].name);
	printf("Age: %d\n", students[i].age);
	printf("Id: %d\n", students[i].id);
	printf("Degree: %s\n", students[i].degree);
	printf("Address: %s\n", students[i].address);
	printf("Email: %s\n", students[i].email);
	printf("\n");
}

}




