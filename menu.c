#include"global.h"
void menu(void)
{
    int option,choice,i,v;
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
        printf("\n\t\t Enter 1 to go back to main menu or any key to exit.");
        printf("\n\t\t Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
            goto m;
        else close();
    break;
    case 3 :
        clrscr();
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************\n\t\t   ************                BANKING SYSTEM                ************");
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************");
        printf("\n\t\t\t\t\tInput Your Account No.: ");
        scanf("%d",&accno);
        banking(find_int(accno));
        printf("\n\t\t Enter 1 to go back to main menu or any key to exit.");
        printf("\n\t\t Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
            goto m;
        else close();
    break;
    case 4 :
        clrscr();
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************\n\t\t   ************               CHECK YOUR ACCOUNT              ************");
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************");
        check();
        printf("\n\t\t Enter 1 to go back to main menu or any key to exit.");
        printf("\n\t\t Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
            goto m;
        else close();
        break;
    case 5 :
        clrscr();
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************\n\t\t   ************              DELETE YOUR ACCOUNT              ************");
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************");
        printf("\n\t\t\t\t\tInput Your Account No.: ");
        scanf("%d",&accno);
        int g;
        g=(find_int(accno));
        if(arr[g].loan==0)
        {
            del(find_int(accno));
            printf("\n\n\t\t\t\t\tYOUR ACCOUNT IS DELETED.");
        }

        else
        {
            printf("\n\t\tYou haven't paid your loan.So, you can't delete it now.\n\t\tDo you want to pay the loan?\n\t\t[1].Yes\n\t\t[2].No");
            scanf("%d",v);
            if(v==1)
            {
                arr[g].loan=0;
            }
            else goto m;

        }

        printf("\n\t\t Enter 1 to go back to main menu or any key to exit.");
        printf("\n\t\t Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
            goto m;
        else close();
        break;
    case 6 :
        clrscr();
        login();
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************\n\t\t   ************               VIEW YOUR ACCOUNT               ************");
        printf("\n\n\t\t   ***********************************************************************\n\n\t\t   ***********************************************************************");
        list_all();
        printf("\n\t\t Enter 1 to go back to main menu or any key to exit.");
        printf("\n\t\t Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
            goto m;
        else close();
        break;
    case 7 :
        close();
        break;

    }

}

