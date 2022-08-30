#include <stdio.h>
#include <math.h>

int isprime();
int main()
{
    //read n and m
    int n,m;
    printf("input:");
    scanf("%i %i", &n, &m);
    //sum primes
    int sum = 0;
    int a = 1, j = 2;

    do
    {
        if (isprime(j))
        {
            if (a >= n)
            {
                sum += j;
                a++;
            }
            else
            {
                a++;
            }
        }
        j++;
    }
    while (a <= m);
    
    printf("%i", sum);
}

int isprime(int j)
{
    for (int i = 2; i <= (int)sqrt(j); i++)
    {
        if ((j % i == 0) && j > 2)
        {
            return 0;
        }
    }
    return 1;
}
