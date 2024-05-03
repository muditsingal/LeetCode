#include <bits/types/clock_t.h>
#include<iostream>
#include <numbers>
#include<vector>
#include<ostream>
#include<ctime>
#include<math.h>

using namespace std;
bool is_prime_linear(int num)
{
  if(num <= 1)
    return false;

  for(int i = 2; i <= num/2; i++)
    if(num%i == 0)
      return false;

  return true;
}

bool is_prime_sqrt(int num)
{
  if(num <= 1)
    return false;

  for(int i = 2; i <= int(std::sqrt(num)); i++)
    if(num%i == 0)
      return false;

  return true;
}

std::vector<int> find_primes(int n)
{
    std::vector<int> primes_list;
    for(int i = 2; i <= n; i++)
    {
      if(is_prime_sqrt(i))
        primes_list.push_back(i);
    }
    return primes_list;
}

std::vector<int> find_primes_vec(int n)
{
  std::vector<int> primes_list;
  bool is_prime = true;
  int i_sqrt;
  for(int i = 2; i <= n; i++)
  {
    is_prime = true;
    i_sqrt = std::sqrt(i);
    for(auto it = primes_list.begin(); it != primes_list.end(); it++)
    {
      if(i % (*it) == 0 || (*it) > i_sqrt)
      {
        is_prime = false;
        break;
      }
    }
    if(is_prime)
      primes_list.push_back(i);
  }
  return primes_list;
}

int main()
{
  std::clock_t start_time = std::clock();
  // std::vector<int> primes = find_primes(10000000);
  std::vector<int> primes = find_primes_vec(10000000);
  std::clock_t end_time = std::clock();

  std::cout<<"The list of primes is: " << "\n";
  // for(auto it = primes.begin(); it != primes.end(); it++)
  //   std::cout<< *it << " ";

  double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

  std::cout<< "\nTime taken by the program: " << elapsed_time << "\n";

  return 0;
}