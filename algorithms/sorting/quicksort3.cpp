#include <cstdio>

int n;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *a, int lo, int hi)
{

    int p = lo;

    for(int j = lo; j < hi; j++)
    {
        if(a[j] <= a[hi])
        {
            swap(a[p], a[j]);
            p++;
        }
    }
    swap(a[p], a[hi]);
    return p;
}

void quicksort(int *a, int lo, int hi)
{
    if(lo < hi)
    {
        int p = partition(a, lo, hi);
        for(int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
        quicksort(a, lo, p-1);
        quicksort(a, p+1, hi);
    }
}

int main()
{
    scanf("%d", &n);
    int *a = new int[n];
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);

    quicksort(a, 0, n - 1);
    delete[] a;
    return 0;
}

