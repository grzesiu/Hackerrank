#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main()
{
    int n, k, a, max_size = 0;
    
    cin >> n >> k;
    vector<int> as(k, 0);

    for(int i = 0; i < n; i++)
    {
        cin >> a;
        as[a % k]++;
    }

    if(as[0] > 0)
        max_size++;

    if(k % 2 == 0 && as[k / 2] != 0)
        max_size++;

    for(int i = 1; i <= (k - 1) / 2; i++)
    {
        max_size += max(as[i], as[k - i]);
    }
    cout << max_size << endl;

    return 0;
}
