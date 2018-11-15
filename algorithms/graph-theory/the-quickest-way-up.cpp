#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define BOARD_SIZE 100

struct queue_entry
{
    int v, dist;
    queue_entry(int v, int dist): v(v), dist(dist) {}
};

int bfs(vector<vector<int>> &board)
{
    queue<queue_entry> q;
    vector<bool> visited(BOARD_SIZE + 1, false);
    queue_entry qe = {1, 0};
    q.push(qe);

    while(!q.empty())
    {
        qe = q.front();
        q.pop();
        visited[qe.v] = true;
        for(int u : board[qe.v])
        {
            if(!visited[u])
            {
                if(u == BOARD_SIZE)
                {
                    return qe.dist + 1;
                }
                else
                {
                    q.push(queue_entry(u, qe.dist + 1));
                }
            }
        }
    }
    return -1;
}

int main()
{
    int t, n, m, i, j;
    vector<vector<int>> board(BOARD_SIZE + 1);

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d %d", &i, &j);
            board[i].push_back(j);
        }

        scanf("%d", &m);
        while(m--)
        {
            scanf("%d %d", &i, &j);
            board[i].push_back(j);
        }
        for(i = 1; i < BOARD_SIZE; i++)
        {
            if(board[i].empty())
            {
                for(int j = 1; j < 7; j++)
                {
                    if(i + j <= BOARD_SIZE)
                    {
                        if(board[i+j].empty())
                            board[i].push_back(i+j);
                        else
                            board[i].push_back(board[i+j][0]);
                    }
                }
            }
        }

        printf("%d\n", bfs(board));

        for(i = 1; i <= BOARD_SIZE; i++)
        {
            board[i].clear();
        }
    }
    return 0;
}
