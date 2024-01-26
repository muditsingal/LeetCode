class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum1 = 0.0;
        int i;
        for(i = 0; i < k; i++) {
            sum1 += nums[i];
        }
        int max_sum = sum1;
        for(i = k; i < nums.size(); i++) {
            sum1 += nums[i] - nums[i - k];
            if(sum1 > max_sum)
                max_sum = sum1;
        }
        return double(max_sum) / k;
    }
};
