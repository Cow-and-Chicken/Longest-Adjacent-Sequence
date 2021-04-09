#include"longestSequence.h"

static int mCheck(char **matrix, int rows,int cols, int currRow, int currCol){
    if(currRow<0 || currRow>rows-1 || currCol<0 || currCol>cols-1){
        return 1;
    }
    
    return 0;
}

static int colorCheck(char **matrix,char color, int rows,int cols, int currRow, int currCol){
    if(mCheck(matrix,rows,cols,currRow,currCol)){
        return 1;
    }
    if(matrix[currRow][currCol]==0){
        return 1;
    }
    if(matrix[currRow][currCol]!=color){
        return 1;
    }
    return 0;
}

static int oneZeroCheck(char **matrix, int rows,int cols, int currRow, int currCol){
    if(mCheck(matrix,rows,cols,currRow,currCol)){
        return 1;
    }
    if(matrix[currRow][currCol]>2){
        return 1;
    }
    return 0;
}

static void printM(char **matrix,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

static int surrCheck(char **matrix,char color, int rows,int cols, int currRow, int currCol){
    if(colorCheck(matrix,color,rows,cols,currRow+1,currCol)&&
        colorCheck(matrix,color,rows,cols,currRow-1,currCol)&&
        colorCheck(matrix,color,rows,cols,currRow,currCol+1)&&
        colorCheck(matrix,color,rows,cols,currRow,currCol-1)){
        return 1;
    }
    return 0;
}

static int getRecursiveRow(char **matrix, const char color, const int rows, const int cols, const int fnRow, const int currCol){
    if(surrCheck(matrix,color,rows,cols,fnRow,currCol)){
        matrix[fnRow][currCol]=1;
        return 0;
    }

    int rez=0;
    int c=1;
    int currRow=fnRow;
    while(1){
        matrix[currRow][currCol]=1;
        if(colorCheck(matrix,color,rows,cols,currRow+c,currCol)){
            break;
        }
        currRow+=c;
    }
    if(!colorCheck(matrix,color,rows,cols,fnRow-1,currCol)){
        c=-c;
        currRow=fnRow+c;
        while(1){
            matrix[currRow][currCol]=1;
            if(colorCheck(matrix,color,rows,cols,currRow+c,currCol)){
                break;
            }
            currRow+=c;
        }
    }
    printf("\n");
    printM(matrix,rows,cols);
    printf("\n");
    while(1){
        rez+=getRecursiveCol(matrix,color,rows,cols,currRow,currCol);
        rez+=matrix[currRow][currCol];
        matrix[currRow][currCol]=0;
        if(oneZeroCheck(matrix,rows,cols,currRow-c,currCol)){
            break;
        }
        currRow-=c;
    }
    printf("\n");
    printM(matrix,rows,cols);
    printf("\n");
    return rez;
}



static int getRecursiveCol(char **matrix, const char color, const int rows, const int cols, const int currRow, const int fnCol){
    if(surrCheck(matrix,color,rows,cols,currRow,fnCol)){
        matrix[currRow][fnCol]=1;
        return 0;
    }
    
    int rez=0;
    int c=1;
    int currCol=fnCol;
    while(1){
        matrix[currRow][currCol]=1;
        if(colorCheck(matrix,color,rows,cols,currRow,currCol+c)){
            break;
        }
        
        currCol+=c;
    }
    if(!colorCheck(matrix,color,rows,cols,currRow,fnCol-1)){
        c=-c;
        currCol=fnCol+c;
        while(1){
            matrix[currRow][currCol]=1;
            if(colorCheck(matrix,color,rows,cols,currRow,currCol+c)){
                break;
            }
            currCol+=c;
        }
    }
    while(1){
        
        rez+=getRecursiveRow(matrix,color,rows,cols,currRow,currCol);
        rez+=matrix[currRow][currCol];
        matrix[currRow][currCol]=0;
        if(oneZeroCheck(matrix,rows,cols,currRow,currCol-c)){
            break;
        }
        currCol-=c;
    }
    return rez;
}


int findLongestSequence(char **matrix,int rows,int cols){
    int max=0,curr=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==1 || matrix[i][j]==0){
                continue;
            }
            
            curr=0;
            curr=getRecursiveRow(matrix,matrix[i][j],rows,cols,i,j);
            printf("%d",curr);;
            printf("\n");
            if(curr>max){
                max=curr;
            }
            
        }
    }
    return max;
}