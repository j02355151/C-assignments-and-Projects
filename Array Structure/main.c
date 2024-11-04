#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char lname[25];
    char fname[25];
    float gpa;
    int age;

}
student;

const int num_students = 10;
//here is where we will use the comment from the assignment to create the array
int main()
{
    student thisclass[num_students];
    char lname[25];
    char fname[25];
    float gpa;
    int age;
//The loop is created to store the information of every student so we can access them within the thisclass array.
    for (int i = 0; i < num_students; i++)
    {
        printf("Enter student information %i\n", i + 1);
        printf("Enter student's Last name: ");
        scanf("%s", lname);
        printf("Enter student's First name: ");
        scanf("%s", fname);
        printf("Enter student's GPA: ");
        scanf("%f", &gpa);
        printf("Enter student's Age: ");
        scanf("%i", &age);
        printf("\n");

        strcpy(thisclass[i].lname, lname);
        strcpy(thisclass[i].fname, fname);
        thisclass[i].gpa = gpa;
        thisclass[i].age = age;
//here will be the information displayed when we access them
    }
    printf("-------------------\n");
    printf("Student Information\n");
    printf("-------------------\n");
    for (int i= 0; i < num_students; i++)
    {
        printf("Name: %s %s\n", thisclass[i].fname, thisclass[i].lname);
        printf("GPA: %.2f\n", thisclass[i].gpa);
        printf("Age: %i\n", thisclass[i].age);
        printf("***********\n");
    }
    return 0;
}
