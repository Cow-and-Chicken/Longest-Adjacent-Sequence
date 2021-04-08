#include <stdio.h>
#include"longestSequence.h"
int main(int argc,char *argv[])
{
    FILE *inputFilePtr; /* Creating pointer to the input file */
    int row, col;
    inputFilePtr = fopen("test_4", "r"); /* Opening the file in read mode */
    if (inputFilePtr == NULL)
    { /* Checking if the file is correctly opened */
        perror("Error in opening file");
        return (-1);
    }
    fscanf(inputFilePtr, "%d ", &col);                      /* Using the input to initialize the columns of the matrix */
    fscanf(inputFilePtr, "%d ", &row);                      /* Using the input to initialize the rows of the matrix */
    int **resultsArr = (char**)malloc(row * sizeof(char*));
     /* Dynamically  allocating memory for the matrix I need */
    for (int i = 0; i < row; i++)
    {
        resultsArr[i] = (char *)malloc((col) * sizeof(char)); /* Dynamically  allocating memory for the rows of the matrix I nedd */
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            fscanf(inputFilePtr, "%c ", &resultsArr[i][j]); /* Filling the matrix with the input */
        }
    }
   
    
    int result=findLongestSequence(resultsArr,row,col);
    printf("%d\n",result);
    printf("\nDone\n");
                           /* Setting the pointer to the input file to NULL */
    for (int i = 0; i < row; i++)
    {
        free(resultsArr[i]); /* Releasing the memory used for the rows in the matrix */
    }
     
    free(resultsArr); 
    fclose(inputFilePtr);                         /* Closing the input file */
    inputFilePtr = NULL;  /* Releasing the memory for the matrix */
    return 0;
}