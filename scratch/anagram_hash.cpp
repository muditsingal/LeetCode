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
            unordered_map<string, vector<string>> ana_grps;
            
            for(const auto& s : strs)
            {
                vector<int> shards(26, 0);
                for(const auto& ch: s)
                    shards[int(ch) - int('a')] += 1;

                string key = "";
                for(int i = 0; i < 26; i++)
                    while(shards[i] > 0)
                    {
                        key.push_back(char(int('a')+i));
                        shards[i]--;
                    }

                ana_grps[key].push_back(s);
            }

            for(const auto& ana_grp : ana_grps)
            {
                res.push_back(ana_grp.second);
            }
               


        // for(const auto& sub_grp: ana_grps)
        // {
        //     res.push_back(sub_grp.second);
        // }

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