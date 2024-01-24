class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last_non_zero = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                continue;
            swap(nums[last_non_zero+1], nums[i]);
            last_non_zero++;
        }
    }
};
