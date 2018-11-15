#include <cstdio>
#include <algorithm>

using namespace std;

void prepare_array(int *a, int n)
{
    int *temp = new int[n];
    for(int i = 0; i < n; i++)
        temp[i] = a[i];
    sort(temp, temp + n);
    
    for(int i = 0; i < n; i++)
        a[i] = lower_bound(temp, temp + n, a[i]) - temp + 1;
}

int get_lower_count(int *bit, int x)
{
    int lower_count = 0;

    while(x > 0)
    {
        lower_count += bit[x];
        x -= x & (-x);
    }
    return lower_count;
}

void add_to_bit(int *bit, int x, int n)
{
    while(x <= n)
    {
        bit[x]++;
        x += x & (-x);
    }
}

long get_shifts_count(int *a, int n)
{
    long shifts_count = 0;
    int *bit = new int[n + 1];

    prepare_array(a, n);
     
    for(int i = 1; i <= n; i++)
        bit[i] = 0;
    
    for(int i = n - 1; i > 0; i--)
    {
        shifts_count += get_lower_count(bit, a[i] - 1);
        add_to_bit(bit, a[i], n);
    }

    shifts_count += get_lower_count(bit, a[0] - 1);
    delete[] bit;
    return shifts_count;
}

int main()
{

    int t, n, *a;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        a = new int[n];
    
        for(int i = 0; i < n; i++)
            scanf("%d", a + i);
        
        printf("%lli\n", get_shifts_count(a, n));
        delete[] a;    
    }
    return 0;
}
