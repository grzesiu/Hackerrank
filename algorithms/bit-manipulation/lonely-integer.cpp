#include <cstdio>
using namespace std;
int main()
{
    int n, x, y = 0;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &x);
        y ^= x;
    }
    printf("%d\n", y);
    return 0;
}
