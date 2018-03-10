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
    int itemNum;
    vector<int> itemX;
    vector<int> itemY;

    void resizeItem(int itemNum){
        itemX.reserve(itemNum);
        itemY.reserve(itemNum);
        return;
    }

};

#endif
