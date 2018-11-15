#include <cstdio>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int calc_sgv(vector<int>);
void add_to_parents(int);
void update_sg(int);
void init_sg(int);

unordered_map<int, vector<int>> children;
unordered_map<int, vector<int>> parents;
unordered_map<int, multiset<int>> sg_sets;
unordered_map<int, int> sgs;

int calc_sgv(multiset<int> sg_set)
{
    int prev = -1;
    for(auto const &sg : sg_set)
    {
        if(sg - prev > 1)
        {
            return prev + 1;
        }
        else
        {
            prev = sg;
        }
    }
    return prev + 1;
}

void add_to_parents(int c)
{
    for(auto const &p : parents[c])
    {
        sg_sets[p].insert(sgs[c]);
        update_sg(p);
    }
}

void update_sg(int c)
{
    if(sg_sets[c].size() == children[c].size())
    {
        int sgv = calc_sgv(sg_sets[c]);
        sgs[c] = sgv;
        add_to_parents(c);
    }
}

void init_sg(int n)
{
    for(int c = 1; c <= n; c++)
    {
        if(children[c].size() == 0)
        {
            update_sg(c);
        }
    }
}

int main()
{
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        children[u].push_back(v);
        parents[v].push_back(u);
    }

    init_sg(n);

    int t, k, b, ans;
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        scanf("%d", &k);
        while(k--)
        {
            scanf("%d", &b);
            ans ^= sgs[b];
        }
        printf("%s\n", ((ans == 0) ? "Iroh" : "Bumi"));
    }
    return 0;
}
