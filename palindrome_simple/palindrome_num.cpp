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
        if (x<0){
            return false;
        }
        int x_cpy = x;
        int i = 0, new_num = 0;
        while (i < len) {
            new_num = new_num*10 + x_cpy%10;
            x_cpy = int(x_cpy / 10);
            i += 1;
        }
        if (x == new_num){
            return true;
        }
        return false;
    }
};
