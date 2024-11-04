# include<stdio.h>
int main (void)
{
    int x, y, j;

    for (x=0; x<10; x++)
    {
            for (y=x; y<10; y++)
            {
                j++;
                printf("the count is %i", j);
            }
    }
}
