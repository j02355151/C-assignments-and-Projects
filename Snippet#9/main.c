# include <stdio.h>

int main (void)
{
char A = "A";
short B = 150;
long X = 105000;
char A2 = "B";
char A3 = "C";

printf("the address of A3 is % d" , &A3)
;
printf("\nthe address of A2 is % d" , &A2)
;
printf("\nthe address of X is % d" , &X)
;
printf("\nthe address of B is % d" , &B)
;
printf("\nthe address of A is % d" , &A)
;
return 0;
}

