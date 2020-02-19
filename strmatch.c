#include"global.h"
int strmatch(char *x,char *y,int end)
{
    int i=0;
    for(i=0; i<end; i++)
    {
        if(x[i]!=y[i])
            return 0;
    }
    return 1;
}

