#include <cstdio>
        
int main()
{       
    int n, start, end, i, j, m, temp;
    scanf("%d", &n);
        
    int *a = new int[n];
    for(i = 0; i < n; i++)
        scanf("%d", a + i);
        
    m = n / 2;
    start = 0;
    end = n - 1;
         
    while(start < end)
    {   
        i = start;
        j = end;
        do
        {
            while(a[i] < a[m]) i++;
            while(a[j] > a[m]) j--;
            if(i <= j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
        }while(i <= j);
        if(j < m) start = i;
        if(i > m) end = j;
    }   
    printf("%d\n", a[m]);
    delete[] a;
    return 0;
}       
