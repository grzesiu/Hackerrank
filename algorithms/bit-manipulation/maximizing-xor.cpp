#include <cstdio>
int main()
{
    int l, r;
    scanf("%d%d", &l, &r);
    int value = l ^ r;
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    printf("%d\n", value);
    return 0;
}
