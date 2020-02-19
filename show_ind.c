#include"global.h"
void show_ind(int x,int j)
{
    printf("\n\t\t[%d].",j);
    printf("\n\t\tName: %s",arr[x].name1);
    printf("\n\t\tName: %s",arr[x].name2);
    printf("\n\t\tNominee Name: %s",arr[x].nominee_name1);
    printf("\n\t\tNominee Name: %s",arr[x].nominee_name2);
    printf("\n\t\tNID: %s",arr[x].nid);
    printf("\n\t\tPhone Number: %s",arr[x].phn);
    printf("\n\t\tPresent address: %s",arr[x].prs_add);
    printf("\n\t\tAccount no: %d",arr[x].acc_no);
}

