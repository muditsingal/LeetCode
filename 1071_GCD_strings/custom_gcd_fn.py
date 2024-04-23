class Solution:
    def findGCD(self,str1: str, str2:str):
        n1 = len(str1)
        n2 = len(str2)
        while n2:
            n1, n2 = n2, n1 % n2

        return n1

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        gcd = self.findGCD(str1, str2)
        if (str1[:gcd]*(len(str1) // gcd) == str1) and (str1[:gcd]*(len(str2) // gcd) == str2):
            return str1[:gcd]

        return ""
