#include <stdio.h>

int next(int k, int p);
int main()
{
    printf("input:");
    int a,b;
    scanf("%d/%d", &a, &b);

    printf("0.");

    for (int i = 0; i < 200; i++)
    {
        a *= 10;
        printf ("%d", a / b);
        if (a % b == 0)
        {
            break;
        }
        else
        {
            a = a % b;
          //a %= b；
        }
    }
    return 0;
}
