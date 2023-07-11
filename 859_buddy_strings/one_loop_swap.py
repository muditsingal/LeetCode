class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        s_len = len(s)
        if(s_len != len(goal) or s_len == 1):
            return False

        c1 = '0'
        c2 = '0'
        new_str = list(s)
        
        if s == goal:
            for i in range(s_len-1):
                for j in range(i+1, s_len):
                    if s[i] == goal[j]:
                        return True

            return False

        for i in range(s_len):
            if c1 == s[i] and c2 == goal[i]:
                new_str[j], new_str[i] = new_str[i], new_str[j]
                new_str = ''.join(s[idx] if idx != i else c2 for idx in range(len(s)))
                new_str = ''.join(new_str[idx] if idx != j else c1 for idx in range(len(s)))
                break

            if s[i] != goal[i]:
                c1 = goal[i]
                c2 = s[i]
                j = i

        return new_str == goal