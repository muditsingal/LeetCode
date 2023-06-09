class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}
        for i, n in enumerate(nums):
            comp = target - n
            val = hash_map.get(comp)
            if val is not None:
                return [val, i]

            hash_map[n] = i

        return []