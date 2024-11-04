#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define MAX_HASHTABLE_SIZE 20

typedef struct Node {

char name[20];

struct Node *next;

}

Node;

Node *hashTable[MAX_HASHTABLE_SIZE];

int hashFunction(char name[]) {

int sum = 0;

for (int i = 0; i < strlen(name); i++) {

sum += name[i];

}

return sum % MAX_HASHTABLE_SIZE;

}

void insertName(char name[]) {

Node *newNode = (Node *)malloc(sizeof(Node));

strcpy(newNode->name, name);

newNode->next = NULL;

int index = hashFunction(name);

if (hashTable[index] == NULL) {

hashTable[index] = newNode;

}

else {

Node *current = hashTable[index];

while (current->next != NULL) {

current = current->next;

}

current->next = newNode;

}

}

int searchName(char name[]) {

int index = hashFunction(name);

if (hashTable[index] == NULL) {

return 0;

}

Node *current = hashTable[index];

while (current != NULL) {

if (strcmp(current->name, name) == 0) {

return 1;

}

current = current->next;

}

return 0;

}

int main() {

int choice;

while (1) {

printf("\n1. Enter a new name\n");

printf("2. Search for a name\n");

printf("3. Exit\n");

printf("Enter your choice: ");

scanf("%d", &choice);

switch (choice) {

case 1: ;

char name[20];

printf("Enter a last name: ");

scanf("%s", name);

insertName(name);

break;

case 2: ;

char search_name[20];

printf("Enter a last name to search: ");

scanf("%s", search_name);

if (searchName(search_name)) {

printf("Name found\n");

}

else {

printf("Name not found\n");

}

break;

case 3:

printf("Exiting...\n");

return 0;

default:

printf("Invalid choice\n");

}

}

}
