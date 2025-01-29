#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>

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
    vector<int> kahn_topo_sort(int v, int e)
    {
        queue<int> topo_q;
        vector<int> indegree(v);
        vector<int> res;
        int curr;
        // Find initial indegree vector
        for(auto &node : adj_list)
            for(auto &nbr : node.second)
                indegree[nbr] += 1;

        // Push node(s) with 0 indegree into queue
        for(int i = 0; i < indegree.size(); i++)
        {
            if(indegree[i] == 0)
                topo_q.push(i);
        }

        while(!topo_q.empty())
        {
            // Pop the front of queue
            curr = topo_q.front();
            topo_q.pop();

            // Update answer with popped element of queue
            res.push_back(curr);

            // Find neighbours of popped element of queue
            for(auto &nbr : adj_list[curr])
            {
                // Update indegree map
                indegree[nbr] -= 1;
                if(indegree[nbr] == 0)
                {
                    topo_q.push(nbr);
                }
            }
        }

        // Update indegree map and repeat until no more elements remain in indegree
        for(vector<int>::iterator it = res.begin(); it != res.end(); it++)
            cout << *it << " ";

        cout << "\n";

        return res;
    }
    void check_cycle(int v, int e)
    {
        vector<int> indegree(v);
        int cnt = 0;
        queue<int> node_q;
        int curr;

        // Update indegree vector
        for(auto &node : adj_list)
            for(auto &nbr : node.second)
                indegree[nbr] += 1;

        for(int i = 0; i < indegree.size(); i++)
            if(indegree[i] == 0)
                node_q.push(i);

        while(!node_q.empty())
        {
            curr = node_q.front();
            node_q.pop();
            cnt += 1;
            for(auto &nbr : adj_list[curr])
            {
                indegree[nbr] -= 1;
                if(indegree[nbr] == 0)
                    node_q.push(nbr);
            }
        }
        if(cnt == v)
            cout << "Cycle is not present!" << "\n";
        else
            cout << "Cycle is present!!!" << "\n";
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

    // Case 1:
    g1.add_edge(0, 1, 1);
    g1.add_edge(1, 2, 1);
    g1.add_edge(2, 3, 1);
    g1.add_edge(2, 4, 1);
    g1.add_edge(3, 7, 1);
    g1.add_edge(3, 8, 1);
    g1.add_edge(4, 5, 1);
    g1.add_edge(5, 6, 1);
    g1.add_edge(6, 4, 1);
    g1.add_edge(8, 7, 1);

    g1.kahn_topo_sort(9, 10);
    g1.check_cycle(9, 10);


    // Case 2:
    // g1.add_edge(0, 3, 1);
    // g1.add_edge(0, 1, 1);
    // g1.add_edge(1, 2, 1);
    // g1.add_edge(3, 2, 1);
    // g1.add_edge(2, 4, 1);


    // g1.print_graph();

    // g1.topological_sort(0);
    // g1.kahn_topo_sort(5, 5);
    // g1.check_cycle(5, 5);


    return 0;
}