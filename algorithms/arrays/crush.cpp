#include <cstdio>

int main()
{
    int n, m, a, b, k, i, *t;
    long sum = 0, max = 0;
    scanf("%d%d", &n, &m);
    t = new int[n + 1];
    for(i = 1; i <= n; i++)
        t[i] = 0;

    for(i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &k);
        t[a] += k;
        if(b < n)
            t[b + 1] -= k;
    }

    for(i = 1; i <= n; i++)
    {
        sum += t[i];
        if(max < sum)
            max = sum;
    }

    printf("%lli\n", max);
    return 0;
}
