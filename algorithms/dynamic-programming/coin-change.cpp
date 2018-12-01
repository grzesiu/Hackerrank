#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> coins(m);
    for (int i = 0; i < m; ++i) {
        cin >> coins[i];
    }
    vector<vector<long>> counts(n + 1, vector<long>(m + 1, 0));
    for (int i = 0; i < m; ++i) {
        counts[0][i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            counts[i][j] = counts[i][j + 1];
            if (i - coins[j] >= 0) {
                counts[i][j] += counts[i - coins[j]][j];
            }
        }
    }
    cout << counts[n][0] << endl;
    return 0;
}

