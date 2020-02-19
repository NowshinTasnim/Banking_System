#include <stdio.h>
#include <ctype.h>
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
struct date c_t;
struct bank xq;

int main_exit;
int size=0;
FILE *inp;

void check();
void clrscr();
void banking(int x);
void new_acc();
void close();
void find_int(int x);
void del(int x);
void login();
void fordelay();
void random();
void loan_update(int x);
void menu();
void read_from_file();
void write_in_file();
void show_ind(int x,int j);
void view_ind(int x);
void update(int x);
void get_time(struct date x);
void list_all();
int strmatch(char *x,char *y,int end);

