#include <iostream>
using namespace std;

unsigned int MOD = 1000000007;

int main()
{
    unsigned int t, n, temp, a;
    cin >> t;
    while(t--)
    {
        a = 0;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            a |= temp;
        }
        for(int i = 0; i < n - 1; i++)
        {
            a = (a << 1) % MOD;
        }
        cout << a << endl;
    }
    return 0;
}
