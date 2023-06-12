class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        res = []
        if len(nums) == 0:
            return []
        
        elif len(nums) == 1:
            return [str(nums[0])]

        j = 0
        n1 = nums[0]
        num_cnt = 0
        for i, num in enumerate(nums):
            if(j==0):
                j = 1
                continue

            if num == n1 + j:
                num_cnt += 1
                j += 1
                if not i == len(nums) - 1:
                    continue

            if num_cnt > 0:
                res.append(str(n1)+"->"+str(n1+num_cnt))
            elif num_cnt == 0:
                res.append(str(n1))

            if i == len(nums) - 1 and n1+num_cnt != num:
                res.append(str(num))

            n1 = num
            num_cnt = 0
            j = 1

        return res
