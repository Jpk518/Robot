#include "map.h"
#include <iostream>
#include <vector>
#include "items.h"
#include "map.h"

using namespace std;

items::items(map pool)
: poolData(pool)
{

itemNum = poolData.itemNum;

}
