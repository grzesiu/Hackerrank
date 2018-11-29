#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

void add_edge(unordered_map<int, unordered_map<int, int>>& graph, int t, int a, int b) {
    graph[0][2 * a] = t;
    graph[2 * a][0] = 0;
    graph[2 * a][2 * b + 1] = 1;
    graph[2 * b + 1][2 * a] = 0;
    graph[2 * b + 1][1] = 1;
    graph[1][2 * b + 1] = 0;
}

vector<int> get_path(unordered_map<int, int>& parents, int next) {
    vector<int> path;
    while (next != 0) {
        path.push_back(next);
        next = parents[next];
    }
    path.push_back(next);
    return path;
}

vector<int> bfs(unordered_map<int, unordered_map<int, int>>& graph) {
    int curr;
    queue<int> q;
    unordered_set<int> visited;
    unordered_map<int, int> parents;

    q.push(0);
    while (!q.empty()) {
        curr = q.front();
        q.pop();
        visited.insert(curr);
        for (const auto& next : graph[curr]) {
            if (next.second != 0 && visited.count(next.first) == 0) {
                q.push(next.first);
                parents[next.first] = curr;
                if (next.first == 1) {
                    return get_path(parents, next.first);
                }
            }
        }
    }
    return vector<int>();
}

int get_max_flow(unordered_map<int, unordered_map<int, int>>& graph) {
    int min, max_flow = 0;
    vector<int> path = bfs(graph);
    while (!path.empty()) {
        min = INT_MAX;
        for (unsigned int i = 1; i < path.size(); ++i) {
            if (graph[path[i]][path[i - 1]] < min) {
                min = graph[path[i]][path[i - 1]];
            }
        }
        max_flow += min;
        for (unsigned int i = 1; i < path.size(); ++i) {
            graph[path[i]][path[i - 1]] -= min;
            graph[path[i - 1]][path[i]] += min;
        }
        path = bfs(graph);
    }
    return max_flow;
}

int main() {
    int c, n, t, m, a, b;
    cin >> c;
    while (c--) {
        unordered_map<int, unordered_map<int, int>> graph;
        cin >> n >> t >> m;
        while (m--) {
            cin >> a >> b;
            add_edge(graph, t, a, b);
            add_edge(graph, t, b, a);
        }
        cout << get_max_flow(graph) << endl;
    }
    return 0;
}
