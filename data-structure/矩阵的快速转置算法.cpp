#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
    int x;
    int y;
    int data;
}NODE;

int main(){
    int row, col, n, x, y , data;
    
    scanf("%d %d %d",&row,&col,&n);
    NODE matrix[n+1];
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d",&x,&y,&data);
        matrix[i].x = x;
        matrix[i].y = y;
        matrix[i].data = data;
    }
    NODE tmatrix[n+1];

    int num[col+1];
    for(int i = 1; i <= col; i++)
        num[i] = 0;
    for(int i = 1; i <= n; i++){
        num[matrix[i].y]++;
    }

    int cpot[col+1];
    cpot[1] = 1;
    for(int i = 2; i <= col; i++){
        cpot[i] = cpot[i-1]+num[i-1];
    }
    printf("num:");
    for(int i = 1; i <= col; i++)
        printf("%d,",num[i]);
    printf("\n");
    printf("cpot:");
    for(int i = 1; i <= col; i++)
        printf("%d,",cpot[i]);
    printf("\n");
    int count = 1, flag;
    for(int i = 1; i <= n; i++){
        flag = matrix[i].y;
        tmatrix[cpot[flag]].x = matrix[i].y;
        tmatrix[cpot[flag]].y = matrix[i].x;
        tmatrix[cpot[flag]].data = matrix[i].data;
        cpot[flag]++;
    }
    
    for(int i = 1; i <= n; i++){
        printf("%d,%d,%d\n",tmatrix[i].x,tmatrix[i].y,tmatrix[i].data);
    }
}
