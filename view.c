#include"global.h"
void list_all()
{
    int i=0,j;
    for(i=0; i<size; i++)
    {
        printf("\n\t\tFirst Name: %s\n",arr[i].name1);
        printf("\n\t\tLast Name: %s\n",arr[i].name2);
        printf("\n\t\tNominee's First Name :%s\n",arr[i].nominee_name1);
        printf("\n\t\tNominee's Last Name :%s\n",arr[i].nominee_name2);
        printf("\n\t\tAccount No: %d\n",arr[i].acc_no);
        printf("\n\t\tAge: %d\n",arr[i].age);
        printf("\n\t\tPresent Address: %s\n",arr[i].prs_add);
        printf("\n\t\tPermanent Address: %s\n",arr[i].prm_add);
        printf("\n\t\tNationality: %s\n",arr[i].ntnlt);
        printf("\n\t\tPhone number: %s\n",arr[i].phn);
        printf("\n\t\tBalance: %f\n",arr[i].amnt);
        printf("\n\t\tLoan: %f\n",arr[i].loan);
        printf("\n\t\tDate of birth: %d/%d/%d\n",arr[i].dob.month,arr[i].dob.day,arr[i].dob.year);
        printf("\n\t\tTotal Deposit Happened: %d\n",arr[i].depsize);
        printf("\n\t\tMonth--Day--Year\n");
        for(j=0; j<arr[i].depsize; j++)
            printf("\n\t\t%d/%d/%d\n",arr[i].deposit[j].month,arr[i].deposit[j].day,arr[i].deposit[j].year);
        printf("\n\t\tTotal Withdrawn Happened: %d\n",arr[i].wdsize);
        if(arr[i].wdsize)
        {
            printf("\n\t\tMonth--Day--Year\n");
        }
        for(j=0; j<arr[i].wdsize; j++)
            printf("\n\t\t%d/%d/%d\n",arr[i].withdraw[j].month,arr[i].withdraw[j].day,arr[i].withdraw[j].year);
    }
}

