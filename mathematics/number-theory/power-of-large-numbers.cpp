#include <iostream>
#include <string>

using namespace std;

long M = 1000000007;

long mod(string x, int m) {
    long t = 0;
    for (int i = 0; i < x.length(); i++) {
        t = (t * 10 + x[i] - '0') % m;
    }
    return t;
}

long exp(long a, long b) {
    long t = 1;
    while (b) {
        if (b % 2) {
            t = (t * a) % M;
        }
        a = (a * a) % M;
        b /= 2;
    }
    return t;
}

long solve(string as, string bs) {
    long a = mod(as, M);
    long b = mod(bs, M - 1);
    return exp(a, b);
}

int main() {
    int t;
    string as, bs;
    cin >> t;
    while (t--) {
        cin >> as >> bs;
        cout << solve(as, bs) << endl;
    }
    return 0;
}
