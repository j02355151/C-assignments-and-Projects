#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100];
    printf("What string do you want to reverse? ");
    scanf("%s", str1);
    int l= strlen(str1);
    char str2[l];
    int i=0,j=0;
    for (i=l-1;i>=0;--i)
    {
        str2[j]=str1[i];
        ++j;
    }
    printf("Reversed String: %s\n", str2);
}
