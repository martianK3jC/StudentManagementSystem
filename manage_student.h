#include <stdio.h>
#include "student.h"
void viewStudents(){
	//Testing: Sample array of students

	struct Student students[3] = {
		{"Kesha Jane L. Ceniza", 19, 3242005, "Computer Engineering", "Magnolia Town, Fiore, Ishgar", "	quackersnackercracker@duck.com"},
		{"Kiarra Jane L. Ceniza", 9, 3252015, "Science", "Curva, Medellin, Cebu", "duckeshaquack2x@duck.com"},
		{"Random Name", 200, 1234567, "Magic", "Magic Land", "duckeshaquack2x@duck.com"}
	};


printf("List of Students:\n\n");

for (int i = 0; i < 3; i++){
	printf("Name: %s\n", students[i].name);
	printf("Age: %d\n", students[i].age);
	printf("Id: %d\n", students[i].id);
	printf("Course: %s\n", students[i].course);
	printf("Address: %s\n", students[i].address);
	printf("Email: %s\n", students[i].email);
	printf("\n\n");
}

}




