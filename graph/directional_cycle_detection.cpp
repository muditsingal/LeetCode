#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class graph {
public:
    void add_edge(int v1, int v2, int dir)
    {
        adj_list[v1].push_back(v2);
        if(dir == 0)
            adj_list[v2].push_back(v1);
    }
    void print_adj_list()
    {
        for(auto &node : adj_list)
        {
            cout << node.first << " -> ";
            for(auto &nbr : node.second)
                cout << nbr << " ";

            cout << "\n";
        }
    }
    void check_cycle_dfs_d()
    {
        stack<int> stk;
        int start = adj_list.begin()->first;
        int curr;
        stk.push(start);
        // dfs_called.insert(start);
        // visited.insert(start);
        while(!stk.empty())
        {
            curr = stk.top();
            stk.pop();
            visited.insert(curr);
            dfs_called.insert(curr);
            cout << curr << " ";
            for(auto &nbr : adj_list[curr])
            {
                if(visited.count(nbr) == 0)
                {
                    visited.insert(nbr);
                    stk.push(nbr);
                }
                else if(dfs_called.count(nbr) != 0)
                {
                    cout << "Cycle present!!" << endl;
                    return;
                }    
            }
            dfs_called.erase(curr);
        }
        cout << "Cycle not present!" << endl;
    }
    bool check_dir_cycle_dfs_recur(int node)
    {
        visited.insert(node);
        dfs_called.insert(node);
        for(auto &nbr : adj_list[node])
        {
            if(visited.count(nbr) == 0)
            {
                bool cycle_det = check_dir_cycle_dfs_recur(nbr);
                if(cycle_det)
                    return true;
            }
            else if(dfs_called.count(nbr) != 0)
            {
                return true;
            }    
        }
        dfs_called.erase(node);
        return false;
    }
private:
    map<int, vector<int>> adj_list;
    unordered_set<int> visited;
    unordered_set<int> dfs_called;
};

int main()
{
    vector<pair<int, int>> edges;
    graph g1;
    g1.add_edge(1,2,1);
    g1.add_edge(2,3,1);
    g1.add_edge(2,4,1);
    g1.add_edge(3,7,1);
    g1.add_edge(3,8,1);
    g1.add_edge(4,5,1);
    g1.add_edge(5,6,1);
    g1.add_edge(6,4,1);
    g1.add_edge(8,7,1);

    g1.print_adj_list();
    bool cycle_present = g1.check_dir_cycle_dfs_recur(1);
    if(cycle_present)
        cout << "Cycle is present!" << endl;
    else    
        cout << "Cycle is not present!!!!" << endl;

    return 0;
}