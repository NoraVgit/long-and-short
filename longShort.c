#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//coded by Nora Van Leer
int main(int argc, char * argv[])
{
    if(argc < 4)//if the user didnt provide enougth arguments the user is informed and program is exited
    {
        printf("Please enter missing command arguments: ./a.out (read file) (write file) (write file)\n");
        return 1;
    }
    FILE * input = fopen(argv[1],"r");//opens file to read contents from
    FILE * shortWrite = fopen(argv[2],"w");//opens the second file for short lines
    FILE * longWrite = fopen(argv[3],"w");//opens the third file for long lines

    if(!input)//if there was an issue opening the file
    {
        printf("could not open file for reading\n");
        return 1;
    }

    char line[40];//for holding each line of files
    int shortLines = 0;
    int longLines = 0;
    while(fgets(line,39,input) != NULL)//gets a line of input from the input file
    {
        if(strlen(line) < 20)//if the strings length is less than 20 chars
        {
            for(int i = 0; i < strlen(line); i++)
            {
                fprintf(shortWrite,"%c",toupper(line[i]));//converts to uppcase and prints to the short file
                
            }
            shortLines++;//increase the number of shortlines 
        }
        else
        {
            for(int j = 0; j < strlen(line); j++)
            {
                fprintf(longWrite,"%c",tolower(line[j]));//else converts to lowercase and prints to the long file
                
            }
            longLines++;//increase the number of longlines
        }
        
    }
    printf("%d lines written to %s\n",shortLines,argv[2]);//displays number of short lines to user
    printf("%d lines written to %s\n",longLines,argv[3]);//displays the number of long lines to user
    //closes all files
    fclose(longWrite);
    fclose(shortWrite);
    fclose(input);
    return 0;
}