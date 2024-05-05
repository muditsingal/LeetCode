#include<iostream>
#include<numbers>
#include<ostream>
#include <stdexcept>
#include <string>


using namespace std;

class vehicle
{
  private:
    int wheels;
    string transmission_type;
    int top_speed;

  protected:
    int current_speed;
    
  public:
    vehicle()
    {
      wheels = 4;
      top_speed = 100;
    }
    void set_max_speed(int t_speed)
    {
      top_speed = t_speed;
    }
    void print_top_speed()
    {
      cout << "Top speed is: " << top_speed << "\n";
    }
    void print_speed()
    {
      cout << "Current speed is: " << current_speed << "\n";
    }

};

class truck : public vehicle
{
  public:
    int no_axels;
    int max_capacity;
  
  public:
    truck()
    {
      no_axels = 2;
      max_capacity = 10;
    }
    void set_speed(int speed)
    {
      current_speed = speed;
    }
};

int main()
{
  truck t1;
  truck* tp = new truck;
  tp->set_max_speed(60);
  tp->print_top_speed();

  return 0;
}