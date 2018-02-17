#include <iostream>
using namespace std;

int main()
{
  int fish = 5;
  int dog = 2;
  int *point1 = &fish;
  int *point2 = &dog;
  cout << point1 << endl;
  cout << point2 << endl;
  return 0;
}
