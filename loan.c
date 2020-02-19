#include"global.h"
void loan_update(int x)
{
    get_time(c_t);
    struct date l_wd=arr[x].withdraw[arr[x].wdsize-1];
    int q=0,w=0,e=0;
    float pr=10.0;
    if(c_t.day-l_wd.day>=0)
        q=c_t.day-l_wd.day;
    if(c_t.month-l_wd.month>=0)
        w=c_t.month-l_wd.month;
    if(c_t.year-l_wd.year>=0)
        e=c_t.year-l_wd.year;
    pr=(float)q/365+(float)w/12+(float)e;
    arr[x].loan+=arr[x].loan*pr/100;
}

