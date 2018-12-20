#include <iostream>
#include <vector>

using namespace std;

void minimum_bribes(const vector<int> &q) {
    int ans = 0;
    for (int i = 0; i < q.size(); ++i) {
        if (q[i] - 3 > i) {
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j = max(0, q[i] - 2); j < i; ++j) {
            if (q[j] > q[i]) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

	while (t--) {
        int n;
        cin >> n;
        vector<int> q(n);

        for (int i = 0; i < n; i++) {
			cin >> q[i];
        }

        minimum_bribes(q);
    }

    return 0;
}

