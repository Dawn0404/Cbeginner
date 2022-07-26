#include <stdio.h>
#include <math.h>

int main()
{
    printf("input:");
    int n;
    scanf("%d", &n);
    int x = 0;

    for(int i = 1; i <= 6; i++)
    {
        int t = n % 10;
        n = (n - t) / 10;
        
        if ((i + t) % 2 == 0)
        {
            x += pow(2, i - 1);
        }
    }
    printf("output:%d\n", x);
}
