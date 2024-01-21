class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0, j=0;
        std::string res = "";
        while(i < word1.length() && j < word2.length())
        {
            res.push_back(word1[i]);
            res.push_back(word2[j]);
            i++;
            j++;
        }
        if(word1.length() > word2.length())
        {
            for(; i < word1.length(); i++)
                res.push_back(word1[i]);
        }
        else
        {
            for(; j < word2.length(); j++)
                res.push_back(word2[j]);
        }
        return res;
    }
};
