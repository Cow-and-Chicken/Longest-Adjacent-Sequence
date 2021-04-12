#include"longestSequence.h"

/* Static variables for the matrix */
static int rows;
static int cols;

/* Checks if we are out of the matrix */
static int mCheck(const int currRow, const int currCol){
    if(currRow<0 || currRow>rows-1 || currCol<0 || currCol>cols-1){
        return 1;
    }
    
    return 0;
}

/* Checks if the color of the matrix is the same we are looking for */
static int colorCheck(char **matrix, const char color, const int currRow, const int currCol){
    if(mCheck(currRow,currCol)){
        return 1;
    }

    if(matrix[currRow][currCol]!=color){
        return 1;
    }

    return 0;
}

/* Prints the matrix - test purpose only */
static void printM(char **matrix){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

/* Returns number of connected colors of the same type under the calling cell of the matrix */
static int getDown(char **matrix, const char color, const int fnRow, const int currCol){
    if(colorCheck(matrix,color,fnRow,currCol)){
        return 0;
    }
    matrix[fnRow][currCol]=1;
    int currRow=fnRow;
    int rez=0;
    while(!colorCheck(matrix,color,currRow+1,currCol)){
        currRow++;
        matrix[currRow][currCol]=1;
    }
    while(currRow>=fnRow){
        rez+=getRight(matrix,color,currRow,currCol+1);
        rez+=getLeft(matrix,color,currRow,currCol-1);
        rez+=matrix[currRow][currCol];
        matrix[currRow][currCol]=0;
        currRow--;
    }
    return rez;
}

/* Returns number of connected colors of the same type above the calling cell of the matrix */
static int getUp(char **matrix, const char color, const int fnRow, const int currCol){
    if(colorCheck(matrix,color,fnRow,currCol)){
        return 0;
    }

    matrix[fnRow][currCol]=1;
    int currRow=fnRow;
    int rez=0;
    while(!colorCheck(matrix,color,currRow-1,currCol)){
        currRow--;
        matrix[currRow][currCol]=1;
    }
    while(currRow<=fnRow){
        rez+=getRight(matrix,color,currRow,currCol+1);
        rez+=getLeft(matrix,color,currRow,currCol-1);
        rez+=matrix[currRow][currCol];
        matrix[currRow][currCol]=0;
        currRow++;
    }
    return rez;
}

/* Returns number of connected colors of the same type to the right of the calling cell of the matrix */
static int getRight(char **matrix, const char color, const int currRow,const int fnCol){
    if(colorCheck(matrix,color,currRow,fnCol)){
        return 0;
    }
    
    matrix[currRow][fnCol]=1;
    int currCol=fnCol;
    int rez=0;
    while(!colorCheck(matrix,color,currRow,currCol+1)){
        currCol++;
        matrix[currRow][currCol]=1;
    }
    while(currCol>=fnCol){
        rez+=getDown(matrix,color,currRow+1,currCol);
        rez+=getUp(matrix,color,currRow-1,currCol);
        rez+=matrix[currRow][currCol];
        matrix[currRow][currCol]=0;
        currCol--;
    }
    return rez;

}

/* Returns number of connected colors of the same type to the left of the calling cell of the matrix */
static int getLeft(char **matrix, const char color, const int currRow, const int fnCol){
    if(colorCheck(matrix,color,currRow,fnCol)){
        return 0;
    }
        matrix[currRow][fnCol]=1;
    int currCol=fnCol;
    int rez=0;
    while(!colorCheck(matrix,color,currRow,currCol-1)){
        currCol--;
        matrix[currRow][currCol]=1;
    }
    while(currCol<=fnCol){
        rez+=getDown(matrix,color,currRow+1,currCol);
        rez+=getUp(matrix,color,currRow-1,currCol);
        rez+=matrix[currRow][currCol];
        matrix[currRow][currCol]=0;
        currCol++;
    }
    return rez;
}

/* Finds and returns the longest sequence of the same color in the mateix */
int findLongestSequence(char **matrix, const int iRows, const int iCols){
    int max=0,curr=0;
    rows=iRows;
    cols=iCols;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==0){
                continue;
            }
            curr=0;
            curr=getDown(matrix,matrix[i][j],i,j);
            if(curr>max){
                max=curr;
            }
            
        }
    }
    return max;
}