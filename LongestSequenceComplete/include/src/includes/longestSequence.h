#include<stdlib.h>
#include<stdio.h>


int findLongestSequence(char **matrix, const int rows,const int cols);
static int getDown(char **matrix, const char color, const int fnRow, const int currCol);
static int getUp(char **matrix, const char color, const int fnRow, const int currCol);
static int getRight(char **matrix, const char color, const int fnRow, const int currCol);
static int getLeft(char **matrix, const char color, const int fnRow, const int currCol);


