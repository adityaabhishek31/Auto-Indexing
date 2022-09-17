#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include"headerfile.h"
int main()
{ 
    struct tree *root = NULL;
    FILE* fp;
    int k,n;
    root = insert(root, "INDEX","LINE"); 
    printf("Enter the number of terms to be put in index page- ");
    scanf("%d",&k);
    if(k>0 && k<1000)
    {
       for(int j=0;j<k;j++)
        {
            printf("Enter the word to put in index- ");
            char word[20];
            char input[1000];
            scanf("%s",word);
            char ch1=',';
            int line_count=1;
            char line[50]={0};
            fp=fopen("file.txt","r");
            while(fgets(input,sizeof(input),fp)!=NULL)
            {
                char *ptr=strstr(input,word);
                if(ptr!=NULL)
                {
                     sprintf(line+strlen(line),"%d",line_count);
                     strncat(line,&ch1, 1);
                } 
                line_count++;
            }
            int len=strlen(line);
            line[len-1]='\0';
            if(len>0)
            {
                insert(root,word,line);
            }
            else
            {
                printf("Entered word is not present in the document\n");
                j--;
            }
        }
    }
    else
    {
        printf("INVALID ENTRY\n");
        exit(1);
    }
   do
    {
    printf("Enter 1 to print index \n");
    printf("Enter 2 to search for an index\n");
    printf("Enter 3 to exit\n");
    scanf("%d",&n);
    switch (n)
    {
        case 1:
            {
                printf("\n");
                display(root);
                printf("\n");
                break;
            }
        case 2:
            {
                char searchfor[30];
                printf("Enter the index you want to search for\n");
                scanf("%s",searchfor);
                search(root,searchfor);
                break;
            }
        case 3:
            {
                exit(1);
            }
        default:
        {
            printf("INVALID ENTRY");
            exit(1);
        }
    }
    }while(n>=0 && n<3);
    return 0; 
}