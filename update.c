#include"global.h"
void update(int x)
{
    int y;
    char temp[30];
    int k;
    q:

    printf("\n\t\t\t\t\t[1]Update Nominee Name\n\t\t\t\t\t[2]Update Present Address\n\t\t\t\t\t[3]Update Permanent Address\n\t\t\t\t\t[4]Change phone number\n\t\t\t\t\t[5]Exit\n\t\t\t\t\tYour Choice: ");
    scanf("%d",&y);
    getchar();
    if(y==1)
    {
        printf("\n\t\t\t\t\tEnter Nominee's First Name: ");
        gets(arr[x].nominee_name1);
        printf("\n\t\t\t\t\tEnter Nominee's Last Name: ");
        gets(arr[x].nominee_name2);
        goto q;
    }
    else if(y==2)
    {
        printf("\n\t\t\t\t\tEnter Present Address: ");
        gets(arr[x].prs_add);
        goto q;
    }
    else if(y==3)
    {
        printf("\n\t\t\t\t\tEnter Permanent Address: ");
        gets(arr[x].prm_add);
        goto q;
    }
    else if(y==4)
    {
        printf("\n\t\t\t\t\tEnter Phone Number: ");
        gets(arr[x].phn);
        goto q;
    }
    else if(y==5)
        {
            write_in_file();
            menu();
        }
}

