#include <iostream>
#include <vector>

using namespace std;

long gcd(long a, long b) {
    while (a && b) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

int main() {
    long n, x;
    cin >> n;
    vector<long> a(n);
    vector<vector<long>> g(2, vector<long>(n, 0));
    for (long i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] + 1;
        return 0;
    }
    for (long i = 0; i < n - 1; i++) {
        g[0][i + 1] = gcd(g[0][i], a[i]);
        g[1][i + 1] = gcd(g[1][i], a[n - i - 1]);
    }
    for (long i = 0; i < n - 1; i++) {
        x = gcd(g[0][i], g[1][n - i - 1]);
        if (a[i] % x) {
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}
