#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    if(argc < 4)
    {
        printf("Please enter missing command arguments: ./a.out (read file) (write file) (write file)\n");
        return 1;
    }
    FILE * input = fopen(argv[1],"r");
    if(!input)
    {
        printf("could not open file for reading\n");
        return 1;
    }

    char line[40];//for holding each line of files

    while(fgets(line,40,input) != NULL)
    {
        printf("%s",line);
    }
    return 0;
}