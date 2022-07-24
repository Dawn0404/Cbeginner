#include <stdio.h>
int main()
{
    int n1 = 0, n2 = 0;
    int j;
    printf("input:");
    do
    {
        scanf("%i", &j);

        if (j % 2 == 1)
        {
            n1++;
        }
        else if (j % 2 == 0)
        {
            n2++;
        }
    }
    while (j > 0);

    printf("%i %i", n1, n2);
}
