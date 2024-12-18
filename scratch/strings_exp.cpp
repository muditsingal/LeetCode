#include <vector>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;


class soln
{
public:
    string encode(vector<string> strs)
    {
        string enc_str;
        int wlen;
        for(auto& word: strs)
        {
            wlen = word.size();
            enc_str.append(to_string(wlen) + ";" + word);
        }
        cout << enc_str << endl;
        return enc_str;
    }
    vector<string> decode(string &str) {
        vector<string> dec_str;
        int i=0, j=0, len = 0;
        while(i < str.size())
        {
            j = i;
            len = int(str[i]) - 48;
            cout << len << "\n";
            while(str[j] != ';')
                j += 1;
            dec_str.push_back(str.substr(j+1,len));
            i = j + 1 + len;
        }
        return dec_str;
    }
};

int main()
{
    string str;
    soln s1;
    vector<string> input_words = {"we","say",":","yes","!@#$%^&*()"}; //{"word", "with", "cpp", "probably", "not ", "HIU5#idea", "h5h"};
    // vector<string> decoded_words;
    // str = s1.encode(input_words);
    // decoded_words = s1.decode(str);
    string s_mix = "HellO mY deaSSAARR BiLlOoO";
    string::iterator fit = s_mix.begin();
    string::iterator rit = s_mix.end() - 1;

    if(fit < rit)
        cout << "fwd iterator behind reverse it" << endl;

    cout << "The original string is: " << s_mix;
    

    // cout << str.substr(0,5);
    return 0;
}