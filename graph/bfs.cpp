#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <unordered_set>

using namespace std;

class graph {

public:
    void add_edges(vector<pair<int, int>> &edges)
    {
        for(auto &edge : edges)
        {
            adj_list[edge.first].push_back(edge.second);
            adj_list[edge.second].push_back(edge.first);
        }
    }

    void print_graph()
    {
        for(auto &node : adj_list)
        {
            cout << node.first << " -> ";
            for(auto &nbr : node.second)
                cout << nbr << " ";
            cout << "\n";
        }
    }

    void print_bfs(int start)
    {
        if(adj_list.find(start) == adj_list.end())
            return;
        fifo.push(start);
        visited.insert(start);
        while(!fifo.empty())
        {
            cout << fifo.front() << " ";
            for(auto& node : adj_list[fifo.front()])
            {
                if(visited.count(node) == 0)
                {
                    fifo.push(node);
                    visited.insert(node);
                }
            }
            fifo.pop();
        }
    }
private:
    map<int, vector<int>> adj_list;
    unordered_set<int> visited;
    queue<int> fifo;
};

int main()
{
    vector<pair<int, int>> edges;
    graph g1;


    // Case 1:
    /*
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 4));
    */

    // Case 2:
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(1, 4));

    g1.add_edges(edges);
    // g1.print_graph();
    g1.print_bfs(0);
    return 0;
}