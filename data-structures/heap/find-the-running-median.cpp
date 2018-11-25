#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    float a, m = 0;
    priority_queue<float, vector<float>, greater<float>> min;
    priority_queue<float> max;
    cin >> n;
    cout << fixed;
    cout << setprecision(1);
    while (n--) {
        cin >> a;
        if (a <= m) {
            max.push(a);
        } else {
            min.push(a);
        }
        if (max.size() == min.size()) {
            m = (max.top() + min.top()) / 2;
        } else if (max.size() == min.size() + 1) {
            m = max.top();
        } else if (max.size() == min.size() + 2) {
            min.push(max.top());
            max.pop();
            m = (max.top() + min.top()) / 2;
        } else if (max.size() + 1 == min.size()) {
            m = min.top();
        } else {
            max.push(min.top());
            min.pop();
            m = (max.top() + min.top()) / 2;
        }
        cout << m << endl;
    }
    return 0;
}
