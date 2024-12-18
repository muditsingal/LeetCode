#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int main()
{
    stack<pair<int, int>> stk;
    stk.push(make_pair(5,2));
    cout << stk.top().first << " " << stk.top().second;
    return 0;
}