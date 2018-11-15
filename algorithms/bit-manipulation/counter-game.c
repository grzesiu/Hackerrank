#include <stdio.h>
#include <stdint.h>

unsigned int count_ones(unsigned long long v)
{
    unsigned int c = 0;
    while(v)
    {
        c++;
        v &= v - 1;
    }
    return c;
}


unsigned int count_trailing_zeros(unsigned long long v)
{
    unsigned int c = 0;
    while(!(v & 1))
    {
        c++;
        v >>= 1;
    }
    return c;
}

int main()
{
    int t, c;
    unsigned long long v;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%llu", &v);
        c = count_ones(v) + count_trailing_zeros(v);
        if(c % 2)
            printf("Richard\n");
        else
            printf("Louise\n");
    }
    return 0;
}
