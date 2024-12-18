#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string>::iterator it;
        unordered_map<string, vector<string>> ana_grps;
        unordered_map<string, vector<string>>::iterator ita;
        for(int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            ana_grps[str].push_back(strs[i]);
        }

        for(const auto& sub_grp: ana_grps)
        {
            res.push_back(sub_grp.second);
        }

        return res;
    }
};


int main()
{
    Solution s1;
    vector<string> strs1 = {"eat","tea","tan","ate","nat","bat"};
    s1.groupAnagrams(strs1);

    return 0;
}