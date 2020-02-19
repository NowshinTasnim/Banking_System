#include"global.h"
void del(int x)
{
    int i=x;
    for(i=x; i<size; i++)
        arr[x]=arr[x+1];
    size--;
    write_in_file();
}

