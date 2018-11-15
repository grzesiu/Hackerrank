#include <cstdio>

int main()
{
    int t, n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        if(n % 2 && m != 1)
            printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}
