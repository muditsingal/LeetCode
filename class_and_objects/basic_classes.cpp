#include<iostream>
#include<numbers>
#include<ostream>
#include <stdexcept>


// Write inheritance code

using namespace std;

struct player_st {
  int x;
  int y;
};

class player {
  private:
    int x;
    int y;
  public:
    player(int xi, int yi)
    {
      x = xi;
      y = yi;
    }
    player()
    {
      x = 0;
      y = 0;
    }
    void move(int dx, int dy)
    {
      x += dx;
      y += dy;
    }
    void print_pos()
    {
      cout << "X: " << x << " Y: " << y << "\n";
    }
};

class Log
{
  public:
    enum Level
    {
      log_level_error = 0, log_level_warning, log_level_info
    };
  private:
    Level log_level;
  public:
    Log()
    {
      log_level = log_level_info;
    }
    Log(Level level)
    {
      log_level = level;
    }
    ~Log()
    {
      cout << "Destroyed the logger object!" << "\n";
    }
    void set_log_level(Level level)
    {
      log_level = level;
    }
    void error(const char* msg)
    {
      cout << "[ERROR]: " << msg << "\n";
    }
    void warn(const char* msg)
    {
      if(log_level >= log_level_warning)
        cout << "[WARNING]: " << msg << "\n";
    }
    void info(const char* msg)
    {
      if(log_level >= log_level_info)
        cout << "[INFO]: " << msg << "\n";
    }

};

int main()
{
  player_st ps1;
  player p1(50,41);
  Log logger;
  ps1.x = 10;
  ps1.y = 2;
  p1.move(2, 2);
  cout<<"Structure player's position is: X=" << ps1.x << " Y=" << ps1.y << "\n";
  p1.print_pos();

  logger.set_log_level(Log::log_level_error);
  logger.warn("This is a warning");
  logger.error("This is an error");
  logger.info("This is an info msg");

  return 0;
}