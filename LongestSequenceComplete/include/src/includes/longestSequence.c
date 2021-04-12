#include"longestSequence.h"

static int rows;
static int cols;
static int counter=0;
static int mCheck(char **matrix,  int currRow, int currCol){
    if(currRow<0 || currRow>rows-1 || currCol<0 || currCol>cols-1){
        return 1;
    }
    
    return 0;
}

static int colorCheck(char **matrix,char color,int currRow, int currCol){
    if(mCheck(matrix,currRow,currCol)){
        return 1;
    }

    if(matrix[currRow][currCol]!=color){
        return 1;
    }

    return 0;
}

static void printM(char **matrix){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

static int getDown(char **matrix, char color, int fnRow,int currCol){
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

static int getUp(char **matrix, char color, int fnRow,int currCol){
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

static int getRight(char **matrix, char color, int currRow,int fnCol){
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

static int getLeft(char **matrix, char color, int currRow,int fnCol){
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


int findLongestSequence(char **matrix,int iRows,int iCols){
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