#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        vector<vector<int>> a(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 1; i < n; ++i) {
            a[i][0] = max(a[i - 1][0], a[i - 1][1] + b[i - 1] - 1);
            a[i][1] = max(a[i - 1][0] + b[i] - 1, a[i - 1][1] + abs(b[i] - b[i - 1]));
        }
        cout << max(a[n - 1][0], a[n - 1][1]) << endl;
    }
    return 0;
}
