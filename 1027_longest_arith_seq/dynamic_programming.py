class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        seq_arr = {}
        n = len(nums)

        for right_idx in range(0, n):
            for left_idx in range(0, right_idx):
                diff = nums[right_idx] - nums[left_idx]
                seq_arr[(right_idx, diff)] = seq_arr.get((left_idx, diff), 1) + 1

        return max(seq_arr.values())