#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int a;

};


int main()
{
    vector<pair<string, int>> name_frz;
    vector<pair<int, int>> freq_vec(11);
    vector<int> tmp(5);
    tmp[3] = 6;
    for(auto& j: tmp)
        cout << j << " ";


    auto p1 = make_pair("hritvik",69);
    auto p2 = make_pair("suraj",6);
    auto p3 = make_pair("arka",2);
    name_frz.push_back(p1);
    name_frz.push_back(p2);
    name_frz.push_back(p3);
    name_frz.push_back(make_pair("hhh", 3));
    vector<pair<string,int>>::iterator it;

    for(it = name_frz.begin(); it != name_frz.end(); it++)
    {
        cout << it->first << " " << it->second << "\n";
    }

    sort(name_frz.begin(), name_frz.end(),[](pair<string, int>& l, pair<string, int>& r){return l.second > r.second;});
    cout << "Sorted vector of pairs is: " << '\n';
    for(it = name_frz.begin(); it != name_frz.end(); it++)
    {
        cout << it->first << " " << it->second << "\n";
    }

    return 0;
}