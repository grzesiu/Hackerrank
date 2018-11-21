#include <iostream>
#include <stack>
using namespace std;

int main() {
    int q, type, x;
    stack<int> first, second;
    cin >> q;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            first.push(x);
        } else {
            if (second.empty()) {
                while (!first.empty()) {
                    second.push(first.top());
                    first.pop();
                }
            }
            if (type == 2) {
                second.pop();
            } else {
                cout << second.top() << endl;
            }
        }
    }
    return 0;
}
