#include <stdio.h>

typedef struct
{
    int power;
    int coefficient;
} term;

int main()
{    
    const int MAX = 101;
    term item[MAX];

    for (int i = 0; i < MAX; i++)
    {
        item[i].coefficient = 0;
        item[i].power = 0;
    }

    int a,b;
    for (int i = 0; i < 2; i++)
    {
        do
        {
            scanf("%d %d", &a, &b);
            item[a].power = a;
            item[a].coefficient += b;
        } while (item[a].power > 0);
    }

    for (int i = MAX - 1; i >= 0; i--)
    {
        if (item[i].coefficient != 0)
        {
            if (item[i].power == 1)
            {
                printf("%dx+", item[i].coefficient);
            }
            else if (item[i].power == 0)
            {
                printf("%d\n", item[i].coefficient);
            }
            else
            {
                printf("%dx%d+",item[i].coefficient, item[i].power);
            } 
        }
    }
}
