#include <stdio.h>

long long int max(long int n) 
{
    return n/2*(n-1);
}

int main()
{
    long int i, j, n, u;
    long long int k, m;
    scanf("%ld%lld", &n, &k);

    for(i = 1; i < n; i++) 
    {
        m = max(n - i);
        if(m >= k)
        {
            printf("%ld", i);
        }
        else
        {
            u = i - m + k;
            printf("%ld", u);
            break;
        }
    }
    for(j = n; j >= i; j--)
    {
        if(j != u) {
            printf("%ld", j);
        }
    }
    return 0;
}
