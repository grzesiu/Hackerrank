#include <iostream>
#include <vector>

using namespace std;

int lsi(const vector<int>& a, int n) {
    int l = 0;
    vector<int> b(n + 1);
    for (int i = 0; i < n; ++i) {
        int lo = 1;
        int hi = l;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (a[b[mid]] < a[i]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        b[lo] = i;
        if (lo > l) {
            l = lo;
        }
    }
    return l;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << lsi(a, n);
    return 0;
}

