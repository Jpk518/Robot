#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "map.h"
#include "machine.h"
#include "items.h"
#include "inventory.h"
#include "map.cpp"
#include "machine.cpp"
#include "items.cpp"
#include "inventory.cpp"

using namespace std;

bool running = true;


void Setup(map &pool, inventory &inv, items &item){
  running = true;
  cout << "This simulation xwill run with no starting items on ROV." << endl;
  while(true)
  {
    cout << "Enter # of items in course (1-10): ";
    cin >> item.itemNum;
    if (pool.itemNum > 10 || pool.itemNum < 0 || !cin)
    {
      cin.clear();
      cin.ignore();
      cout << "Enter a # between 1 and 10";
      Sleep(1500);
      system("CLS");
    }
    else
    {
      item.resizeItem(item.itemNum);
      cout << item.itemX.size() << endl;

      for(int i = 0; i < pool.itemNum; i++)
      {
        srand(time(0));
        item.itemX[i] = rand() % pool.width;
        item.itemY[i] = rand() % pool.height;
        inv.invNum = 0;
      }
    return;
    }
  }
}

void Draw(map &pool, machine &robot, items &item){
  system("CLS"); // system clear
  for (int i = 0; i < pool.width; i++) //top border
  cout << " # " ;
  cout << endl;

  for (int j = 0; j < pool.height; j++)
  {
    for (int i = 0; i < pool.width; i++)
    {
      bool testCondition = false;
      for (int x = 0; i < pool.itemNum; x++) {
       if (i == item.itemX[x] && j == item.itemY[x])
       testCondition = true;
     }
      if (i == 0)
          cout << " # ";
      else if (i == pool.width - 1)
          cout << " # ";
      else if (i == robot.x && j == robot.y)
          cout << " O ";
      else if (testCondition == true)
          cout << " X ";
      else
          cout << "   ";

    }
    cout << endl;
  }

  for (int i = 0; i < pool.width; i++) //bottom border
    cout << " # ";
  cout << endl << endl;
  cout << "Position: X = " << robot.x << ", Y = " << robot.y+1 << endl;
  cout << "Inventory: " <<  endl;
  //cout << "Number or Inventory Items: " << invNum << endl;

}

void Input(map &pool, machine &robot){
  switch(_getch())
  {
    case 'w':
      robot.dir = robot.UP;
      break;
    case 'a':
      robot.dir = robot.LEFT;
      break;
    case 's':
      robot.dir = robot.DOWN;
      break;
    case 'd':
      robot.dir = robot.RIGHT;
      break;
    case 'z':

      break;
    case 'x':

      break;

    default:
      break;
  }
}

void Logic(map &pool, machine &robot){

  switch(robot.dir)
  {
    case robot.LEFT:
      if(robot.x > 1)
        robot.x --;
      break;
    case robot.RIGHT:
      if(robot.x < pool.width - 2)
        robot.x ++;
      break;
    case robot.UP:
      if(robot.y > 0)
        robot.y --;
      break;
    case robot.DOWN:
      if (robot.y < pool.height - 1)
        robot.y ++;
      break;
    default:
      break;
  }
}

int main(){
  map pool;
  machine robot;
  inventory inv;
  items item(pool);

  Setup(pool, inv, item);

  while (running)
  {
    Draw(pool, robot, item);
    Input(pool, robot);
    Logic(pool, robot);
  }
  return 0;
}
