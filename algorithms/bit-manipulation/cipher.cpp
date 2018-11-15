#include <cstdio>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    char *s = new char[n + k + 2];
    char *a = new char[n];

    scanf("%s", s);
    
    for(int i = 0; i < n + k - 1; i++)
    {
        s[i] -= 48;
    }

    a[0] = s[0];
    for(int i = 1; i < k; i++)
    {
        a[i] = s[i] ^ s[i - 1];
    }

    for(int i = k; i < n; i++)
    {
        a[i] = a[i - k] ^ s[i - 1] ^ s[i];
    }

    for(int i = 0; i < n; i++)
        printf("%d", a[i]);
    printf("\n");


}
