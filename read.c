#include"global.h"
void read_from_file()
{
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

