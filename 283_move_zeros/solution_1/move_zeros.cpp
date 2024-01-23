class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> res;
        int n_zeros = 0;
        for(auto elem : nums) {
            if(elem == 0)
            {
                n_zeros++;
                continue;
            }
            res.push_back(elem);
        }
        for(; n_zeros > 0; n_zeros--)
            res.push_back(0);

        nums = res;
    }
};
