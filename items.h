#ifndef Items_H
#define Items_H
#include <vector>
#include "map.h"
using namespace std;

class items
{
  public:
    items(map pool);
    map poolData;
    vector<int> itemX;
    vector<int> itemY;
    int itemNum;
};

#endif
