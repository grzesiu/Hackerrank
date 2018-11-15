#include <iostream>
#include <cmath>

using namespace std;

int closestNumber(int a, int b, int x) {
    int ab = pow(a, b);
    int n = ab / x;
    int r = ab % x;
    if (r <= x / 2 ) {
        return n * x;
    } else {
        return (n + 1) * x;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b >> x;
        cout << closestNumber(a, b, x) << endl;
    }
    return 0;
}
