#include"global.h"
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

