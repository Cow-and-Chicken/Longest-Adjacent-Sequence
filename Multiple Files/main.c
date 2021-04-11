#include <stdio.h>
#include "longestSequence.h"

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("Error");
        return 1;
    }
    int counter;
    for (counter = 1; counter <= argc; counter++)
    {
        FILE *inputFilePtr;
        int row, col;
        inputFilePtr = fopen(argv[counter], "r");
        if (inputFilePtr == NULL)
        {
            perror("Error in opening file");
            exit(1);
        }
        fscanf(inputFilePtr, "%d ", &col);
        fscanf(inputFilePtr, "%d ", &row);
        char **resultsArr = (char **)malloc(row * sizeof(char *));

        for (int i = 0; i < row; i++)
        {
            resultsArr[i] = (char *)malloc((col) * sizeof(char));
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                fscanf(inputFilePtr, "%c ", &resultsArr[i][j]);
            }
        }
        int result = findLongestSequence(resultsArr, row, col);
        printf("%d. Result: %d\n", counter, result);

        for (int i = 0; i < row; i++)
        {
            free(resultsArr[i]);
        }

        free(resultsArr);
        fclose(inputFilePtr);
        inputFilePtr = NULL;
    }
    return 0;
}