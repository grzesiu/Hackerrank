#include <bits/stdc++.h>

using namespace std;


bool check(vector<string>& g, vector<string>& p, int sr, int sc, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(g[sr + i][sc + j] != p[i][j])
                return false;
        }
    }
    return true;
}

string has_pattern(vector<string>& g, vector<string>& p, int R, int C, int r, int c)
{
    for(int i = 0; i <= R - r; i++)
    {
        for(int j = 0; j <= C - c; j++)
        {
            if(check(g, p, i, j, r, c))
                return "YES";
        }
    }
    return "NO";
}
int main()
{
    int t, R, C, r, c;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        cin >> R >> C;
        vector<string> g(R);
        for(int i = 0; i < R; i++)
            cin >> g[i];
        cin >> r >> c;
        vector<string> p(r);
        for(int i = 0; i < r; i++)
            cin >> p[i];

        cout << has_pattern(g, p, R, C, r, c) << endl;
        
    }
    return 0;
}
