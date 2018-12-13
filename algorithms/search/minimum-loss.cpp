#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long, int>> prices(n);
    for (int i = 0; i < n; ++i) {
        long t;
        cin >> t;
        prices[i] = make_pair(t, i);
    }
    sort(prices.begin(), prices.end());
    long min = LONG_MAX;
    for (int i = 1; i < n; ++i) {
        long diff = prices[i].first - prices[i - 1].first;
        if (diff < min && prices[i].second < prices[i - 1].second) {
            min = diff;
        }
    }
    cout << min << endl;
    return 0;
}
