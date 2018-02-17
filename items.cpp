#include "items.h"
#include "map.h"
#include <iostream>

using namespace std;

items::items(map pool)
: poolData(pool)
{
itemNum = poolData.itemNum;

}
