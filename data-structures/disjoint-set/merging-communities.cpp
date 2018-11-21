#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int find_root(const vector<int> &roots, int x) {
    if (roots[x] != 0) {
        while (x != roots.at(x)) {
            x = roots[x];
        }
    }
    return x;
}

int main() {
    int n, q, x, y;
    char type;

    cin >> n >> q;

    vector<int> roots(n + 1), counts(n + 1, 1);

    for (int i = 1; i <= n; ++i) {
        roots[i] = i;
    }

    while (q--) {
        cin >> type;
        if (type == 'M') {
            cin >> x >> y;
            roots[x] = find_root(roots, x);
            roots[y] = find_root(roots, y);
            if (roots[x] != roots[y]) {
                if (counts[roots[x]] < counts[roots[y]]) {
                    swap(x, y);
                }
                counts[roots[x]] += counts[roots[y]];
                roots[roots[y]] = roots[x];
            }
        } else {
            cin >> x;
            roots[x] = find_root(roots, x);
            cout << counts[roots[x]] << endl;
        }
    }

    return 0;
}
