#include<stdlib.h>
#include<stdio.h>


int findLongestSequence(char **matrix,int rows,int cols);
static int getRecursiveRow(char **matrix,char color, int rows,int cols, int fnRow, int currCol);
static int getRecursiveCol(char **matrix,char color, int rows,int cols, int currRow, int fnCol);



