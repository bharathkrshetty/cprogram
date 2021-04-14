#include<librarymanagement.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define IN 1
#define OUT 0

char info[500];

struct
{
  int bid;
  char bname[25] ;
  char author[25];
  int nooftitles;
  char titles[500];
  int status;
}book;
struct
{
  int mid;
  char mname[25] ;
  char department[25];
  int availibcard;
  int phno;

}membr;
FILE *librecord;
FILE *membrrecord;
FILE *fp1;
FILE *fp2;
FILE *temp1;
FILE *temp2;

void Addbook()
{
    int i;book.status=IN;
            //opening the librecord file
    librecord = fopen("librecord.txt","a+");
    printf("Enter The number of The Book :(Integer) \n");
        scanf("%d",&book.bid);
    printf("Enter The Name of The Book :\n");
        scanf("%s",book.bname);
    printf("Enter The Name of Author :\n");
        scanf("%s",book.author);
    printf("Enter The Number of Titles Of The Book:(Integer)\n");
        scanf("%d",&book.nooftitles);
    fprintf(librecord,"\n%d\t%s\t%s\t%d\t%d\t",book.bid,book.bname,book.author,book.status,book.nooftitles);
    printf("Enter The Titles Of The Book : \n");
    for(i=0;i<book.nooftitles;i++)
    {
        scanf("%s",book.titles);
        fprintf(librecord,"%s\t",book.titles);
    }
    fclose(librecord);
    printf(" (' ' ) A New Book has been Added Successfully...\n");

}

void Displaybook()
{
    librecord = fopen("librecord.txt","a+");
    printf("\nBookid\tName\tAuthor\tStatus\tNo.\tTitles\n",info);
    do
    {
        fgets(info,500,librecord);
        printf("%s\n",info);
    }while(!feof(librecord));
    fclose(librecord);
}
void Searchbook()
{
    int i;
    char Target[25],stats[3];
    int Found=0;
    if((librecord=fopen("librecord.txt","r"))==NULL)
        printf(" ! The File is Empty...\n\n");
    else
    {
        printf("\nEnter The Name Of Book : ");
            scanf("%s",Target);
        while(!feof(librecord)&& Found==0)
        {
        fscanf(librecord,"%d %s %s %d %d", &book.bid,book.bname,book.author,&book.status,&book.nooftitles);
            if(strcmp(Target,book.bname)==0)
                Found=1;
            for(i=0;i<book.nooftitles;i++)
                fscanf(librecord,"%s",book.titles);
        }
        if(Found)
        {
            if(book.status==IN)
                strcpy(stats,"IN");
            else
                strcpy(stats,"OUT");

            printf("\nThe Unique ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author is:  %s\nThe Book Status:%s\n\n",book.bid,book.bname,book.author,stats);
            }
        else if(!Found)
            printf("! There is no such Entry...\n");
        fclose(librecord);
    }

}

void Author()
{
    int i;
    char Target[500];
    int Found=0;
    if((librecord=fopen("librecord.txt","r"))==NULL)
    printf(" ! The file is empty... \n\n");
    else
    {
        printf("\nEnter The Name Of Author : ");
            scanf("%s",Target);
        printf("\nBooks:");
        while(!feof(librecord))
        {
            fscanf(librecord,"%d %s %s %d %d",&book.bid,book.bname,book.author,&book.status,&book.nooftitles);
            if(strcmp(Target,book.author)==0)
            {
                Found=1;
                printf("\n\t%s",book.bname);
            }
            for(i=0;i<book.nooftitles;i++)
                fscanf(librecord,"%s",book.titles);
        }
        if(!Found)
            printf(" ! There is no such Entry...\n");
        fclose(librecord);
    }

}
void Titlelist()
{
    int i;
    char Target[500];
    int Found=0;
    if((librecord=fopen("librecord.txt","r"))==NULL)
        printf(" ! The file is empty...\n\n");
    else
    {
        printf("\nEnter The Book Name :");
        scanf("%s",Target);
        while(!feof(librecord)&& Found==0)
        {
            fscanf(librecord,"%d %s %s %d %d",&book.bid,book.bname,book.author,&book.status,&book.nooftitles);
            if(strcmp(Target,book.bname)==0)
                {
                    Found=1;
                    break;
                }
            for(i=0;i<book.nooftitles;i++)
                fscanf(librecord,"%s",book.titles);
        }
        if(Found)
        {
            //printf("The Name of book is:               %s\n",book.bname);
            printf("\nThe Titles:\n");
            for(i=0;i<book.nooftitles;i++)
            {
                fscanf(librecord,"%s",book.titles);
                    printf("%d.%s......\n",i+1,book.titles);
            }
        }
        else if(!Found)
            printf(" ! There is no such Entry...\n");
        fclose(librecord);
    }

}