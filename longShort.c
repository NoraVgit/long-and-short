#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getLength(char line[])//just a get length function
{
    int length = 0;
    while(line[length] != '\n' || line[length] != '\0')//while not the end of line character or new line
    {
        length++;
    }
    return length;
}
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
        //printf("%s",line);
        fprintf(shortWrite, "%s", line);
        
    }
    return 0;
}