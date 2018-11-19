#include <iostream>
#include <unordered_map>
using namespace std;

long n;
unordered_map<long, long> roots, counts;

long find_root(long x) {
    if (roots[x] != 0) {
        while (x != roots.at(x)) {
            x = roots[x];
        }
    }
    return x;
}

long get_triplets_count() {
    long c = n * (n - 1) * (n - 2);
    for (const auto &count : counts) {
        long t = count.second;
        c -= t * (t - 1) * (3 * n - 2 * t - 2);
    }
    return (c / 6) % 1000000007;
}

int main() {
    long x, y;
    char color;
    cin >> n;
    for (long i = 0; i < n - 1; ++i) {
        cin >> x >> y >> color;
        if (color == 'b') {
            roots[x] = find_root(x);
            roots[y] = find_root(y);
            if (counts[roots[x]] < counts[roots[y]]) {
                long temp = x;
                x = y;
                y = temp;
            }
            if (counts[roots[x]] == 0) {
                counts[roots[x]] = 2;
            } else if (counts[roots[y]] == 0) {
                counts[roots[x]] += 1;
            } else {
                counts[roots[x]] += counts[roots[y]];
                counts[roots[y]] = 0;
            }
            roots[roots[y]] = roots[x];
        }
    }
    cout << get_triplets_count() << endl;
    return 0;
}
