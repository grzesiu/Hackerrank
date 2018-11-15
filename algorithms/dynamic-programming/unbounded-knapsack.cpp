#include <cstdio>

int max(int a, int b)
{
    return a > b ? a : b;
}

void add_new_item(int *ks[2], int curr, int ks_weight, int curr_weight)
{
    for(int i = 1; i <= ks_weight; i++)
    {
        if(i < curr_weight)
            ks[curr][i] = max(ks[curr][i - 1], ks[1 - curr][i]);
        else
            ks[curr][i] = max(ks[1 - curr][i], max(ks[curr][i - 1], curr_weight + ks[1 - curr][i - curr_weight]));
    }
}

int get_max_value(int *ks[2], int *items, int items_no, int ks_weight)
{
    int curr = 0;
    for(int i = 0; i < items_no; i ++)
    {
        for(int j = 1; j * items[i] <= ks_weight; j++)
        {
            curr = 1 - curr;
            add_new_item(ks, curr, ks_weight, items[i]);
        }
    }
    return ks[curr][ks_weight];
}

int main()
{
    int t, i, items_no, ks_weight, *items, *ks[2];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &items_no, &ks_weight);

        for(i = 0; i < 2; i++)
            ks[i] = new int[ks_weight + 1]();

        items = new int[items_no];
        for(i = 0; i < items_no; i++)
            scanf("%d", items + i);

        printf("%d\n", get_max_value(ks, items, items_no, ks_weight));
        delete[] items, ks[0], ks[1];
    }
    return 0;
}
