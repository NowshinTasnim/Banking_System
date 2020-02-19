#include"global.h"
int find_int(int x)
{
    int pos=0,i=0;
    for(i=0; i<size; i++)
    {
        if(x==arr[i].acc_no)
        {
            pos=i;
            break;
        }
    }
    return pos;
}


