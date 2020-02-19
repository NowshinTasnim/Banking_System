#include"global.h"
void view_ind(int k)
{
        int l;
        printf("\n\t\tName: %s %s\n",arr[k].name1,arr[k].name2);
        printf("\n\t\tNominee Name: %s %s\n",arr[k].nominee_name1,arr[k].nominee_name2);
        printf("\n\t\tAccount No: %d\n",arr[k].acc_no);
        printf("\n\t\tAge: %d\n",arr[k].age);
        printf("\n\t\tPresent Address: %s\n",arr[k].prs_add);
        printf("\n\t\tPermanent Address: %s\n",arr[k].prm_add);
        printf("\n\t\tNationality: %s\n",arr[k].ntnlt);
        printf("\n\t\tPhone number: %s\n",arr[k].phn);
        printf("\n\t\tBalance: %f\n",arr[k].amnt);
        printf("\n\t\tLoan: %f\n",arr[k].loan);
        printf("\n\t\tDate of birth: %d/%d/%d\n",arr[k].dob.month,arr[k].dob.day,arr[k].dob.year);
        printf("\n\t\tTotal Deposit Happened: %d\n",arr[k].depsize);
        printf("\n\t\tMonth--Day--Year\n");
        for(l=0; l<arr[k].depsize;l++)
            printf("\n\t\t%d/%d/%d\n",arr[k].deposit[l].month,arr[k].deposit[l].day,arr[k].deposit[l].year);
        printf("\n\t\tTotal Withdrawn Happened: %d\n",arr[k].wdsize);
        if(arr[k].wdsize)
        {
            printf("\n\t\tMonth--Day--Year\n");
        }
        for(l=0;l<arr[k].wdsize; l++)
            printf("\n\t\t%d/%d/%d\n",arr[k].withdraw[l].month,arr[k].withdraw[l].day,arr[k].withdraw[l].year);
}

