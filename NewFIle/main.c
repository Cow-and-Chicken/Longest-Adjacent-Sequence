#include <stdio.h>
#include"longestSequence.h"
int main(int argc,char *argv[]){
/* Creating pointer to the input file */
    FILE *inputFilePtr; 
    int row, col;
    /* Opening the file in read mode */
    inputFilePtr = fopen("test_4", "r"); 
    if (inputFilePtr == NULL)
    { /* Checking if the file is correctly opened */
        perror("Error in opening file");
        return (-1);
    }
    /* Using the input to initialize the columns of the matrix */
    fscanf(inputFilePtr, "%d ", &col);
    /* Using the input to initialize the rows of the matrix */                      
    fscanf(inputFilePtr, "%d ", &row);                      
    char **resultsArr = (char**)malloc(row * sizeof(char*));
     /* Dynamically  allocating memory for the matrix I need */
    for (int i = 0; i < row; i++)
    {
        /* Dynamically  allocating memory for the rows of the matrix I nedd */
        resultsArr[i] = (char *)malloc((col) * sizeof(char)); 
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            fscanf(inputFilePtr, "%c ", &resultsArr[i][j]);
        }
        printf("\n");
    }
   
    int result=findLongestSequence(resultsArr,row,col);
    printf("\n%d\n",result);

    /* Setting the pointer to the input file to NULL */
    for (int i = 0; i < row; i++)
    {
    /* Releasing the memory used for the rows in the matrix */
        free(resultsArr[i]); 
    }
     
    free(resultsArr);
    /* Closing the input file */ 
    fclose(inputFilePtr);
    /* Releasing the memory for the matrix */                         
    inputFilePtr = NULL;  
    return 0;
}
