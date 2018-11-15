#include <cstdio>

bool is_first(int a)
{
    return (a - 1) / 2 % 2;
}

int main()
{
    int t, x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &x, &y);
        if(is_first(x) || is_first(y))
            printf("First\n");
        else
            printf("Second\n");
    }
    return 0;
}
