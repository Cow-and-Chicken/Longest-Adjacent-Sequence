#include<stdlib.h>
#include<stdio.h>


int findLongestSequence(char **matrix,int rows,int cols);
static int getDown(char **matrix, char color, int fnRow,int currCol);
static int getUp(char **matrix, char color, int fnRow,int currCol);
static int getRight(char **matrix, char color, int fnRow,int currCol);
static int getLeft(char **matrix, char color, int fnRow,int currCol);


