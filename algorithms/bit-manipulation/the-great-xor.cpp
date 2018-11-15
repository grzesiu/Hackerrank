#include <bits/stdc++.h>

using namespace std;

long theGreatXor(long x) 
{
    return pow(2, 64 - __builtin_clzll(x)) - x - 1;
}

int main() 
{
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++)
    {
        long x;
        cin >> x;
        long result = theGreatXor(x);
        cout << result << endl;
    }
    return 0;
}
