#include <queue>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    queue<int> q1;
    stack<int> stk;
    cout << stk.top() << endl;
    q1.push(55);
    q1.push(23);
    q1.push(18);
    q1.push(77);
    q1.push(69);
    q1.push(2);
    while(!q1.empty())
    {
        cout << q1.front() << " " << q1.back() << " ";
        q1.pop();
    }
        
    return 0;
}