class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        merged_str = str()
        i = 0
        j = 0
        while i < len(word1) and j < len(word2):
            merged_str += word1[i]
            merged_str += word2[j]
            i += 1
            j += 1

        if len(word1) > len(word2):
            merged_str += str(word1[i:])

        else:
            merged_str += str(word2[j:])

        return merged_str