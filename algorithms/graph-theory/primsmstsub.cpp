#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <map>

#define INF 1000000000

struct compar
{
    bool operator()(std::pair<int, int> const &left, std::pair<int, int> const &right) const
    {
        return left.second < right.second;
    }
};

std::pair<int, int> extract_min(std::map<int, int> &distances)
{
    std::pair<int, int> min = *min_element(distances.begin(), distances.end(), compar());
    distances.erase(min.first);
    return min;
}

std::map<int, int> get_initial_distances(int size, int starting_node)
{
    std::map<int, int> distances;
    for(int i = 1; i <= size; i++)
        distances[i] = INF;

    distances[starting_node] = 0;
    return distances;
}

int prim(std::unordered_map<int, std::unordered_map<int, int> > &al, int starting_node)
{
    int total_weight = 0;
    std::map<int, int> distances = get_initial_distances(al.size(), starting_node);
    std::pair<int, int> curr;
    
    while(!distances.empty())
    {
        curr = extract_min(distances);
        total_weight += curr.second;
        for(auto it = al[curr.first].begin(); it != al[curr.first].end(); it++)
        {
            if(distances.find(it->first) != distances.end() && distances[it->first] > it->second)
            {
                distances[it->first] = it->second;
            }
        }
    }
    return total_weight;
}

void add(std::unordered_map<int, std::unordered_map<int, int> > &al, int x, int y, int w)
{
    auto it = al[x].find(y);
    if(it == al[x].end() || al[x][y] > w)
    {
        al[x][y] = w;
        al[y][x] = w;
    }
}

int main()
{
    int n, m, s, x, y, w;
    scanf("%d%d", &n, &m);
    std::unordered_map<int, std::unordered_map<int, int> > al(n);

    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &x, &y, &w);
        add(al, x, y, w);
    }

    scanf("%d", &s);

    printf("%d\n", prim(al, s));

    return 0;
}
