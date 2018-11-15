#include <iostream>
#include <vector>

using namespace std;

const char MAX_X = 100;

int main()
{
    int n, x, i = 0;
    string s;
    vector<vector<string>> a(MAX_X);

    scanf("%d", &n);       
    for(; i < n/2; i++)
    {
        cin >> x >> s;
        a[x].push_back("-");
    }

    for(; i < n; i++)
    {
        cin >> x >> s;
        a[x].push_back(s);
    }
    
    for(i = 0; i < MAX_X; i++)
    {
        for(int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
    }
    
    return 0;
}
