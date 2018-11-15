#include <cstdio>

int main()
{
    int i, g, n, k, *s, ns;
    scanf("%d", &g);
    while(g--)
    {
        scanf("%d%d", &n, &k);

        s = new int[n];

        for(i = 0; i < n; i++)
            scanf("%d", s + i);
        
        ns = s[0];
        for(i = 1; i < n; i++)
            ns ^= s[i];

        if(ns)
            printf("First\n");
        else
            printf("Second\n");
        
        delete[] s;
    }
    return 0;
}
