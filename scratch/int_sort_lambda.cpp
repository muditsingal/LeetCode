#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    int thres = 20;
    a.push_back(6);
    a.push_back(3);
    a.push_back(33);
    a.push_back(23);
    a.push_back(7);
    a.push_back(1);
    a.push_back(69);

    sort(a.begin(), a.end(), [](int a, int b) { return a < b;});

    for(const auto& it: a)
    {
        cout << it << " ";
    }

    return 0;
}