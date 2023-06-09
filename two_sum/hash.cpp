#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int compl1;
        unordered_map<int, int> hash_m;
        for(int i = 0; i < nums.size(); i++)
        {
            compl1 = target - nums[i];
            if (hash_m.find(compl1) != hash_m.end())
            {
                res.push_back(hash_m.at(compl1));
                res.push_back(i);
                break;
            }
            hash_m.insert(make_pair(nums[i], i));

        }
        return res;
    }
};
