#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    vector<int> ans(n, 1);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            ans[i] += ans[i - 1];
        }
    }
    for (int i = n - 1; i > 0; --i) {
        if (ans[i - 1] <= ans[i] && arr[i - 1] > arr[i]) {
            ans[i - 1] = ans[i] + 1;
        }
    }
    cout << accumulate(ans.begin(), ans.end(), (long)0) << endl;
    return 0;
}
