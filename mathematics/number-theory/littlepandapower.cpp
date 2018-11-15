#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int LIMIT = 1000000;

vector<int> get_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

vector<int> get_totients(int n) {
    vector<int> primes = get_primes(n);
    vector<int> totients(n + 1);
    iota(begin(totients), end(totients), 0);
    for (auto prime : primes) {
        for (int i = prime; i <= n; i += prime) {
            totients[i] -= totients[i] / prime;
        }
    }
    return totients;
}

long exp(long a, int b, int x) {
    long t = 1;
    while(b) {
        if (b % 2) {
            t = (t * a) % x;
        }
        a = (a * a) % x;
        b /= 2;
    }
    return t;
}

int solve(long a, int b, int x, const vector<int>& totients) {
    if (b == 0) {
        return 1;
    } else if (b < 0) {
        a = exp(a, totients[x] - 1, x);
        b = -b;
    }
    return exp(a, b, x);
}

int main() {
    long a;
    int t, b, x;
    vector<int> totients = get_totients(LIMIT);
    cin >> t;
    while (t--) {
        cin >> a >> b >> x;
        cout << solve(a, b, x, totients) << endl;
    }
    return 0;
}
