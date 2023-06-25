class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = 0;
        for(i = digits.size()-1; i >= 0; i--)
        {
            if(digits[i] == 9)
            {
                digits[i] = 0;
                continue;
            }
            digits[i] += 1;
            break;
        }
        if(i < 0)
        {
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};
