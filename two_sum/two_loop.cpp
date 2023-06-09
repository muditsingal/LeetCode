#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        // for(auto i = nums.begin(); i != nums.end() - 1; i++)
        for(int i = 0; i < nums.size()-1; i++)
        {
            cout<<nums[i]<<" ";
            for(int j = i+1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};
