#include "runFunc.h"

/* Reads the files, creates the matrices, calls the finding function, prints the result and frees the alocated memory */
void runLongestSequence(int argc,char *argv[]){
    for(int arg=1;arg<argc;arg++){
        FILE *inputFilePtr;
        int row, col;
        inputFilePtr = fopen(argv[arg], "r");
        if (inputFilePtr == NULL)
        {
            printf("Couldn't open %s\n",argv[arg]);
            perror("Error in opening file");
            
            continue;
        }
        fscanf(inputFilePtr, "%d ", &col);                     
        fscanf(inputFilePtr, "%d ", &row);        

        char **resultsArr = (char**)malloc(row * sizeof(char*));

        for (int i = 0; i < row; i++)
        {
            resultsArr[i] = (char *)malloc((col) * sizeof(char)); 
        }
        for(int i = 0; i < row; i++){
            for (int j = 0; j < col; j++)
            {
                fscanf(inputFilePtr, "%c ", &resultsArr[i][j]);
            }
        }
        int result=findLongestSequence(resultsArr,row,col);
        printf("\n%d\n\n",result);
        for (int i = 0; i < row; i++)
        {
            free(resultsArr[i]); 
        }
     
        free(resultsArr); 
        fclose(inputFilePtr);                         
        inputFilePtr = NULL; 
    }  
}
