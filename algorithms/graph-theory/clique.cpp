#include <cstdio>


int pow2(int a)
{
    return a * a;
}

int ceil(int a, int b)
{
    return (a - 1)/b + 1;
}

int edges(int n, int r)
{
    return 0.5 * (n * n - (n % r) * pow2(ceil(n, r)) - (r - (n % r)) * pow2(n / r));
}

int approx_min_clique(int n, int m)
{
    return (n * n  - 1)/(n * n  - 2 * m) + 1;
}

int exact_min_clique(int n, int m)
{
    int r = approx_min_clique(n, m);
    while(edges(n, r) < m)
        r++;
    return r;
}

int main()
{
    int t, n, m, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        printf("%d\n", exact_min_clique(n, m));
    }
    return 0;
}
