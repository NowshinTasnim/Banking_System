#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
struct date
{
    int month,day,year;
};

struct bank
{
    char name1[30];
    char name2[30];
    char nominee_name1[30];
    char nominee_name2[30];
    int acc_no,age;
    char nid[16];
    char prs_add[60];
    char prm_add[60];
    char ntnlt[15];
    char phn[20];
    float amnt;
    float loan;
    struct date dob;
    int depsize;
    int wdsize;
    struct date deposit[100];
    struct date withdraw[100];
};
struct bank arr[1000];
static int size=0;
struct date c_t;
struct bank xq;
int main_exit;

void write_in_file()
{
    FILE *inp;
    int i=0,j;
    inp=fopen("database.txt","w");
    for(i=0; i<size; i++)
    {
        fprintf(inp,"%s\n",arr[i].name1);
        fprintf(inp,"%s\n",arr[i].name2);
        fprintf(inp,"%s\n",arr[i].nominee_name1);
        fprintf(inp,"%s\n",arr[i].nominee_name2);
        fprintf(inp,"%d\n",arr[i].acc_no);
        fprintf(inp,"%d\n",arr[i].age);
        fprintf(inp,"%s\n",arr[i].prs_add);
        fprintf(inp,"%s\n",arr[i].prm_add);
        fprintf(inp,"%s\n",arr[i].ntnlt);
        fprintf(inp,"%s\n",arr[i].nid);
        fprintf(inp,"%s\n",arr[i].phn);
        fprintf(inp,"%f\n",arr[i].amnt);
        fprintf(inp,"%f\n",arr[i].loan);
        fprintf(inp,"%d/%d/%d\n",arr[i].dob.month,arr[i].dob.day,arr[i].dob.year);
        fprintf(inp,"%d\n",arr[i].depsize);
        for(j=0; j<arr[i].depsize; j++)
            fprintf(inp,"%d/%d/%d\n",arr[i].deposit[j].month,arr[i].deposit[j].day,arr[i].deposit[j].year);
        fprintf(inp,"%d\n",arr[i].wdsize);
        for(j=0; j<arr[i].wdsize; j++)
            fprintf(inp,"%d/%d/%d\n",arr[i].withdraw[j].month,arr[i].withdraw[j].day,arr[i].withdraw[j].year);
    }
    fclose(inp);
}

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

void login()
{
    char pass[11];
    char password[11]="1607053oct";
    int i;
    printf("\n\n\t\t      >>>>>>>>>>>>>>>>>>>>>>>>**********************<<<<<<<<<<<<<<<<<<<<<<<<\n\n\t\t\t\t      ENTER THE PASSWORD TO LOGIN : ");
    scanf("%s",pass);
    printf("\n\n\t\t      >>>>>>>>>>>>>>>>>>>>>>>>**********************<<<<<<<<<<<<<<<<<<<<<<<<");
    if(strcmp(pass,password)==0)
    {
        printf("\n\n\t\t      PASSWORD MATCHED\n\n\t\t      LOADING ");
        for(i=0; i<6; i++)
        {
            fordelay(100000000);
            printf(".");
        }
    }
    else
    {
        printf("\n\n\t\t\t\t WRONG PASSWORD!!!!\a\a\a");
        login_attempt:
        printf("\n\n\t\t\t\t ENTER 1 TO TRY AGAIN: ");
        scanf("%d",&main_exit);
        if(main_exit==1)
        {
            clrscr();
            login();
        }
        else if(main_exit==0)
        {
            clrscr();
            close();
        }
        else
        {
            printf("\n\n\t\t\t\t Invalid!!!!!");
            fordelay(100000000);
            clrscr();
            goto login_attempt;
        }
    }
}


void read_from_file()
{
    FILE *inp;
    inp=fopen("database.txt","r");
    int i=0;
    int j=0;
    while(fscanf(inp,"%s",&arr[i].name1)!=EOF)
    {
        fscanf(inp,"%s",&arr[i].name2);
        fscanf(inp,"%s",&arr[i].nominee_name1);
        fscanf(inp,"%s",&arr[i].nominee_name2);
        fscanf(inp,"%d",&arr[i].acc_no);
        fscanf(inp,"%d",&arr[i].age);
        fscanf(inp,"%s",&arr[i].prs_add);
        fscanf(inp,"%s",&arr[i].prm_add);
        fscanf(inp,"%s",&arr[i].ntnlt);
        fscanf(inp,"%s",&arr[i].nid);
        fscanf(inp,"%s",&arr[i].phn);
        fscanf(inp,"%f",&arr[i].amnt);
        fscanf(inp,"%f",&arr[i].loan);
        fscanf(inp,"%d/%d/%d",&arr[i].dob.month,&arr[i].dob.day,&arr[i].dob.year);
        fscanf(inp,"%d",&arr[i].depsize);
        for(j=0; j<arr[i].depsize; j++)
            fscanf(inp,"%d/%d/%d",&arr[i].deposit[j].month,&arr[i].deposit[j].day,&arr[i].deposit[j].year);
        fscanf(inp,"%d",&arr[i].wdsize);
        for(j=0; j<arr[i].wdsize; j++)
            fscanf(inp,"%d/%d/%d",&arr[i].withdraw[j].month,&arr[i].withdraw[j].day,&arr[i].withdraw[j].year);
        i++;
    }
    size=i;
    fclose(inp);
}

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

void check()
{
    int i,q,fu,j,choice,k,l;
    char x[100];
    printf("\n\t\t\tWhich information you want to give for searching your account?\n\t\t\t[1]Name\n\t\t\t[2]Nominee Name\n\t\t\t[3]Account No\n\t\t\t[4]NID\n\t\t\t[5]Present_Address\n\t\t\t[6]Nationality\n\t\t\t[7]Phone\n\t\t\t[8]Exit\n\t\t\tEnter your choice: ");
    scanf("%d",&fu);
    getchar();
    if(fu==1)
    {
        printf("\n\t\tGive your name or a part of name: ");
        scanf("%s",x);
        j=1;
        for(i=0; i<size; i++)
        {
            if(strcmp(arr[i].name1,x)==0 || strmatch(x,arr[i].name1,strlen(x)) || strcmp(arr[i].name2,x)==0 || strmatch(x,arr[i].name2,strlen(x)))
                show_ind(i,j++);
        }
        printf("\n\t\tChoose one account no. from above: ");
        scanf("%d",&q);
        k=find_int(q);
        view_ind(k);


    }
    else if(fu==2)
    {
        printf("\n\t\tGive your nominee's full name or a part of name:");
        scanf("%s",x);
        j=1;
        for(i=0; i<size; i++)
        {
            if(strcmp(arr[i].nominee_name1,x)==0 || strmatch(x,arr[i].nominee_name1,strlen(x))||strcmp(arr[i].nominee_name2,x)==0 || strmatch(x,arr[i].nominee_name2,strlen(x)))
                show_ind(i,j++);
        }
        printf("\n\t\tChoose one account no. from above: ");
        scanf("%d",&q);
        k=find_int(q);
        view_ind(k);

    }
    else if(fu==3)
    {
        h:
        printf("\n\t\tGive your Account No.:");
        scanf("%d",&q);
        if(find_int(q))
        {
            //printf("\n\t\t%d found @ %d position",q,find_int(q)+1);
            k=find_int(q);
            view_ind(k);

        }
        else
        {
            printf("\n\t\t\t\t\tAccount no. is not found.");
            printf("\n\t\t\t\t\tPress 1 to try again or any key to extit: ");
            scanf("%d",main_exit);
            if(main_exit==1)
                goto h;
            else menu();
        }

    }
    else if(fu==4)
    {
        printf("\n\t\t Give Your NID No.: ");
        gets(x);
        j=1;
        for(i=0; i<size; i++)
        {
            if(strcmp(arr[i].nid,x)==0 || strmatch(x,arr[i].prs_add,strlen(x)))
                show_ind(i,j++);
        }
        printf("\n\t\tChoose one account no. from above: ");
        scanf("%d",&q);
        k=find_int(q);
        view_ind(k);
    }
    else if(fu==5)
    {
        printf("\n\t\tGive your Present Address or a part of Present address:");
        scanf("%s",x);
        j=1;
        for(i=0; i<size; i++)
        {
            if(strcmp(arr[i].prs_add,x)==0 || strmatch(x,arr[i].prs_add,strlen(x)))
                show_ind(i,j++);
        }
        printf("\n\t\tChoose one account no. from above: ");
        scanf("%d",&q);
        k=find_int(q);
        view_ind(k);
    }
    else if(fu==6)
    {
        printf("\n\t\tGive your Nationality:");
        scanf("%s",x);
        j=1;
        for(i=0; i<size; i++)
        {
            if(strcmp(arr[i].ntnlt,x)==0|| strmatch(x,arr[i].ntnlt,strlen(x)))
                show_ind(i,j++);
        }
        printf("\n\t\tChoose one account no. from above: ");
        scanf("%d",&q);
        k=find_int(q);
        view_ind(k);
    }
    else if(fu==7)
    {
        printf("\n\t\tPhone number or a part of Phone number:");
        scanf("%s",x);
        j=1;
        for(i=0; i<size; i++)
        {
            if(strcmp(arr[i].phn,x)==0 || strmatch(x,arr[i].phn,strlen(x)))
                show_ind(i,j++);
        }
        printf("\n\t\tChoose one account no. from above: ");
        scanf("%d",&q);
        k=find_int(q);
        view_ind(k);
    }
    else
        menu();
}

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

void menu(void)
{
    int option,choice,i;
    m:
    clrscr();
    printf("\n\n\t\t      ***********************************************************************\n\n\t\t      ***********************************************************************\n\n\t\t      **********       WELCOME TO BANKING MANAGEMENT SYSTEM        **********\n\n\t\t      **********            CUSTOMER ACCOUNT HANDELING             **********");
    printf("\n\n\t\t      ***********************************************************************\n\n\t\t      ***********************************************************************");
    printf("\n\n\t\t      **********                                                   **********");
    printf("\n\n\t\t      **********                   MAIN MENU                       **********");
    printf("\n\n\t\t      **********                                                   **********");
    printf("\n\n\t\t\t\t\t[1]. CREATE A NEW ACCOUNT\n\n\t\t\t\t\t[2]. UPDATE INFORMATION OF EXISTING ACCOUNT\n\n\t\t\t\t\t[3]. BANKING\n\n\t\t\t\t\t[4]. CHECK THE DETAILS OF EXISTING ACCOUNT\n\n\t\t\t\t\t[5]. DELET EXISTING FILE\n\n\t\t\t\t\t[6]. VIEW CUSTOMER'S LIST\n\n\t\t\t\t\t[7]. EXIT\n\n");
    printf("\n\n\t\t      ENTER THE NUMBER OF YOUR CHOICE: ");
    scanf("%d",&option);
    printf("\n\n\t\t\t\t\t      LOADING ");
        for(i=0; i<6; i++)
        {
            fordelay(100000000);
            printf(".");
        }
    getchar();
    int accno;

    switch(option)
    {
    case 1 :
        new_acc();
        v:
        printf("\n\t\t Enter 1 to go back to main menu or any key to exit.");
        printf("\n\t\t Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
            goto m;
        else close();
    break;
    case 2 :
        clrscr();
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************\n\t\t   ************              UPDATE YOUR ACCOUNT              ************");
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************");
        printf("\n\t\t\t\t\tInput Your Account No.: ");
        scanf("%d",&accno);
        update(find_int(accno));
        goto v;
    break;
    case 3 :
        clrscr();
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************\n\t\t   ************                BANKING SYSTEM                ************");
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************");
        printf("\n\t\t\t\t\tInput Your Account No.: ");
        scanf("%d",&accno);
        banking(find_int(accno));
        goto v;
    break;
    case 4 :
        clrscr();
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************\n\t\t   ************               CHECK YOUR ACCOUNT              ************");
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************");
        check();
        goto v;
        break;
    case 5 :
        clrscr();
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************\n\t\t   ************              DELETE YOUR ACCOUNT              ************");
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************");
        printf("\n\t\t\t\t\tInput Your Account No.: ");
        scanf("%d",&accno);
        del(find_int(accno));
        goto v;
        break;
    case 6 :
        clrscr();
        login();
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************\n\t\t   ************               VIEW YOUR ACCOUNT               ************");
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************");
        list_all();
        goto v;
        break;
    case 7 :
        close();
        break;

    }

}


int main()
{
    read_from_file();
    system("COLOR 9F");
    menu();
}
