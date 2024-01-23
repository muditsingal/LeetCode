class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n_zeros = 0
        res = []
        for elem in nums:
            if elem == 0:
                n_zeros += 1
                continue
            
            res.append(elem)

        for _ in range(n_zeros):
            res.append(0)

        nums.clear()
        for elem in res:
            nums.append(elem)
