#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

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
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 4));

    for(int i = 0; i < m; i++)
    {
        // add edge to the graph
        g1.add_edge(edges[i].first, edges[i].second);
        g1.add_adj_mtx(edges[i].first, edges[i].second);
    }

    g1.print_adj_list();
    g1.print_adj_mtx();

    return 0;
}