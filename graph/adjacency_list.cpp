#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

class graph {
public:
    graph(int n)
    {
        adj_mtx = vector<vector<bool>>(n, vector<bool>(n));
    }
    void add_edge(int v1, int v2)
    {
        adj_list[v1].push_back(v2);
        adj_list[v2].push_back(v1);
    }
    void add_adj_mtx(int v1, int v2)
    {
        adj_mtx[v1][v2] = 1;
        adj_mtx[v2][v1] = 1;
    }
    void print_adj_list()
    {
        cout << "The adjacency list of graph is: " << "\n";
        for(auto& node: adj_list)
        {
            cout << node.first << " -> ";
            for(auto& v : node.second)
                cout << v << " ";

            cout << "\n";
        }
    }

    vector<int> shortest_path_bfs(int start, int goal)
    {
        vector<int> res;
        unordered_set<int> visited;
        unordered_map<int, int> parent;
        queue<int> node_q;
        int curr;
        if(adj_list[start].size() == 0)
        {
            cout << "Invalid start node" << endl;
            return res;
        }
        else if(adj_list[goal].size() == 0)
        {
            cout << "Invalid goal node" << endl;
            return res;
        }
        visited.insert(start);
        node_q.push(start);
        parent[start] = -1;
        while(!node_q.empty())
        {
            curr = node_q.front();
            node_q.pop();
            if(curr == goal)
                break;
            for(auto &nbr : adj_list[curr])
            {
                if(visited.count(nbr) == 0)
                {
                    parent[nbr] = curr;
                    visited.insert(nbr);
                    node_q.push(nbr);
                }
            }
        }

        while(curr != -1)
        {
            res.push_back(curr);
            curr = parent[curr];
        }

        for(int i = 0; i < res.size()/2; i++)
            swap(res[i], res[res.size()-i-1]);

        return res;
    }

    void print_adj_mtx()
    {
        for(int i = 0; i < adj_mtx.size(); i++)
        {
            for(int j = 0; j < adj_mtx.size(); j++)
                cout << adj_mtx[i][j] << " ";
            cout << "\n";
        }
    }

private:
    map<int, vector<int>> adj_list;
    vector<vector<bool>> adj_mtx;
};

int main()
{
    int n = 5; // number of nodes
    int m = 6; // number of edges

    vector<pair<int, int>> edges;
    graph g1(n);

    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(0, 3));

    edges.push_back(make_pair(1, 4));
    edges.push_back(make_pair(2, 5));
    edges.push_back(make_pair(3, 10));

    edges.push_back(make_pair(4, 7));
    edges.push_back(make_pair(5, 8));
    edges.push_back(make_pair(6, 7));
    edges.push_back(make_pair(7, 10));
    edges.push_back(make_pair(8, 9));
    edges.push_back(make_pair(9, 10));


    for(int i = 0; i < edges.size(); i++)
        g1.add_edge(edges[i].first, edges[i].second);

    // g1.print_adj_list();
    vector<int> path = g1.shortest_path_bfs(0, 10);
    for(auto &node : path)
        cout << node << " ";

    cout << endl;

    return 0;
}