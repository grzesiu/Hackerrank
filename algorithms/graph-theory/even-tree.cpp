#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > al;
vector<bool> visited;
int n, m, ans = 0; 

int dfs(int node)
{
    visited[node] = true;
    int desc_no = 0;

    for(int i = 0; i < al[node].size(); i++)
    {
        if(!visited[al[node][i]])
            desc_no += dfs(al[node][i]);
    }
    desc_no++;

    if(desc_no % 2 == 0)
        ans++;

    return desc_no;
}

int main()
{
    int x, y;
    scanf("%d%d", &n, &m);
    
    al = vector<vector<int> >(n + 1);
    visited = vector<bool>(n + 1, false);

    while(m--)
    {
        scanf("%d%d", &x, &y);
        al[x].push_back(y);
        al[y].push_back(x);
    }

    dfs(1);
    printf("%d\n", ans - 1);
    return 0;
}
