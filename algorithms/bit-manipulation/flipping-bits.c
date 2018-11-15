#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    uint8_t t;
    uint32_t i;
    scanf("%"SCNd8, &t);
    while(t--)
    {
        scanf("%d", &i);
        printf("%u\n", i ^ UINT32_MAX);
    }
    return 0;
}
