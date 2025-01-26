#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class graph {
public:
    void print_adj_list()
    {
        for(auto &node : adj_list)
        {
            cout << node.first << " -> ";
            for(auto& nbr : node.second)
                cout << nbr << " ";

            cout << "\n";
        }
    }
    void add_edges(vector<pair<int, int>> edges)
    {
        for(auto &edge : edges)
        {
            adj_list[edge.first].push_back(edge.second);
            adj_list[edge.second].push_back(edge.first);
        }
    }
    void check_cycle_und()
    {
        if(adj_list.empty())
        {
            cout << "Empty graph" << endl;
            return;
        }
        int start = adj_list.begin()->first;
        node_q.push(start);
        visited.insert(start);
        parent[start] = -1;
        int curr;
        while(!node_q.empty())
        {
            curr = node_q.front();
            node_q.pop();
            for(auto &nbr : adj_list[curr])
            {
                if(visited.count(nbr) != 0 && parent[curr] != nbr)
                {
                    cout << "Cycle present!" << endl;
                    return;
                }
                else if(visited.count(nbr) == 0)
                {
                    node_q.push(nbr);
                    parent[nbr] = curr;
                    visited.insert(nbr);
                }
            }    
        }
        cout << "Cycle is not present!" << endl;
    }
    void check_cycle_dfs_und()
    {
        int start = adj_list.begin()->first;
        int curr;
        stack<int> stk;
        stk.push(start);
        parent[start] = -1;
        while(!stk.empty())
        {
            curr = stk.top();
            stk.pop();
            for(auto &nbr : adj_list[curr])
            {
                if(visited.count(nbr) != 0 && parent[curr] != nbr)
                {
                    cout << "Cycle is present" << endl;
                    return;
                }
                else if(visited.count(nbr) == 0)
                {
                    visited.insert(nbr);
                    stk.push(nbr);
                    parent[nbr] = curr;
                }
            }
        }
        cout << "Cycle is not present" << endl;
    }

private:
    unordered_map<int, vector<int>> adj_list;
    queue<int> node_q;
    unordered_set<int> visited;
    unordered_map<int, int> parent;
};


int main()
{
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(4,5));
    edges.push_back(make_pair(5,6));
    edges.push_back(make_pair(5,7));
    edges.push_back(make_pair(6,8));
    edges.push_back(make_pair(7,8));
    edges.push_back(make_pair(8,9));
    graph g1;
    g1.add_edges(edges);
    g1.print_adj_list();
    // g1.check_cycle_und();
    g1.check_cycle_dfs_und();
    return 0;
}