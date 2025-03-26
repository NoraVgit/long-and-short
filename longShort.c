#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    if(argc < 3)
    {
        printf("Please enter missing command arguments (read file) (write file) (write file)\n");
        return 1;
    }
    FILE * input = fopen(argv[0],"r");
    if(!input)
    {
        printf("could not open file for reading\n");
        return 1;
    }
    return 0;
}