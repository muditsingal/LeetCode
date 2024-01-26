class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        sum1 = sum(nums[:k])
        max_sum = sum1

        for i in range(k,len(nums)):
            sum1 -= nums[i-k]
            sum1 += nums[i]
            if(sum1 > max_sum):
                max_sum = sum1

        return float(max_sum / k)