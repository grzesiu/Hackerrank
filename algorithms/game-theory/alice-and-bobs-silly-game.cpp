#include <iostream>
#include <vector>

using namespace std;

int count_primes_less_than(int n)
{
    int c = 0;
    vector<bool> ns(n + 1, true);
    for(int i = 2; i <= n; i++)
    {
        if(ns[i])
        {
            c++;
            int j = 1;
            while(i * j <= n)
            {
                ns[i * j] = false;
                j++;
            }
        }
    }
    return c;
}

int main()
{
    int g, n;
    cin >> g;
    while(g--)
    {
        cin >> n;
        if(count_primes_less_than(n) % 2)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}
