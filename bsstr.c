#include<stdio.h>
#include<string.h>

typedef struct 
{
    int code;
    char name[20];
    char state[20];
}city;

int filest(city c[])
{
    FILE *fp;
    char str[30];
    int i=0;

    printf("\nEnter File Name: ");
    gets(str);

    fp=fopen(str,"r");
    if(fp==NULL)
        printf("%s not Found!",str);
    else
    {
        while(!feof(fp))
        {
            fscanf(fp,"%d %s %s",&c[i].code,c[i].name,c[i].state);
            i++;
        }
        fclose(fp);
    }

    return i;
}

void flcpy(city c[],int n)
{
    FILE *fp;
    char str[30];
    int i;

    printf("\nEnter File to Copy in: ");
    gets(str);
    fp=fopen(str,"w");
    for(i=0;i<n;i++)
       fprintf(fp,"%d\t%s\t%s\n",c[i].code,c[i].name,c[i].state);

    fclose(fp);
}

void printstruct(city c[],int n)
{
    int i;
    printf("\nCode\tName\tState\n");
    for(i=0;i<n;i++)
        printf("%d\t%s\t%s\n",c[i].code,c[i].name,c[i].state);
}

void bubble(city c[],int n)
{
    city t;
    int i,j,cnt=0,swap=0,flag=0;
    for(i=1;i<n;i++)
    {
        flag=0;
        for(j=0;j<n-i;j++)
        {
            if(strcmp(c[j].name,c[j+1].name)>0)
            {
                swap++;
                t=c[j];
                c[j]=c[j+1];
                c[j+1]=t;
                flag++;
            }
            cnt++;
        }
        if(flag==0)
            break;
    }

    printf("\nComparision: %d\nSwap: %d",cnt,swap);
}


int main()
{
    city c[100];
    int n;
    char sr[30];

    n=filest(c);
    printf("\nBefore Sort:\n");
    printstruct(c,n);

    printf("\nAfter Sort:\n");
    bubble(c,n);
    printstruct(c,n);

    flcpy(c,n);

    return 0;
}