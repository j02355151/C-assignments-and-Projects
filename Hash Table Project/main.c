#include <stdio.h>

#include <string.h>

#define MAX_NAMES 50

typedef struct {

char name[20];

} Lastname;

int main() {

int choice, num_names = 0;

Lastname names[MAX_NAMES];

while (1) {

printf("\n1. Enter a new name\n");

printf("2. Search for a name\n");

printf("3. Exit\n");

printf("Enter your choice: ");

scanf("%d", &choice);

switch (choice) {

case 1:

if (num_names == MAX_NAMES) {

printf("List full\n");

break;

}

printf("Enter a last name: ");

scanf("%s", names[num_names].name);

num_names++; break;

case 2: ;

char search_name[20];

int found = 0;

printf("Enter a last name to search: ");

scanf("%s", search_name);

for (int i = 0; i < num_names; i++) {

if (strcmp(names[i].name, search_name) == 0) {

found = 1;

printf("Name found\n");

break;

}

}

if (!found) {

printf("Name not found\n"); }

break;

case 3:

printf("Exiting...\n");

return 0;

default:

printf("Invalid choice\n");

}

}

}
