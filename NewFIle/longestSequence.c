#include"longestSequence.h"
int count=0;

static int getRecursiveRes(char **matrix,char color,int rows,int cols,int currRow,int currCol){
    if(currRow<0 || currRow>rows-1 || currCol<0 || currCol>cols-1 || matrix[currRow][currCol]!=color){
        return 0;
    }

    int res=1;
    matrix[currRow][currCol]=1;
    printf("\n%d\n",count);
    count++;
    res+=getRecursiveRes(matrix,color,rows,cols,currRow+1,currCol);
    res+=getRecursiveRes(matrix,color,rows,cols,currRow,currCol+1);
    res+=getRecursiveRes(matrix,color,rows,cols,currRow-1,currCol);
    res+=getRecursiveRes(matrix,color,rows,cols,currRow,currCol-1);

    return res;
}

int findLongestSequence(char **matrix,int rows,int cols){
    int max=0,curr=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
           
            if(matrix[i][j]==1){
                continue;
            }
            curr=0;
            curr=getRecursiveRes(matrix,matrix[i][j],rows,cols,i,j);
            if(curr>max){
                max=curr;
            }
        }
    }
    return max;
}

