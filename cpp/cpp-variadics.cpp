#include <iostream>
using namespace std;

template <bool last>
int reversed_binary_value()
{
    return last;
}

template <bool head, bool neck, bool...tail> 
int reversed_binary_value()
{
    return reversed_binary_value<neck, tail...>() * 2 + head;
}

template <int n, bool...digits>
struct CheckValues {
    static void check(int x, int y)
    {
        CheckValues<n-1, 0, digits...>::check(x, y);
        CheckValues<n-1, 1, digits...>::check(x, y);
    }
};

template <bool...digits>
struct CheckValues<0, digits...> {
    static void check(int x, int y)
    {
        int z = reversed_binary_value<digits...>();
        cout << (z+64*y==x);
    }
};

int main()
{
    int t; cin >> t;
    for (int i=0; i!=t; ++i) {
        int x, y;
        cin >> x >> y;
        CheckValues<6>::check(x, y);
        cout << "\n";
    }
}
