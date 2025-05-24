#include<stdio.h>
#include<string.h>
#include "header.h"
void main(int argc,char *argv[])
{
    FILE *fp;
  
    if(argc==3 && strcmp(argv[1],"-v")==0 )
    {
        fp=fopen(argv[2],"rb");
    
        if(fp==NULL)
        {
            printf("file not present\n");
            return;
        } 

        view_tag(fp);
        fclose(fp); 
    }
    else if(argc==5 && strcmp(argv[1],"-e")==0 )
    {
       edit_tag(argv[2],argv[3],argv[4]);
    }
    else if(argc==2)
    {
        printf("---------------HELP MENU----------------\n");
        printf("1. -v -> to view mp3 file contents\n");
        printf("2. -e -> to edit mp3 file contents\n");
        printf("2.1. -t -> to edit song title\n");  
        printf("2.1. -a -> to edit artist name\n");
        printf("2.1. -A -> to edit album name\n");
        printf("2.1. -y -> to edit year\n");
        printf("2.1. -g -> to edit content\n");
        printf("2.1. -c -> to edit comment\n");
        printf("----------------------------------------\n");
    }
    else
    {
     printf("------------------------------------------\n");
     printf("Error: ./a.out : INVALID ARGUMENTS\n");
     printf("USAGE : ");
     printf("To view please pass like: ./a.out -v sample.mp3\n");
     printf("To edit please pass like: ./a.out -e sample.mp3 -y 2025\n");
     printf("To get help pass like: ./a.out --help\n");
     printf("------------------------------------------\n");
    }
}

