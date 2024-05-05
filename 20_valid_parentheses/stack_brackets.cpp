#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

bool is_valid_parentheses(string s)
{
  unordered_map<char, char> brackets {{'{','}'},{'[',']'},{'(',')'}};
  stack<char> stk;
  for(auto it : s)
  {
    if(brackets.find(it) != brackets.end())
    {
      stk.push(it);
      continue;
    }
    else if(stk.empty())
      return false;
    if(brackets[stk.top()] != it)
      return false;

    stk.pop();
  }
  if(stk.empty())
    return true;

  return false;
}

int main()
{
  string input_str = "{()}()";

  if(is_valid_parentheses(input_str))
    cout << "The input string: " << input_str << " is valid!" << endl;

  else
    cout << "The input string: " << input_str << " is not valid." << endl;
  // for(auto it = input_str.begin(); it != input_str.end(); ++it)
  
  return 0;
}