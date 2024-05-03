#include <bits/types/clock_t.h>
#include<iostream>
#include<numbers>
#include<vector>
#include<ostream>
#include<ctime>
#include<math.h>

using namespace std;

int factorial_loop(int num)
{
  int fact = 1;
  for(int i = num; i >=1; i--)
  {
    fact *= i;
  }
  return fact;
}

int factorial_recurr(int num)
{
  if(num <= 1)
    return 1;
  return num*factorial_recurr(num-1);
}

int main()
{
  int n = 5;
  cout << "The factorial by loop is: " << factorial_loop(n) << "\n";
  cout << "The factorial by recurrsion is: " << factorial_recurr(n);
  return 0;
}