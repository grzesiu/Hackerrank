#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int q, n, i;
    unsigned long long m, prev_sum, sum, maximum; 
    set<unsigned long long> s;
    set<unsigned long long>::iterator it;

    scanf("%d", &q);
    while(q--)
    {
        scanf("%d%llu", &n, &m);
        prev_sum = 0;
        maximum = 0;
        s.insert(0);

        for(i = 0; i < n; i++)
        {
            scanf("%llu", &sum);
            sum = (prev_sum + sum) % m;

            it = s.lower_bound(sum + 1);
            if(it == s.end())
                maximum = max(sum, maximum);
            else
                maximum = max((sum - *it + m) % m, maximum);

            s.insert(sum);
            prev_sum = sum;
        }

        printf("%llu\n", maximum);
        s.clear();
    }
    return 0;
}       
