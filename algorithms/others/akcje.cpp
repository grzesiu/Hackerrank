#include <stdio.h>

int main() {
    int n, m, *v, a, b, i, temp, sum = 0;
    scanf("%d %d", &n, &m);
    v = new int[n+1];


    v[0] = 0;
    for(i = 1; i < n + 1; i++) {
        scanf("%d", &temp);
        sum += temp;
        v[i] = sum;
    }

    while(m--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", v[b] - v[a-1]);

    }
    return 0;
}
