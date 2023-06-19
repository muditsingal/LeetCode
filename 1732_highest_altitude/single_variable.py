class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        max = 0
        curr = 0
        for elem in gain:
            curr += elem
            if curr > max:
                max = curr

        return max