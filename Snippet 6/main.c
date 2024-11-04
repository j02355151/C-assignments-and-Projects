#include <stdio.h>
long fact(int);
int fact1(int);
int main()
{
    long res;
    int x ;
    printf(" enter the number for factorial ");
    scanf("%d",&x);
    fact1(x);
    res = fact(x);
    printf("The result of recursive method for factorial is %ld\n",res);
    return 0;
}
int fact1(int a) { //interactive version
    int i;
    long ans1 = 1;
    for (i=a;i>=1;i--) {
        ans1 = ans1 * i;
    }
    printf("The factorial of a given number is %ld \n " , ans1);
    return 0;
}
long fact(int x1) { // recursive version
    long ans = 1;
    if (x1 == 1) {
        return 1;
    }
    else {
        ans = x1 * fact(x1-1);
        return ans;
    }
}
