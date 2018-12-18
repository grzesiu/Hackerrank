#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n, m;
    unordered_map<int, vector<pair<int, int>>> graph;

    cin >> n >> m;

    while (m--) {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back(make_pair(b, cost));
        graph[b].push_back(make_pair(a, cost));
    }

    int s, t;
    queue<pair<int, int>> q;
    unordered_map<int, unordered_set<int>> distances;

    cin >> s >> t;
    distances[s].insert(0);
    q.push(make_pair(s, 0));

    while (!q.empty()) {
        auto[a, distance_a] = q.front();
        q.pop();
        for (auto[b, cost] : graph[a]) {
            int distance_b = distance_a | cost;
            if (distances[b].count(distance_b) == 0 && distance_b < 1024) {
                distances[b].insert(distance_b);
                q.push(make_pair(b, distance_b));
            }
        }
    }

    if (distances[t].empty()) {
        cout << "-1" << endl;
    } else {
        cout << *min_element(distances[t].begin(), distances[t].end()) << endl;
    }

    return 0;
}
