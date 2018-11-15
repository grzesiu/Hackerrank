#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

void dfs(std::vector<int> *al, int *descendants_no, int node)
{
    std::vector<int>::iterator it;
    for(it = al[node].begin(); it != al[node].end(); it++)
    {
        if(al[*it].size() != 0)
            dfs(al, descendants_no, *it);
        descendants_no[node] += descendants_no[*it];
    }
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int get_gcd(int a, int b)
{
    return b == 0 ? a : get_gcd(b, a % b);
}

std::vector<int> get_divisors(int n)
{
    std::vector<int> divisors;
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            divisors.push_back(i);
            if(n / i != i)
                divisors.push_back(n / i);
        }
    }
    std::sort(divisors.begin(), divisors.end());
    return divisors;
}

int* get_divisors_count(int *descendants_no, std::vector<int> divisors, int n)
{
    int gcd;
    int *count = new int[divisors.size()]();
    for(int i = 1; i < n; i++)
    {
        gcd = get_gcd(descendants_no[i], n - descendants_no[i]); 
        std::vector<int> gcd_divisors = get_divisors(gcd);
        std::vector<int>::iterator it;
        for(int j = 0; j < gcd_divisors.size(); j++)
        {
            it = find(divisors.begin(), divisors.end(), gcd_divisors.at(j));
            count[it - divisors.begin()]++;
        }
    }
    return count;
}

int main()
{
    int i, a, n;
    scanf("%d", &n);

    std::vector<int> divisors = get_divisors(n);

    std::vector<int> *al = new std::vector<int>[n];
    int *descendants_no = new int[n];

    for(i = 0; i < n; i++)
        descendants_no[i] = 1;

    for(i = 0; i < n - 1; i++)
    {
        scanf("%d", &a);
        al[a - 1].push_back(i + 1);
    }

    dfs(al, descendants_no, 0);
    delete[] al;

    int *count = get_divisors_count(descendants_no, divisors, n);

    for(i = divisors.size() - 1; i >= 0; i--)
    {
        if(n / divisors.at(i) - 1 == count[i])
            printf("%d ", n / divisors.at(i));
    }


    delete[] descendants_no, count;
    return 0;
}
