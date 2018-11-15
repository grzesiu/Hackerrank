#include <iostream>
using namespace std;
int main()
{
    unsigned int t;
    unsigned long long l, r, ans;
    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> l >> r;

        if(l % 4 > 0 && l % 4 < 3)
        {
            ans = l + 1;
        }
        else if(l % 4 == 0)
        {
            ans = 2;
        }
        if(r % 4 < 2)
        {
            ans ^= r;
        }
        else
        {
            ans ^= 2;
        }
        ans ^= (r / 4 - l / 4 - 1) % 2 * 2;
        cout << ans << endl;
    }
    return 0;
}
