#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct triple
{
    int a, b, m;

    bool operator==(const triple &x) const
    {
        return (x.a == a && x.b == b && x.m == m);
    }
};

struct KeyHasher
{
    std::size_t operator()(const triple& k) const
    {
        using std::size_t;
        using std::hash;
        using std::string;

        return ((hash<int>()(k.a)
                    ^ (hash<int>()(k.b) << 1)) >> 1)
            ^ (hash<int>()(k.m) << 1);
    }
};

unordered_map<triple, int, KeyHasher> memo;

int choose(int a, int b, int m)
{
    if(b > a || b < 0)
    {
        return 0;
    } 
    else if(b == 0 || a == b)
    {
        return 1;
    }
    else if(a >= m)
    {
        return choose(a / m, b / m, m) * choose(a % m, b % m, m) % m;
    }

    triple t = {a, b, m};
    unordered_map<triple, int, KeyHasher>::iterator it = memo.find(t);

    if(it == memo.end())
    {
        int v = (choose(a - 1, b - 1, m) + choose(a - 1, b, m)) % m;
        memo[t] = v;
    }
    return memo[t];
}

vector<int> factorize(int n)
{
    vector<int> pfs;
    int p = 2;
    while(p <= n)
    {
        if(p * p > n)
            p = n;
        while(n % p == 0)
        {
            pfs.push_back(p);
            n /= p;
        }
        p++;
    }
    return pfs;
}

pair<int, int> ee(int a, int b)
{
    if(b == 0)
    {
        return pair<int, int>(1, 0);
    }
    else
    {
        pair<int, int> xy = ee(b, a % b);
        return pair<int, int>(xy.second, xy.first - a / b * xy.second);
    }
}

vector<int> dtn(int a, int n)
{
    vector<int> x;
    while(a)
    {
        x.push_back(a % n);
        a /= n;
    }
    return x;
}



int main()
{
    int t, n, r, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> r >> m;

        cout << ee(n, r).first << " " << ee(n, r).second << endl;
        //cout << choose(n, r, m);
        //for(auto x : factorize(n))
        //    cout << x << " ";
        //int nbm = dtn(n, m);
        //int rbm = dtn(r, m);

    }
    return 0;
}
