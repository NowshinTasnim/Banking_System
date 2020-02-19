#include"global.h"
void new_acc()
{
    clrscr();
    printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************\n\t\t   ************              CREATE YOUR ACCOUNT              ************");
    printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************");
    printf("\n\t\t      [1].Your First Name:");
    scanf("%s",arr[size].name1);
    printf("\n\t\t      [1].Your Last Name:");
    scanf("%s",arr[size].name2);
    printf("\n\t\t      [2].Nominee's First Name:");
    scanf("%s",arr[size].nominee_name1);
    printf("\n\t\t      [2].Nominee's Last Name:");
    scanf("%s",arr[size].nominee_name2);
    printf("\n\t\t      [3]Present address: ");
    scanf("%s",arr[size].prs_add);
    printf("\n\t\t      [4]Permanent address: ");
    scanf("%s",arr[size].prm_add);
    arr[size].acc_no=random();
    printf("\n\t\t      [5]Nationality: ");
    scanf("%s",&arr[size].ntnlt);
    printf("\n\t\t      [6]NID: ");
    scanf("%s",&arr[size].nid);
    printf("\n\t\t      [7]Phone Number: ");
    scanf("%s",&arr[size].phn);
    printf("\n\t\t      [8]Amount of money to  deposit: ");
    scanf("%f",&arr[size].amnt);
    arr[size].loan=0.0;
    printf("\n\t\t      [9]Date of Birth(mm/dd/yyyy): ");
    scanf("%d/%d/%d",&arr[size].dob.month,&arr[size].dob.day,&arr[size].dob.year);
    get_time(arr[size].deposit[0]);
    arr[size].age=arr[size].deposit[0].year-arr[size].dob.year+1;
    arr[size].withdraw[0].month=-1,arr[size].withdraw[0].day=-1,arr[size].withdraw[0].year=-1;
    arr[size].depsize=1;
    arr[size].wdsize=0;
    size++;
    write_in_file();
    printf("\n\n\t\t      Account has been created successfully!");
    getchar();
}

