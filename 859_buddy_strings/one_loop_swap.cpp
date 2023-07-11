class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() == 1)
            return false;

        if(s.length() != goal.length())
            return false;

        if(s == goal)
        {
            for(int i=0; i<s.length()-1; i++)
            {
                for(int j=i+1; j<s.length();j++)
                    if (s[i] == goal[j])
                        return true;
            }
            return false;
        }

        char c1, c2;
        char tmp;
        int count=0;
        int j=0;

        for(int i=0; i < s.length(); i++)
        {
            if(c1 == goal[i] && c2 == s[i])
            {
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
                break;
            }
            if(s[i] != goal[i])
            {
                j=i;
                c1 = s[i];
                c2 = goal[i];
            }
        }

        return s == goal;
    }
};
