#include <iostream>

using namespace std;

long M = 1000000007;

long exp(long a, long b, long m) {
    long t = 1;
    while (b) {
        if (b % 2) {
            t = a * t % m;
        }
        a = a * a % m;
        b /= 2;
    }
    return t;
}

long number_of_subsets(long n) {
    long b = (exp(2, n, M - 1) - n) % (M - 1);
    if (b < 0) {
        b += M - 1;
    }
    return exp(2, b, M);
}

int main() {
    long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << number_of_subsets(n) << endl;
    }
    return 0;
}
