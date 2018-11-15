#include <stdio.h>

long long p(long long a, int b)
{
    long long ans = 1;
    
    while(b)
    {
        if(b & 1)
            ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

int main()
{
    unsigned long long n;
    int c = 0;

    scanf("%llu", &n);
    while(n)
    {
        c += n % 2 ? 0 : 1;
        n >>= 1;
    }
    printf("%lld\n", p(2, c));
    return 0;
}
