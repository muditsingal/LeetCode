#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int idx1, idx2;
        vector<string> op_arr;
        // cout<<nums.size();
        int j = 0;
        if(nums.size() == 0)
            return op_arr;
        for(int i = 0; i < nums.size(); i++)
        {
            idx1 = nums[i];
            idx2 = nums[i+j];
            
            while ((idx2 - j) == idx1)
            {
                ++j;
                if(i+j >= nums.size())
                    break;
                idx2 = nums[i+j];
            }
            if(j==1)
            {
                op_arr.push_back(to_string(idx1));
            }
            else
            {
                op_arr.push_back(to_string(idx1) + "->" + to_string(nums[i+j-1]));
                i += j - 1;
            }
            j = 0;
            
        }
        return op_arr;
    }
};
