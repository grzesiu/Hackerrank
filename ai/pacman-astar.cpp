#include <cstdio>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

static const char WALL = '%';    
static const char PATH = '_';    
static const char FOOD = '.';    
static const char PACMAN = 'P';    


struct Point
{
    int x, y;

    Point() {}

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

struct Node 
{
    Node *parent;
    Point coords;
    int f_cost, g_cost;
    bool visited;
    char symbol;

    Node(){}

    Node(Node *parent, Point coords, int f_cost, int g_cost, bool visited)
    {
        this->parent = parent;
        this->coords = coords;
        this->f_cost = f_cost;
        this->g_cost = g_cost;
        this->visited = visited;
    }

    Node(Point coords, char symbol)
    {
        this->coords = coords;
        this->symbol = symbol;
        parent = NULL;
        f_cost = INT_MAX;
        g_cost = INT_MAX;
        visited = false;
    }

    int cost() const
    {
        return f_cost + g_cost;
    }
};

struct CompNodePtrs
{
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        if(lhs->cost() < rhs->cost())
            return true;
        else if(lhs->cost() == rhs->cost())
            return lhs->g_cost < rhs->g_cost;
        else
            return false;
    }
};

int abs(int x)
{
    return x < 0 ? -x : x;
}

int get_g_cost(Point p1, Point p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

class A_star_search
{
    Point pacman_coords, food_coords;
    Node ***graph;
    priority_queue<Node*, vector<Node*>, CompNodePtrs> q;

    public:
    A_star_search(Point pacman_coords, Point food_coords, Node ***graph)
    {
        this->pacman_coords = pacman_coords;
        this->food_coords = food_coords;
        this->graph = graph;
    }

    Node* a_star_search()
    {
        Node *pacman = new Node(NULL, pacman_coords, 0, get_g_cost(pacman_coords, food_coords), true);
        q.push(pacman);
        while(pacman->symbol != FOOD)
        {
            update_neighbours(pacman);
            while(!q.empty() && q.top()->visited)
            {
                q.pop();
            }

            pacman = q.top();
            pacman->visited = true;
            q.pop();
        }
        
        return pacman;
    }

    private:
    void update_neighbour(int dx, int dy, Node *parent)
    {
        int x = parent->coords.x + dx;
        int y = parent->coords.y + dy;
        if(graph[x][y]->symbol != WALL && !graph[x][y]->visited)
        {

            if(parent->f_cost + 1 < graph[x][y]->f_cost)
            {
                graph[x][y]->parent = parent;
                graph[x][y]->f_cost = parent->f_cost + 1;
                graph[x][y]->g_cost = get_g_cost(graph[x][y]->coords, food_coords);
                q.push(graph[x][y]);
            }
        }
    } 

    void update_neighbours(Node *parent)
    {
        update_neighbour(1, 0, parent);
        update_neighbour(-1, 0, parent);
        update_neighbour(0, 1, parent);
        update_neighbour(0, -1, parent);
    }
};

Node* reverse_do(Node *end)
{
    if(end->parent->parent != NULL)
    {
        Node *start= reverse_do(end->parent);
        end->parent->parent = end;
        return start;
    }
    else
    {
        end->parent->parent = end;
        return end -> parent;
    }
}

Node* reverse(Node *end)
{
    Node *start = reverse_do(end);
    end -> parent = NULL;
    return start;
}

int main()
{
    Point pacman_coords, food_coords;
    int r, c;
    Node ***graph;

    scanf("%d%d%d%d%d%d\n", &pacman_coords.x, &pacman_coords.y, &food_coords.x, &food_coords.y, &r, &c);
    graph = new Node**[r];

    for(int i = 0; i < r; i++)
    {
        graph[i] = new Node*[c];
        for(int j = 0; j < c; j++)
        {
            graph[i][j] = new Node(Point(i,j), getchar());
        }
        getchar();
    }

    Node *end =  A_star_search(pacman_coords, food_coords, graph).a_star_search();

    printf("%d\n", end->cost());

    Node *start = reverse(end);

    while(start != NULL)
    {
        printf("%d %d\n", start->coords.x, start->coords.y);
        start = start->parent;
    }

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            delete[] graph[i][j];
        }
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
