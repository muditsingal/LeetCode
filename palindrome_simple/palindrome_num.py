class Solution:
    def isPalindrome(self, x: int) -> bool:
        new_num = 0
        len_num = len(str(x))
        cpy_x = x
        i = 0
        while i < len_num:
            new_num = new_num*10 + cpy_x%10 
            cpy_x //= 10
            i += 1
        
        if new_num == x:
            return True
        return False