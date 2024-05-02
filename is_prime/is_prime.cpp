#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
#include <ctime>
using namespace std;

// input: integer >=0
// output: find the factorial of ^ integer
bool is_prime_linear(int num)
{
  if (num <= 1)
    return false;
  for(int i = 2; i <= int(num/2); i++)
    if(num % i == 0)
      return false;

  return true;
}

bool is_prime_sqrt(int num)
{
  if (num <= 1)
    return false;
  int sq_n = int(sqrt(num));

  for(int i = 2; i <= sq_n; i++)
  {
    if(num % i == 0)
      return false;
  }
  return true;
}

// To execute C++, please define "int main()"
int main() {
  int n = 111781;
  // int n = 131;
  std::clock_t start = std::clock();
  cout<<CLOCKS_PER_SEC<<endl;
  if(is_prime_sqrt(n))
    cout << "The number " << n << " is prime" << "\n";
  else
    cout << "The number " << n << " is not prime" << "\n";  
  std::clock_t end = std::clock();
  double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

  cout<< "Time taken to check if a number is prime: " << elapsed_time << " seconds" << "\n";
  return 0;
}
