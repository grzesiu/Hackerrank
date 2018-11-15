#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int w, h, as[102][102] = {};
    cin >> w >> h;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            cin >> as[i][j];
        }
    }
    int area = 2 * w * h;
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            area += abs(as[i + 1][j] - as[i][j]);
            area += abs(as[i][j + 1] - as[i][j]);
        }
    } 
    cout << area << endl;
    return 0;
}
