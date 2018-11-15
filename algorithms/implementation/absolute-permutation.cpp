#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    int t, n, k, tmp;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        if(k == 0)
        {
            for(int x = 1; x <= n; x++)
                cout << x << " ";
        }
        else if(n % (2 * k) == 0)
        {
            tmp = k;
            for(int i = 1; i <= n; i++)
            {
                cout << i + tmp << " ";
                if(i % k == 0)
                {
                    tmp = -tmp;
                }
            }
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }

    return 0;
}
