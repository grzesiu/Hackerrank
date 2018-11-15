#include <cstdio>
#include <set>
#include <vector>
using namespace std;

set<int> not_visited;
vector<int> counts;
vector<vector<int>> al;

void dfs(int node) {
    for (int x : al[node]) {
        auto pos = not_visited.find(x);
        if (pos != not_visited.end()) {
            ++counts.back();
            not_visited.erase(pos);
            dfs(x);
        }
    }
}
int main() {
    int a, b;
    long n, p, ans = 0;
    scanf("%ld %ld", &n, &p);
    al = vector<vector<int>>(n);
    while (p--) {
        scanf("%d %d", &a, &b);
        not_visited.insert(a);
        not_visited.insert(b);
        al[a].push_back(b);
        al[b].push_back(a);
    }
    
    long without_pair = n - not_visited.size();
    while (!not_visited.empty()) {
        int x = *not_visited.begin();
        not_visited.erase(not_visited.begin());
        counts.push_back(1);
        dfs(x);
    } 
    for (int i = 0; i < counts.size(); ++i) {
        for (int j = i + 1; j < counts.size(); ++j) {
            ans += counts[i] * counts[j];
        }
        ans += counts[i] * without_pair;
    }
    ans += ((without_pair - 1) * without_pair) / 2;
    printf("%ld\n", ans); 
    return 0;
}
