#include"global.h"

char *qwerty;
void login()
{
    char pass[11];
    char password[11]="1607053oct";
    int i;
    printf("\n\n\t\t      >>>>>>>>>>>>>>>>>>>>>>>>**********************<<<<<<<<<<<<<<<<<<<<<<<<\n\n\t\t\t\t      ENTER THE PASSWORD TO LOGIN : ");
    scanf("%s",pass);
    qwerty=(char*)malloc(strlen(pass));
    strcpy(qwerty,pass);
    printf("\n\n\t\t      >>>>>>>>>>>>>>>>>>>>>>>>**********************<<<<<<<<<<<<<<<<<<<<<<<<");
    if(strcmp(qwerty,password)==0)
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
        free(qwerty);
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

