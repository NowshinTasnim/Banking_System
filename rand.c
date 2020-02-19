#include"global.h"
int random()
{
    int l=1e7;
    int h=999999;
    return l+rand() % (h-l);

}

