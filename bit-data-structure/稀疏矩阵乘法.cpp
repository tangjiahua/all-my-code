#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
    int x;
    int y;
    int data;
}NODE;

typedef struct Q{
    int x;
    int y;
    int data;
    struct Q *next;
}NODE2;

int main(){
    int row1, col1, n1, n2, x, y , data;
    int row2, col2;
    int count = 0;
    scanf("%d %d %d",&row1,&col1,&n1);
    NODE matrix1[n1+1];
    for(int i = 1; i <= n1; i++){
        scanf("%d %d %d",&x,&y,&data);
        matrix1[i].x = x;
        matrix1[i].y = y;
        matrix1[i].data = data;
    }
    scanf("%d%d%d",&row2,&col2,&n2);
    NODE matrix2[n2+1];
    for(int i = 1; i <= n2; i++){
        scanf("%d %d %d",&x,&y,&data);
        matrix2[i].x = x;
        matrix2[i].y = y;
        matrix2[i].data = data;
    }
    NODE2* head, *p, *tail;
    head = (NODE2*)malloc(sizeof(NODE2));
    head->next = NULL;
    tail = head;

    int ctemp[col2+1];
    for(int arrow = 1; arrow <= row1; arrow++){
        for(int i = 1; i <= col2; i++)
            ctemp[i] = 0;
        for(int i = 1; i <= n1; i++){
            if(arrow == matrix1[i].x){
                for(int j = 1; j <= n2; j++){
                    if(matrix1[i].y == matrix2[j].x){
                        ctemp[matrix2[j].y] += matrix1[i].data * matrix2[j].data;
                    }
                }
            }
        }
        for(int i = 1; i <= col2; i++){
            if(ctemp[i] != 0){
                p = (NODE2*)malloc(sizeof(NODE2));
                p->x = arrow;
                p->y = i;
                p->data = ctemp[i];
                tail->next = p;
                p->next = NULL;
                tail = p;
                count++;
            }
        }
    }
    printf("%d\n%d\n%d\n",row1,col2,count);
    p = head->next;
    while(count--){
        printf("%d,%d,%d\n",p->x,p->y,p->data);
        p = p->next;
    }
    return 0;
}