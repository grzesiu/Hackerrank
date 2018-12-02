#include <iostream>
#include <vector>

using namespace std;

int M = 1000000007;
vector<long> f(1001, 0);

void prepare_f() {
    f[0] = 1;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (i - j >= 0) {
                f[i] = (f[i] + f[i - j]) % M;
            }
        }
    }
}

long pow(long a, int b) {
    long ans = 1;
    while (b) {
        if (b % 2) {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b /= 2;
    }
    return ans;
}

int get_ways(int n, int m) {
    vector<long> g(m + 1);
    for (int i = 1; i <= m; ++i) {
        g[i] = pow(f[i], n);
    }
    vector<long> h(m + 1);
    h[1] = 1;
    for (int i = 2; i <= m; ++i) {
        h[i] = g[i];
        long temp = 0;
        for (int j = 1; j < i; ++j) {
            temp = (temp + h[j] * g[i - j]) % M;
        }
        h[i] = (h[i] - temp + M) % M;
    }
    return h[m];
}

int main() {
    prepare_f();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << get_ways(n, m) << endl;
    }
    return 0;
}
