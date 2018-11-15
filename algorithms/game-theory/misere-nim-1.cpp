#include <cstdio>

int main()
{
    int i, g, n, *s, ns;
    bool ones_only;
    scanf("%d", &g);
    while(g--)
    {
        ones_only = true;

        scanf("%d", &n);

        s = new int[n];

        for(i = 0; i < n; i++)
            scanf("%d", s + i);


        for(i = 0; i < n; i++)
        {
            if(s[i] > 1)
            {
                ones_only = false;
                break;    
            }
        }

        if(ones_only)
        {
            ns = !(n % 2);
        }
        else
        {
            ns = s[0];
            for(i = 1; i < n; i++)
                ns ^= s[i];
        }
        if(ns)
            printf("First\n");
        else
            printf("Second\n");

        delete[] s;
    }
    return 0;
}
