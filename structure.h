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
