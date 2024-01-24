class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        last_non_zero = -1
        for i in range(len(nums)):
            if nums[i] == 0:
                continue

            t1 = nums[last_non_zero+1]
            nums[last_non_zero+1] = nums[i]
            nums[i] = t1
            last_non_zero += 1

