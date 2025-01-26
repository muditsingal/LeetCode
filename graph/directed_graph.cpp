#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

class graph {
public:
    void print_graph()
    {
        for(auto &nbr : adj_list)
        {
            cout << nbr.first << " -> ";
            for(auto &node : nbr.second)
                cout << node << " ";
            cout << "\n";
        }
    }
    void add_edge(int v1, int v2, int d)
    {
        if(!d)
            adj_list[v2].push_back(v1);
        adj_list[v1].push_back(v2);
    }
    void topological_sort(int node)
    {
        visited.insert(node);
        for(auto &nbr : adj_list[node])
        {
            if(visited.count(nbr) == 0)
            {
                visited.insert(nbr);
                topological_sort(nbr);
            }
        }
        topo_stk.push(node);
    }
    void print_topo()
    {
        while(!topo_stk.empty())
        {
            cout << topo_stk.top() << " ";
            topo_stk.pop();
        }
    }
private:
    map<int, vector<int>> adj_list;
    unordered_set<int> visited;
    unordered_set<int> dfs_called;
    stack<int> topo_stk;
};

int main()
{
    graph g1;
    g1.add_edge(1, 2, 1);
    g1.add_edge(2, 3, 1);
    g1.add_edge(2, 4, 1);
    g1.add_edge(3, 7, 1);
    g1.add_edge(3, 8, 1);
    g1.add_edge(4, 5, 1);
    g1.add_edge(5, 6, 1);
    g1.add_edge(4, 6, 1);
    g1.add_edge(8, 7, 1);

    // g1.print_graph();

    g1.topological_sort(1);
    g1.print_topo();


    return 0;
}