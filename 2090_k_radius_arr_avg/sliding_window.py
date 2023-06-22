import numpy as np
class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        avg_arr = [-1]*n
        window_size = 2*k+1
        if n < window_size:
            return avg_arr
        
        sum1 = 0
        sum1 = sum(nums[0:window_size])

        avg_arr[k] = int(sum1/window_size)
        for i in range(k+1,n-k):
            sum1 = sum1 - nums[i-k-1] + nums[i+k]
            avg_arr[i] = int(sum1/window_size)

        return avg_arr
