class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        cntr = 0
        res = []

        for i in range(len(digits)-1,-1,-1):
            if digits[i] == 9:
                cntr += 1
                digits[i] = 0
                continue

            digits[i] += 1
            break

        if cntr >= len(digits):
            digits.append(0)
            digits[0] = 1

        return digits
