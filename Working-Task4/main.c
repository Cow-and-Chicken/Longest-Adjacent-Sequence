#include <stdio.h>
#include "longestSequence.h"

void readFile();

int main(int argc, char *argv[])
{
    readFile();
    return 0;
}

void readFile()
{
    FILE *inputFilePtr;
    int row, col;
    inputFilePtr = fopen("test_4", "r");
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
    printf("%d\n", result);

    for (int i = 0; i < row; i++)
    {
        free(resultsArr[i]);
    }

    free(resultsArr);
    fclose(inputFilePtr);
    inputFilePtr = NULL;
}