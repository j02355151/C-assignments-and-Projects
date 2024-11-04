#include <stdio.h>
#include <stdlib.h>

int main()
{
    //These are the 10 different variables for 10 different numbers
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int num6;
    int num7;
    int num8;
    int num9;
    int num10;

    //We have to type 10 different statements for inputting 10 variables
    printf("Enter values of 10 numbers\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);
    scanf("%d", &num4);
    scanf("%d", &num5);
    scanf("%d", &num6);
    scanf("%d", &num7);
    scanf("%d", &num8);
    scanf("%d", &num9);
    scanf("%d", &num10);

    //Here we get the sum of all the operators
    int sum = num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10;
    printf("Sum of values of 10 numbers : %d\n", sum);

    //loops and array example

    //Declare 10 variables using only 1 statement
    int numbers[10];
    int i, newsum = 0;

    //values of 10 numbers using a loop
    printf("Enter values of 10 numbers\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &numbers[i]);

    //Do sum using a loop
    for (i = 0; i < 10; i++)
        newsum = newsum + numbers[i];

    //Now display the sum
    printf("Sum of values of 10 numbers array and loop is : %d\n", newsum);


    return 0;
}
