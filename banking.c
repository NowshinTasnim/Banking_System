#include"global.h"

void banking(int x)
{
    int y;
    q:
    printf("\n\t\t\t\t\t{1].Money Withdraw\n\t\t\t\t\t[2].Deposit\n\t\t\t\t\t[3].Account balance transfer\n\t\t\t\t\t[4]Exit\n\t\t\t\t\tEnter Your choice: ");
    scanf("%d",&y);
    if(y==1)
       {
            money_withdraw(x);
            goto q;
       }
    else if(y==2)
        {
            deposite(x);
            goto q;
        }
    else if(y==3)
    {
        getchar();
        balance_transfer(x);
        goto q;
    }
    else
        menu();
}

void money_withdraw(int x)
{
    float q;
    int w;
    printf("\n\t\t\t\t\tYour Current Balance: %f",arr[x].amnt);
    printf("\n\t\t\t\t\tYour Loan: %f",arr[x].loan);
    printf("\n\t\t\t\t\tEnter the amount of money You want to withdraw: ");
    scanf("%f",&q);
    if(arr[x].amnt-arr[x].loan<q)
    {
        printf("\n\t\tYour Account Balance is insufficient for this Transaction. what do you want to do?\n\t\t\t\t\t[1].Take A loan\n\t\t\t\t\t[2].exit\n\t\t\t\t\tEnter Your choice: ");
        scanf("%d",&w);
        if(w==1)
        {
            arr[x].loan=q-arr[x].amnt+arr[x].loan;
            arr[x].amnt=0;
            get_time(arr[x].withdraw[arr[x].wdsize]);
            arr[x].wdsize++;
        }
        else
            menu();
    }
    else
    {
        printf("\n\t\t\t\t\t[1].Continue\n\t\t\t\t\t[2].Exit");
        scanf("%d",&w);
        if(w==1)
        {
            arr[x].amnt=arr[x].amnt-q;
            get_time(arr[x].withdraw[arr[x].wdsize]);
            arr[x].wdsize++;
        }
        else
            menu();
    }
}

void deposite(int x)
{
    float q;
    int w;
    printf("\n\t\t\t\t\tYour Current Balance: %f",arr[x].amnt);
    loan_update(x);
    printf("\n\t\t\t\t\tYour Loan: %f",arr[x].loan);
    printf("\n\t\t\t\t\tEnter the amount of money You want to deposit : ");
    scanf("%f",&q);
    if(q+arr[x].amnt-arr[x].loan>0)
    {
        arr[x].amnt=(q+arr[x].amnt-arr[x].loan);
        arr[x].loan=0;
    }
    else
    {
        arr[x].loan-=q;
        arr[x].amnt=0;
    }

}

void balance_transfer(int x)
{
    int acno,fu,pos1,pos2;
    float bal;
    char strx[30];
    printf("\n\t\tGive another Account Holder Name:");
    scanf("%s",&strx);
    printf("\n\t\tGive %s 's Account No:",strx);
    scanf("%d",&acno);
    pos1=find_int(acno);
    if(strcmp(arr[pos1].name1,strx)==0 || strcmp(arr[pos1].name2,strx)==0)
        pos2=pos1;
    if(pos1 && pos2 && pos1==pos2)
    {
        printf("\n\t\tMatched!");
abr_de:
        printf("\n\t\tYour account balance: %f\n\t\tEnter Amount of money want to transfer: ",arr[x].amnt);
        scanf("%f",&bal);
        if(bal>arr[x].amnt)
        {
            printf("\n\t\tYou don't have sufficient money to give.\n\t\t[1].Try again\n\t\t[2]. Exit");
            scanf("%d",&fu);
            if(fu==1)
                goto abr_de;
            else
                menu();
        }
        else
        {
            printf("\n\t\t\t\t\tDo you really want to transfer %f Tk ?\n\t\t\t\t\t[1].Yes\n\t\t\t\t\t[2].Want to change the ammount\n\t\t\t\t\t[3].No",bal);
            scanf("%d",&fu);
            if(fu==1)
            {
                arr[x].amnt-=bal;
                loan_update(pos1);
                if(bal+arr[pos1].amnt-arr[pos1].loan>0)
                {
                    arr[pos1].amnt=(bal+arr[pos1].amnt-arr[pos1].loan);
                    arr[pos1].loan=0;
                }
                else
                {
                    arr[pos1].loan-=bal;
                    arr[pos1].amnt=0;
                }

            }
            else if(fu==2)
                goto abr_de;
            else
                menu();
        }
    }
}

