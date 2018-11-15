#include <cstdio>

int n, m, **mat;

int region_size(int x, int y)
{
    int size = 1;
    mat[x][y] = 2;
    for(int i = x - 1; i <= x + 1; i++)
        for(int j = y - 1; j <= y + 1; j++)
            if(i > -1 && j > -1 && i < n && j < m)
                if(mat[i][j] == 1)
                    size += region_size(i,j);
    return size;
}

int max_region()
{
    int max = 0;
    int temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == 1)
            {
                temp = region_size(i, j);
                if(temp > max)
                    max = temp;
            }
        }
    }
    return max;
}

int main()
{
    scanf("%d%d", &n, &m);

    mat = new int*[n];
    for(int i = 0; i < n; i++)
    {
        mat[i] = new int[m];
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }            
    }
    printf("%d\n", max_region());

    for(int i = 0; i < n; i++)
        delete[] mat[i];
    delete[] mat;
    return 0;
}
