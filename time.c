#include"global.h"
void get_time(struct date x)
{
    char dest_d[10];
    char dest_m[10];
    char dest_y[10];
    time_t now=time(NULL);
    time(&now);
    struct tm *t=localtime(&now);
    int dd,mm,yy;
    strftime(dest_d,10,"%d",t);
    strftime(dest_m,10,"%m",t);
    strftime(dest_y,10,"%Y",t);
    x.day=atoi(dest_d);
    x.year=atoi(dest_y);
    x.month=atoi(dest_m);
    return x;
}

