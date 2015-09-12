#include <stdio.h>
#include <string.h>
#include <conio.h>
 
int main()
{
    char Buffer[4095];
    char InputFileName[20];
    char *TemporaryFileName = "temp.txt";
    char Find[20];
    char Replace[20];
    int line = 0;
    FILE *Input,*Output;
    printf("Enter the File Name :");
    gets(InputFileName);
    Input = fopen(InputFileName, "r");
    Output = fopen(TemporaryFileName, "w");
 
    printf("Enter the word to find :");
    gets(Find);
    printf("Enter the New word to replace :");
    gets(Replace);
 
    if(NULL == Input)
        printf("\nCould not open file");
 
    printf("Find:    %s\n", Find);
    printf("Replace: %s\n", Replace);
 
    // For each line...
    while(NULL != fgets(Buffer, 4095, Input))
    {
        char *Stop = NULL;
        char *Start = Buffer;
 
        while(1)
        {
 
            /*getting the first location of the source string*/
            Stop = strstr(Start, Find);
            if(NULL == Stop)
            {a
                fwrite(Start, 1, strlen(Start), Output);
                break;
            }
            printf("\nfound at Line  %d",line);
            /*writting data till the source string location*/
            fwrite(Start, 1, Stop - Start, Output);
            /*writting Replacement string to the output file**/
            fwrite(Replace, 1, strlen(Replace), Output);
            /*moving the pointer to the next char of source string*/
            Start = Stop + strlen(Find);
        }
        line++;
    }
 
    fclose(Input);
    fclose(Output);
    /*Remove the old file*/
    remove(InputFileName);
    /*rename the temporary file*/
    rename(TemporaryFileName, InputFileName);
 
    return 0;
}
