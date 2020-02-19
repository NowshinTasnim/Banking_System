#include"global.h"
void check()
{
    int i,q,fu,j,choice,k,l;
    char x[100];
    no:
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
            if(strcmp(arr[i].name1,x)==0 || strmatch(&x,&arr[i].name1,strlen(x)) || strcmp(arr[i].name2,x)==0 || strmatch(x,arr[i].name2,strlen(x)))
                show_ind(i,j++);
            else
            {
                printf("\n\t\t\t\t\tNOT MATCHED!");
                goto no;
            }

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
            else
            {
                printf("\n\t\t\t\t\tNOT MATCHED!");
                goto no;
            }
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
            k=find_int(q);
            view_ind(k);

        }
        else
        {
            printf("\n\t\t\t\t\tAccount no. is not found.");
            printf("\n\t\t\t\t\tPress 1 to try again or any key to extit: ");
            scanf("%d",&main_exit);
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
            else
            {
                printf("\n\t\t\t\t\tNOT MATCHED!");
                goto no;
            }
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
            else
            {
                printf("\n\t\t\t\t\tNOT MATCHED!");
                goto no;
            }
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
            else
            {
                printf("\n\t\t\t\t\tNOT MATCHED!");
                goto no;
            }
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
            else
            {
                printf("\n\t\t\t\t\tNOT MATCHED!");
                goto no;
            }
        }
        printf("\n\t\tChoose one account no. from above: ");
        scanf("%d",&q);
        k=find_int(q);
        view_ind(k);
    }
    else
        menu();
}

