#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int len = num.size();
        int cntr = int(len/2);
        for(int i=0; i < int(len/2); i++){
            if (num[i] == num[len-i-1]){
                --cntr;
            }
        }
        if (cntr == 0){
            return true;
        }
        return false;
    }
};
