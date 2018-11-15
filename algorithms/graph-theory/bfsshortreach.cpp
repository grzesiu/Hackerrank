#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int EDGE_LEN = 6;

void bfs(vector<vector<int> > al, int curr, int n)
{
    vector<int>::iterator it;
    vector<int> distances(n, -1);
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(curr);
    distances[curr] = 0;
    visited[curr] = true;

    while(!q.empty())
    {
        curr = q.front();
        q.pop();

        for(it = al[curr].begin(); it != al[curr].end(); it++)
        {
            if(!visited[*it])
            {
                distances[*it] = distances[curr] + EDGE_LEN;
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
    
    for(it = distances.begin(); it != distances.end(); it++)
        if(*it != 0)
            printf("%d ", *it);
    printf("\n");
}

int main()
{
    int t, n, m, n1, n2, start;
    vector<vector<int> > al;
    vector<int> ans;
    scanf("%d", &t);
    
    while(t--)
    {
        scanf("%d%d", &n, &m);
        
        al = vector<vector<int> >(n);
        while(m--)
        {
            scanf("%d%d", &n1, &n2);
            n1--;
            n2--;
            al[n1].push_back(n2);
            al[n2].push_back(n1);
        }
        
        scanf("%d", &start);
        start--;
        bfs(al, start, n);
        
    }
    return 0;
}
