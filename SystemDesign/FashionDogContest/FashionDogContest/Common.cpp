#include "Common.h"
#include <cstdlib>


int Common::getRandom(int min, int max)
{
    return min + (rand() % (max - min));
}
