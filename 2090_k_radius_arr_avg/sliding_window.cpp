class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int window_size = 2*k+1;
        vector<int> avg_arr(n, -1);
        if(nums.size() < window_size)
            return avg_arr;
        long long int sum = 0;
        int i = 0;

        for(i = 0; i < 2*k+1; i++)
        {
            sum += nums[i];
        }
        avg_arr[k] = int(sum/window_size);

        for(i = k+1; i < n - k; i++)
        {
            sum = sum - nums[i-k-1];
            sum = sum + nums[i+k];
            avg_arr[i] = int(sum/window_size);
        }

        return avg_arr;

    }
};
