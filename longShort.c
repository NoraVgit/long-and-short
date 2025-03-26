#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    if(argc < 4)
    {
        printf("Please enter missing command arguments: ./a.out (read file) (write file) (write file)\n");
        return 1;
    }
    FILE * input = fopen(argv[1],"r");
    FILE * shortWrite = fopen(argv[2],"w");
    FILE * longWrite = fopen(argv[3],"w");

    if(!input)
    {
        printf("could not open file for reading\n");
        return 1;
    }

    char line[40];//for holding each line of files

    while(fgets(line,40,input) != NULL)
    {
        if(strlen(line) < 20)
        {
            for(int i = 0; i < strlen(line); i++)
            {
                fprintf(shortWrite,"%c",toupper(line[i]));
            }
        }
        else
        {
            for(int j = 0; j < strlen(line); j++)
            {
                //printf("%c", tolower(line[j]));
                fprintf(longWrite,"%c",(line[j]));
            }
        }
        
    }
    return 0;
}