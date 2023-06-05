class Solution:
    def isPalindrome(self, x: int) -> bool:
        str_x = str(x)
        str_len = len(str_x)
        cntr = str_len//2
        
        for i in range(str_len//2):
            if str_x[i] == str_x[str_len-i-1]:
                cntr -= 1
        if cntr == 0:
            return True
        return False