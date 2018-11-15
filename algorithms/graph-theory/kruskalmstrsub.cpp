#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <map>

using namespace std;

class DisjointSet 
{

    struct Node
    {
        int data, rank;
        Node *parent;
    };

    map <int, Node*> nodes;
   
    public:

    DisjointSet(int n)
    {
        for(int i = 1; i <= n; i++)
            make_set(i);
    }

    ~DisjointSet()
    {
        for(map<int, Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
            delete[] it->second;
    }

    void make_set(int x)
    {
        Node *node = new Node();
        node->data = x;
        node->rank = 0;
        node->parent = node;
        nodes.insert(pair<int, Node*>(x, node));
    }

    void merge(int x, int y)
    {
        Node *x_root = find(nodes.find(x)->second);
        Node *y_root = find(nodes.find(y)->second);
        
        if(x_root == y_root)
            return;
        else if(x_root->rank < y_root->rank)
            x_root->parent = y_root;
        else if(y_root->rank < x_root->rank)
            y_root->parent = x_root;
        else
        {
            y_root->parent = x_root;
            x_root->rank++;
        }
    }

    int find(int x)
    {
        return find(nodes.find(x)->second)->data;
    }

    Node* find(Node *x)
    {
        if(x->parent != x)
            x->parent = find(x->parent);
        return x->parent;
    }
};


struct Edge
{
    int x, y, r;

    bool operator >(const Edge &rhs) const
    {
        return r > rhs.r;
    }
};

int kruskal(priority_queue<Edge, vector<Edge>, greater<Edge> > &q, int n)
{
    DisjointSet ds(n);
    Edge current;
    int sum = 0;
    
    while(!q.empty())
    {
        current = q.top();
        q.pop();

        if(ds.find(current.x) != ds.find(current.y))
        {
            ds.merge(current.x, current.y);
            sum += current.r;
        }
    }

    return sum;
}

int main()
{
    int n, m;
    Edge e;
    priority_queue<Edge, vector<Edge>, greater<Edge> > q;

    scanf("%d%d", &n, &m);

    while(m--)
    {
        scanf("%d%d%d", &e.x, &e.y, &e.r);
        q.push(e);
    }

    printf("%d\n", kruskal(q, n));

    return 0;
}
