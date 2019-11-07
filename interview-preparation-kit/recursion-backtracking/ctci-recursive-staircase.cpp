#include <bits/stdc++.h>

using namespace std;

const long M = 10000000007;

vector<long> ways(37);

long stepPerms(int n) {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else {
        if (ways[n] == 0) {
            ways[n] = (stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3)) % M;
        }
        return ways[n];
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        std::fill(ways.begin(), ways.end(), 0);
        cout << stepPerms(n) << endl;
    }
    return 0;
}

