#include <iostream>
using namespace std;
int main()
{
    unsigned int t, a, b, c, i, ans;

    cin >> t;

    while(t--)
    {
        ans = 0;
        i = 32;
        cin >> a >> b;
        while(i > 0)
        {
            i--;
            c = a & (1 << i);
            if(c == (b & (1 << i)))
            {
                ans += c;
            }
            else
            {
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
