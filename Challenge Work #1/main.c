#include<stdio.h>

total_syllables(n)
{
    int result;
    result = ((22*n*(1+n))/2)+(37*n);

    return result;

}

int main()

{

int n; 

printf("Enter the number of verses: ");

scanf("%d", &n);

int all_syllables = total_syllables(n);

printf("Total syllables after%d verses: %d\n", n, all_syllables);

return 0;

}
