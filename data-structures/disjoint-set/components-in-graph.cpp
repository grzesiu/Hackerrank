#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int find_root(int x, const vector<int> &roots) {
    while (roots[x] != x) {
        x = roots[x];
    }
    return x;
}

int main() {
    int n, g, b;
    cin >> n;
    int min = 2 * n + 1, max = 0;
    vector<int> roots(2 * n + 1);
    for (int i = 0; i < 2 * n; ++i) {
        roots[i] = i;
    }
    vector<int> ranks(2 * n + 1, 1); 
    while (n--) {
        cin >> g >> b;
        roots[g] = find_root(g, roots);
        roots[b] = find_root(b, roots);
        if (roots[g] != roots[b]) {
            ranks[roots[g]] += ranks[roots[b]];
            ranks[roots[b]] = 0; 
            roots[roots[b]] = roots[g];
        }
    }
    for (const auto &rank : ranks) {
        if (rank < min && rank > 1) {
            min = rank;
        } 
        if (rank > max) {
            max = rank;
        }
    }
    cout << min << " " << max << endl; 
    return 0;
}
