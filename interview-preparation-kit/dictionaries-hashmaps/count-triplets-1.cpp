#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long count_triplets(vector<int> &a, int r) {
    long ans = 0;
    unordered_map<int, long> two_to_go, one_to_go;
    for (int v : a) {
        if (one_to_go.count(v)) {
            ans += one_to_go[v];
        }
        if (two_to_go.count(v)) {
            one_to_go[v * r] += two_to_go[v];
        }
        ++two_to_go[v * r];
    }
    return ans;
}

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
	for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << count_triplets(a, r) << endl;
    return 0;
}
